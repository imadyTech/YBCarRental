#pragma once
#include "YB_ViewItemBasis.h"
#include <vector>

namespace YBConsoleViews
{
	class YB_InputItem : public YB_ViewItemBasis
	{
	public:
		YB_InputItem() :YB_ViewItemBasis(w, h) {};
		YB_InputItem(string serializeString):YB_InputItem()
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