#pragma once
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
			InitBackground(' ');
		};

		void				OnKey(char* keycode) override;
		void				OnSelect()			 override;
		void				OnReturn()			 override;
		std::vector<char*>	Render()			 override;

	};

}