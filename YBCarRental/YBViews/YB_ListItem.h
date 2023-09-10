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
			Init_Background(' ');
		};

		void				OnBind(string* contents)	override;
		void				OnReturn()					override;
		std::vector<char*>	Render()					override;

	};

}