#include "YB_ListView.h"
#include "YB_Window.h"


class YB_Window;

void				YBConsoleViews::YB_ListView::Init()
{
	//1. Instantiate List Head
	auto* item = this->itemFactoryPtr->CreateViewItem(ListHead);
	this->subItemsList.push_back(item);
	this->listHeadPtr = dynamic_cast<YB_ListHead*>(item);

	//Todo: move the listItem instantiation to BindList() so avoid empty list items
	//2. make copies of List Row Template and attach instances to subItemList.
	for (int i = 0; i < ListRowCount; ++i)
	{
		string tempString = this->ListRowTemplate;
		//Create a auto-generated Id tag
		tempString += string("Id:") + to_string(this->Id * 100 + i) + string("!");
		//Create a auto-generated Bind tag 
		//This scheme is designed for future expansion to implement the paging function
		tempString += string("Bind:") + to_string(i) + string("!");
		ListItem* listItemPtr = dynamic_cast<ListItem*>(this->itemFactoryPtr->CreateViewItem(tempString));
		//Move downward vertical position
		listItemPtr->y += i;
		listItemPtr->parent = this;

		if (i == 0) listItemPtr->isFocused = true;

		this->subItemsList.push_back(listItemPtr);
	}
	//3. invoke base function, this will bind source with the generated items.
	YB_ViewBasis::Init();
}

void				YBConsoleViews::YB_ListView::Bind()
{
	//Bind non-listItems (in base)
	YB_ViewBasis::Bind();
	//Bind the listItems
	this->BindList();
}

void				YBConsoleViews::YB_ListView::BindList() {
	if (!this->listHeadPtr)
		return;

	//scan children viewItems and update the 'Content' variable
	for (auto& item : this->bindableItems)
	{
		if (item->ItemType != "ListItem")	continue;

		auto viewitemPtr = dynamic_cast<YB_ListItem*>(item);
		LIST_ITEM_VALUES* formatedValueCarrier = new LIST_ITEM_VALUES();
		for (auto tup : *listHeadPtr->tableRowFormatter)
		{
			LIST_ITEM_VALUE* newPair = new LIST_ITEM_VALUE(tup->first, "");
			formatedValueCarrier->push_back(newPair);
		}
		try {
			//1. Retrieve the row index from 'Bind' field
			int rowIndex = std::stoi(viewitemPtr->Bind);
			FORMATED_LIST_VIEW_VALUES* row = new FORMATED_LIST_VIEW_VALUES();
			//2. query the source one by one. formatedValueCarrier get the formated value as vector.
			bool result = this->dataSource->Get_QueryByIndex(rowIndex, *formatedValueCarrier);
			//3. generate the tuples for listItem content rendering
			int i = 0;
			for (auto valuePair : *formatedValueCarrier)
			{
				int width = (*listHeadPtr->tableRowFormatter)[i]->second;
				FORMATED_LIST_ITEM_VALUE* tuple;

				if (result)
				{
					tuple = new FORMATED_LIST_ITEM_VALUE(valuePair->first, valuePair->second, width);
				}
				else
				{
					tuple = new FORMATED_LIST_ITEM_VALUE(valuePair->first, "", width);
				}
				row->push_back(tuple);
				i++;
				//save the Id of the binded data source
				if (valuePair->first == "Id") viewitemPtr->dataId = std::stoi(valuePair->second);
			}
			viewitemPtr->OnBind(row);
		}
		catch (exception e) {
			YB_BindingError error;
			error(const_cast<char*>("error in binding values to children items."));
			throw error;
		}
	}
}

void				YBConsoleViews::YB_ListView::OnKey(int* keycode)
{
	YB_ViewBasis::OnKey(keycode);
}

void				YBConsoleViews::YB_ListView::OnChildReturn(YB_ViewMessageBasis* msgPtr, YB_ViewItemBasis* fromItemPtr)
{
	//query the selected viewItem to logic data object (car/user/rent) to forward to next view
	//you need take the data (principalData) by overriding the onViewForwarded(YB_DataBasis*) function.
	this->dataSource->Get_PrincipalData(dynamic_cast<YB_ListItem*>(fromItemPtr)->dataId);

	//Base will raise action of window.Goto() 
	YB_ViewBasis::OnChildReturn(msgPtr, fromItemPtr);
}

void				YBConsoleViews::YB_ListView::OnConfirmReturn(YB_ViewMessageBasis* msgPtr, YB_ViewBasis* fromViewPtr)
{
}

vector<char*>		YBConsoleViews::YB_ListView::Render()
{
	return YB_ViewBasis::Render();
}
