#pragma once
#include "YB_ViewBasis.h"
#include "YB_ViewItemBasis.h"  // Include the full definition here
#include "YB_ViewMessage.h"
#include "YB_Errors.h"
#include <string>
#include "YB_Window.h"


class YB_Window;

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

		serializedString = new std::string(ss.str());
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
			<< "ConfirmView:" << ConfirmView << YB_DataBasis::persistentSeparator
			<< "GotoView:" << GotoView << YB_DataBasis::persistentSeparator;
	}
	void				YB_ViewBasis::Deserialize(string line)
	{
		this->Deserialize(line, &persistentSeparator);
	}
	void				YB_ViewBasis::Deserialize(string line, const char* separator)
	{
		YB_DataBasis::Deserialize(line, separator);

		if (YB_DataBasis::FindValue("Title"))			Title = *YB_DataBasis::FindValue("Title");
		if (YB_DataBasis::FindValue("ViewType"))		ViewType = *YB_DataBasis::FindValue("ViewType");
		if (YB_DataBasis::FindValue("w"))				w = std::stoi(*YB_DataBasis::FindValue("w"));
		if (YB_DataBasis::FindValue("h"))				h = std::stoi(*YB_DataBasis::FindValue("h"));
		if (YB_DataBasis::FindValue("Source"))			Source = *YB_DataBasis::FindValue("Source");
		if (YB_DataBasis::FindValue("ConfirmView"))		ConfirmView = *YB_DataBasis::FindValue("ConfirmView");
		if (YB_DataBasis::FindValue("GotoView"))		GotoView = *YB_DataBasis::FindValue("GotoView");
	}

	/// <summary>
	/// Scan all viewItems, pre-loop activities
	/// </summary>
	/// <returns></returns>
	void				YB_ViewBasis::Init() {
		//1. first let carry-forwarded datasource initiate
		if (fromViewPtr && this->dataSource && fromViewPtr->dataSource)
			//comes from a view with datasource
			this->dataSource->onViewForwarded(fromViewPtr->dataSource->Get_PrincipalData());
		else if (fromViewPtr && this->dataSource && !fromViewPtr->dataSource)
			//comes from a view without dataSource
			this->dataSource->onViewForwarded(nullptr);

		//2. Bind all items with tag "Bind"
		for (auto& item : this->subItemsList)
		{
			//cache the non-static items (which means you can toggle with Tab key)
			if (item->ItemType == "ButtonItem" || item->ItemType == "InputItem" || item->ItemType == "ListItem" || item->ItemType == "MenuItem")
				focusableItems.push_back(item);
			//cache the items which having data binding behaviour
			if (!item->Bind.empty())
				bindableItems.push_back(item);
			//The basis will try to Bind items from data properties;
			//Nothing would happen if unsuccessful in binding.
			//Override the Init in children, if necessary.
		}
		if (focusableItems.size() > 1 && currentItemIndex < 1)
			currentItemIndex = 1;

		this->isInitedFlag = true;
	}

	void				YB_ViewBasis::Bind() {
		if (dataSource && !bindableItems.empty())
			for (auto& item : this->bindableItems) {
				{
					try {
						item->OnBind(this->dataSource->Get_PropertyValue(&item->Bind));
						//item->Content = *this->Bind(&item->Bind);//This syntax has risk of returning nullptr and not handled by try/catch.
					}
					catch (exception e)
					{
						continue;
						//throw YB_BindingError();		//don't break the binding process
					}
				}
			}
		this->isBindedFlag = true;
	}

	void				YB_ViewBasis::BindList() {}

	void				YB_ViewBasis::ReverseBind() {
		//scan children viewItems and update the 'Content' variable
		for (auto& item : this->subItemsList)
		{
			try {
				this->dataSource->Set_PropertyValue(&item->Bind, &item->Content);
			}
			catch (exception e) {
				YB_ReverseBindingError error;
				error(const_cast<char*>(("error in reverse binding values to item:" + item->Bind).c_str()));
				throw error;
			}
		}

	}

	void				YB_ViewBasis::SetPrompt(YB_ViewItemBasis* promptPtr)
	{
		this->promptBoxItemPtr = promptPtr;
	}

	void				YB_ViewBasis::PopPrompt(const char* promptPtr, const char* gotoLink)
	{
		promptBoxItemPtr->Content = string(promptPtr);
		promptBoxItemPtr->isHidden = false;
		promptBoxItemPtr->Link = (gotoLink == nullptr) ? "" : gotoLink;
		this->currentItemIndex = 0;
	}

	//submit is a action-response function not always in loop of YB_View.
	void				YB_ViewBasis::Submit()
	{
		map<string, string> reverseBindMap;
		//find out the viewItems which has 'Bind' tag.
		for (auto& iterator : this->bindableItems)
		{
			if (iterator->ItemType == VIEWITEM_TYPE_BUTTON && !iterator->isFocused)	continue;		//only bind the active button ()
			if (!iterator->Bind.empty())
				reverseBindMap.insert(std::make_pair(iterator->Bind, iterator->Content));
		}
		if (!reverseBindMap.empty())
			//notify the VM for submission action
			this->dataSource->onSubmit(&reverseBindMap);

	}

	vector<char*>		YB_ViewBasis::Render()
	{
		if (viewArray.empty())
			Init_Background(this->Background);



		//Render and merge all viewItems
		for (auto& iterator : this->subItemsList)
		{
			if (iterator->isHidden)continue;

			auto posX = iterator->x, posY = iterator->y;

			//1. Render viewItem
			auto SUB_RECT = iterator->Render();
			if (SUB_RECT.empty())
				continue;

			//2. Merge
			size_t newContentLength = iterator->w;
			for (const auto& row : SUB_RECT)
			{
				std::memcpy(viewArray[posY] + posX, row, newContentLength);
				posY++;
			}
		}
		//3. Re-Render the prompt item as it's likely at bottom
		if (!subItemsList[0]->isHidden)
		{
			auto posX = subItemsList[0]->x, posY = subItemsList[0]->y;
			auto SUB_RECT = subItemsList[0]->Render();
			size_t newContentLength = subItemsList[0]->w;
			for (const auto& row : SUB_RECT)
			{
				std::memcpy(viewArray[posY] + posX, row, newContentLength);
				posY++;
			}
		}

		////Unit testing code - to visualize a single item
		//	for (const char* strPtr : viewArray) {
		//		std::cout << strPtr << std::endl;
		//	}
		////Unit testing code - to visualize a single item

		return viewArray;
	}

	void				YB_ViewBasis::Exit()
	{
		isInitedFlag = false;
		isBindedFlag = false;
		isUpdatedFlag = false;
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
		if (*keycode == 9)											//Tab; Toggle items.
		{
			if (focusableItems.size() <= 1) {						//only 1 item
				//(*focusableItems[currentItemIndex]).OnFocus();
				return;
			}
			(*focusableItems[currentItemIndex]).OnLostFocus();
			currentItemIndex++;
			if (currentItemIndex >= focusableItems.size())
				currentItemIndex = 1;
			(*focusableItems[currentItemIndex]).OnFocus();
		}
		if (*keycode == 13)											//Return key;
		{
			(*focusableItems[currentItemIndex]).OnReturn();
		}
		if (*keycode == 8)											//Backspace key; Previous view.
		{
			(*focusableItems[currentItemIndex]).OnBackspace();
		}
		if (*keycode >= 328 && *keycode <= 336) {					//Lft/Up/Rht/Dw arrow : Intercpted by derived, shall not arrive here
		}
		if ((*keycode >= 65 && *keycode <= 90)						//Alphabet(Upper/Lower) and numbers
			|| (*keycode >= 48 && *keycode <= 57)
			|| (*keycode >= 97 && *keycode <= 122))
		{
			(*focusableItems[currentItemIndex]).OnKey(keycode);		//Pass to active item
		}
	}

	void				YB_ViewBasis::OnChildReturn(YB_ViewMessageBasis* msgPtr, YB_ViewItemBasis* fromItemPtr)
	{
		if (msgPtr->Message == Button_Type_Ok)
		{
			this->promptBoxItemPtr->isHidden = true;
			this->promptBoxItemPtr->isFocused = false;
			this->Clear_Background();
		}

		if (fromItemPtr && !fromItemPtr->Link.empty())
		{
			try
			{
				windowPtr->Goto(fromItemPtr->Link);
			}
			catch (exception e)
			{
				windowPtr->Goto(ERROR_VIEW);
			}
		}
	}

	void				YB_ViewBasis::OnConfirmReturn(YB_ViewMessageBasis* msgPtr, YB_ViewBasis* fromViewPtr)
	{
		//Nothing here, you implement in derived if necessary.
	}
}