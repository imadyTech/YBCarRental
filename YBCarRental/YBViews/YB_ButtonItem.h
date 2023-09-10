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

		string				ButtonType;

		void				Deserialize(string line)	override
		{
			YB_ViewItemBasis::Deserialize(line);

			if (YB_DataBasis::FindValue("ButtonType"))		ButtonType = *YB_DataBasis::FindValue("ButtonType");
		}


		void				OnKey(int* keycode)			override;
		void				OnBackspace()				override;
		void				OnReturn()					override;
		std::vector<char*>	Render()					override;
	};

}