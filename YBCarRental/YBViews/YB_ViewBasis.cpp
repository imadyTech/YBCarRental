#pragma once
#include "YB_ViewBasis.h"
#include "YB_ViewItemBasis.h"  // Include the full definition here
#include "YB_ViewMessage.h"
#include "YB_Errors.h"

namespace YBConsoleViews {
	YB_ViewBasis::YB_ViewBasis()
	{
		YB_DataBasis::persistentSeparator = ';';
		w = 200, h = 20;
	}

	YB_ViewBasis::YB_ViewBasis(int* width, int* height) :YB_ViewBasis::YB_ViewBasis()
	{
		this->w = *width;
		this->h = *height;
	}

	YB_ViewBasis::~YB_ViewBasis()
	{
		//for (char* ptr : viewArray) {
		//	delete[] ptr;
		//}
		//this->viewArray.clear();

		//delete[] & viewArray;
	};


	//void YB_ViewBasis::AddViewItem(YB_ViewItemBasis item)
	//{
	//	int currentSize = YB_ViewBasis::viewItems.size();
	//	YB_ViewBasis::viewItems.insert(std::make_pair(currentSize + 1, item));
	//}
	//void YB_ViewBasis::AddViewItems(vector<YB_ViewItemBasis> items)
	//{
	//}

	string* YB_ViewBasis::Serialize()
	{
		std::stringstream ss;
		//Redirect to new function (instead of previous version overrided function)
		this->Serialize(ss);

		std::string* serializedString = new std::string(ss.str());
		return serializedString;
	}
	void				YB_ViewBasis::Serialize(std::stringstream& strStream)
	{
		YB_DataBasis::Serialize(strStream);
		strStream
			<< "Title:" << Title << YB_DataBasis::persistentSeparator
			<< "ViewType:" << ViewType << YB_DataBasis::persistentSeparator
			<< "w:" << w << YB_DataBasis::persistentSeparator
			<< "h:" << h << YB_DataBasis::persistentSeparator
			<< "Source:" << Source << YB_DataBasis::persistentSeparator
			<< "GotoView:" << GotoView << YB_DataBasis::persistentSeparator;
	}
	void				YB_ViewBasis::Deserialize(string line)
	{
		this->Deserialize(line, &persistentSeparator);
	}
	void				YB_ViewBasis::Deserialize(string line, const char* separator)
	{
		YB_DataBasis::Deserialize(line, separator);

		if (YB_DataBasis::FindValue("Title"))		Title = *YB_DataBasis::FindValue("Title");
		if (YB_DataBasis::FindValue("ViewType"))	ViewType = *YB_DataBasis::FindValue("ViewType");
		if (YB_DataBasis::FindValue("w"))			w = std::stoi(*YB_DataBasis::FindValue("w"));
		if (YB_DataBasis::FindValue("h"))			h = std::stoi(*YB_DataBasis::FindValue("h"));
		if (YB_DataBasis::FindValue("Source"))		Source = *YB_DataBasis::FindValue("Source");
		if (YB_DataBasis::FindValue("GotoView"))	GotoView = *YB_DataBasis::FindValue("GotoView");
	}

	/// <summary>
	/// Scan all viewItems, and merge the grid to viewArray
	/// </summary>
	/// <returns></returns>
	void				YB_ViewBasis::Init() {
		for (auto& item : this->subItemsList)
		{
			if (item->ItemType == "ButtonItem" || item->ItemType == "InputItem" || item->ItemType == "ListItem")
				focusableItems.push_back(item);
		}
	}

	string*				YB_ViewBasis::Bind(string* bindName) {
		return this->dataSource->Get_PropertyValue(bindName);
	}

	void				YB_ViewBasis::BindValues() {
		//scan children viewItems and update the 'Content' variable
		for (auto& item : this->subItemsList)
		{
			try {
				item->Content = *this->Bind(&item->Bind);
			}
			catch (exception e) {
				YB_BindingError error;
				error(const_cast<char*>("error in binding values to children items."));
				throw error;
			}
		}
	}

	void				YB_ViewBasis::ReverseBind() {

	}

	vector<char*>		YB_ViewBasis::Render()
	{
		if (viewArray.empty())
			Init_Background(this->Background);

		for (auto& iterator : this->subItemsList)
		{
			auto posX = iterator->x, posY = iterator->y;
			auto SUB_RECT = iterator->Render();
			if (SUB_RECT.empty())
				continue;

			size_t newContentLength = iterator->w;
			for (const auto& row : SUB_RECT)
			{
				std::memcpy(viewArray[posY] + posX, row, newContentLength);
			}
		}
		////Unit testing code - to visualize a single item
		//	for (const char* strPtr : viewArray) {
		//		std::cout << strPtr << std::endl;
		//	}
		////Unit testing code - to visualize a single item

		return viewArray;
	}

	void				YB_ViewBasis::Init_Background(char background)
	{
		if (!viewArray.empty())
			viewArray.clear();
		//fill the view background with a char
		for (int i = 0; i < this->h; ++i) {
			char* newLine = new char[this->w + 1];
			std::memset(newLine, background, this->w);
			newLine[this->w] = '\0'; // Null-terminate the string
			this->viewArray.push_back(newLine);
		}
	}

	void				YB_ViewBasis::Fill_Background(char background)
	{
		//fill the view background with a char
		for (int i = 0; i < this->h; ++i) {
			std::memset(this->viewArray[i], background, this->w);
		}
	}

	void				YB_ViewBasis::Clear_Background()
	{
		//fill the view background with a char
		for (int i = 0; i < this->h; ++i) {
			std::memset(this->viewArray[i], ' ', this->w);
		}
	}

	void				YB_ViewBasis::OnKey(int* keycode)
	{
		if (subItemsList.empty())
			return;
		if (focusableItems.empty())									//No item to be operated
			return;
		if (currentItemIndex < 0)
			currentItemIndex = 0;
		if (*keycode == 9)										//Tab; Toggle items.
		{
			if (focusableItems.size() == 1) {
				(*focusableItems[currentItemIndex]).isFocused = true;
				return;
			}
			(*focusableItems[currentItemIndex]).isFocused = false;
			currentItemIndex++;
			if (currentItemIndex >= focusableItems.size())
				currentItemIndex = 0;
			(*focusableItems[currentItemIndex]).isFocused = true;
		}
		if (*keycode == 10)										//Return key;
		{
			(*focusableItems[currentItemIndex]).OnReturn();
		}
		if (*keycode == 8)										//Backspace key; Previous view.
		{
			(*focusableItems[currentItemIndex]).OnBackspace();
		}
		if (*keycode >= 37 && *keycode <= 40) {					//Lft/Up/Rht/Dw arrow : Intercpted by derived
		}
		if ((*keycode >= 65 && *keycode <= 90)					//Alphabet(Upper/Lower) and numbers
			|| (*keycode >= 48 && *keycode <= 57)
			|| (*keycode >= 96 && *keycode <= 105))
		{
			(*focusableItems[currentItemIndex]).OnKey(keycode);		//Pass to active item
		}
	}

	void				YB_ViewBasis::OnChildReturn(YB_ViewMessageBasis msg)
	{
	}
}