#pragma once
#include "YB_ViewItemBasis.h"
#include <map>

namespace YBConsoleViews
{
	class YB_ListHead: public YB_ViewItemBasis
	{
	public:
		YB_ListHead() :YB_ViewItemBasis(w, h) {};
		YB_ListHead(string serializeString) :YB_ListHead()
		{
			//List head information is retrievable from YB_DataBasis::stringPairsMap
			//but can't be processed as a property field, as the headName is unknown at compiling time
			this->Deserialize(serializeString);

			Init_Background(' ');
		};



		//void				OnBind(string* contents)	override;
		void				OnReturn()					override;
		std::vector<char*>	Render()					override;

	};

}