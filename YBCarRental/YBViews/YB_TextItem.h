#pragma once
#include "YB_ViewItemBasis.h"
#include <vector>


namespace YBConsoleViews
{
	class YB_TextItem : public YB_ViewItemBasis
	{
	public:
		void				OnKey(char* keycode) override;
		void				OnSelect()			 override;
		void				OnReturn()			 override;
		std::vector<char*>	Render()			 override;
	};
}