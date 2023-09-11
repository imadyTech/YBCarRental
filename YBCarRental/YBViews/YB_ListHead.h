#pragma once
#include "YB_Global_Header.h"
#include "YB_ViewItemBasis.h"
#include <vector>
using namespace std;

namespace YBConsoleViews
{
	class YB_ListHead: public YB_ViewItemBasis
	{
	public:
		YB_ListHead() :YB_ViewItemBasis(w, h) {
			tableRowFormatter = new std::vector<std::pair<string, int>*>();
		};
		YB_ListHead(string serializeString) :YB_ListHead()
		{
			//List head information is retrievable from YB_DataBasis::stringPairsMap
			//but can't be processed as a property field, as the headName is unknown at compiling time
			this->Deserialize(serializeString);

			Init_Background(' ');
		};



		void						Deserialize(string contents)	override;
		void						OnReturn()						override;
		std::vector<char*>			Render()						override;

		//this will be used for create the table row content fields in fixed order
		//columnName, columnContent, columnWidth
		LIST_HEAD_TEMPLATE*			tableRowFormatter;			
	};

}