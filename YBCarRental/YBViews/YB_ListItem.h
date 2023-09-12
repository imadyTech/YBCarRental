#pragma once
#include "YB_Global_Header.h"
#include "YB_ViewItemBasis.h"
#include <vector>

namespace YBConsoleViews
{
	class YB_ListItem : public YB_ViewItemBasis
	{
	public:
		YB_ListItem() :YB_ViewItemBasis(w, h) {};
		YB_ListItem(string serializeString):YB_ListItem()
		{
			this->Deserialize(serializeString);
			Init_Background(' ');
		};

		void						OnBind(string* contents)								override;
		void						OnBind(vector<tuple<string, string, int>*>*);
		void						OnReturn()												override;
		std::vector<char*>			Render()												override;


		FORMATED_LIST_VIEW_VALUES*	row = {};
		/// <summary>
		/// This indicate the Id point to a logic data object. NOT the viewItem Id.
		/// The value will likely be filled when listItem is binded.
		/// </summary>
		int							dataId;
	private:
	};

}