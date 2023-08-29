#pragma once
#include "YB_ViewItemBasis.h"
#include <vector>

namespace YBConsoleViews
{
	class YB_ButtonItem : public YB_ViewItemBasis
	{
	public:
		YB_ButtonItem() :YB_ViewItemBasis(w, h) {};
		YB_ButtonItem(string serializeString):YB_ButtonItem() 
		{
			this->Deserialize(serializeString);
			Init_Background(' ');
		};

		void				OnKey(int* keycode)		override;
		void				OnBackspace()			override;
		void				OnReturn()				override;
		std::vector<char*>	Render()				override;
	};

}