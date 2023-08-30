#pragma once
#include "YB_ViewBasis.h"
#include "YB_ViewItemBasis.h"  // Include the full definition here
#include "YB_ViewMessage.h"


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

	string*				YB_ViewBasis::Serialize()
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
			<< "Title:"				<< Title			<< YB_DataBasis::persistentSeparator
			<< "ViewType:"			<< ViewType			<< YB_DataBasis::persistentSeparator
			<< "w:"					<< w				<< YB_DataBasis::persistentSeparator
			<< "h:"					<< h				<< YB_DataBasis::persistentSeparator
			<< "DataSourceName:"	<< DataSourceName	<< YB_DataBasis::persistentSeparator;
	}
	void				YB_ViewBasis::Deserialize(string line)
	{
		this->Deserialize(line, &persistentSeparator);
	}
	void				YB_ViewBasis::Deserialize(string line, const char* separator)
	{
		YB_DataBasis::Deserialize(line, separator);

		Title =			*YB_DataBasis::FindValue("Title");
		ViewType =		*YB_DataBasis::FindValue("ViewType");
		w =				std::stoi(*YB_DataBasis::FindValue("w"));
		h =				std::stoi(*YB_DataBasis::FindValue("h"));
		DataSourceName = *YB_DataBasis::FindValue("DataSourceName");
	}

	/// <summary>
	/// Scan all viewItems, and merge the grid to viewArray
	/// </summary>
	/// <returns></returns>
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
		if (*keycode == 9)						//tabKeyCode = 9; Toggle items.
		{
			if (subItemsList.empty())
				return;
			if (currentItemIndex < 0)
				currentItemIndex = 0;
			if (subItemsList.size() == 1) {
				(*subItemsList[currentItemIndex]).isFocused = true;
				return;
			}
			(*subItemsList[currentItemIndex]).isFocused = false;
			currentItemIndex++;
			if (currentItemIndex > subItemsList.size() - 1)
				currentItemIndex = 0;
			(*subItemsList[currentItemIndex]).isFocused = true;
		}
		if (*keycode == 10)						//Return key;
		{
			(*subItemsList[currentItemIndex]).OnReturn();
		}
		if (*keycode == 8)						//Backspace key; Previous view.
		{
			(*subItemsList[currentItemIndex]).OnBackspace();
		}
		if ((*keycode >= 65 && *keycode <= 90) || (*keycode >= 48 && *keycode <= 57) || (*keycode >= 97 && *keycode <= 122))		//Alphabet(Upper/Lower) and numbers
		{
			(*subItemsList[currentItemIndex]).OnKey(keycode);
		}
	}
	void				YB_ViewBasis::OnChildReturn(YB_ViewMessageBasis msg)
	{
	}
}