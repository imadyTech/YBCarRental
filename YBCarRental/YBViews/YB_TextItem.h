#pragma once
#include "YB_ViewItemBasis.h"
#include <vector>


namespace YBConsoleViews
{
	class YB_TextItem : public YB_ViewItemBasis
	{
	public:
		YB_TextItem() :YB_ViewItemBasis(w, h) {};
		YB_TextItem(string serializeString) :YB_TextItem()
		{
			this->Deserialize(serializeString);
			Init_Background(' ');
		};

		void				OnKey(int* keycode) override;
		void				OnBackspace()			 override;
		void				OnReturn()			 override;
		std::vector<char*>	Render()			 override;
	};
}