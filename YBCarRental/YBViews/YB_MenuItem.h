#pragma once
#include "YB_ViewItemBasis.h"
#include <vector>

namespace YBConsoleViews
{
	class YB_MenuItem : public YB_ViewItemBasis
	{
	public:
		YB_MenuItem() :YB_ViewItemBasis(w, h) {};
		YB_MenuItem(string serializeString):YB_MenuItem()
		{
			this->Deserialize(serializeString);
			Init_Background(' ');
		};

		void				OnReturn()				override;
		std::vector<char*>	Render()				override;
	};

}