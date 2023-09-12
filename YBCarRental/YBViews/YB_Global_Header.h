#pragma once
#include <map>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

namespace YBConsoleViews {

	typedef std::vector<std::pair<string, int>*>				LIST_HEAD_TEMPLATE;
	typedef std::pair<string, string>							LIST_ITEM_VALUE;
	typedef std::vector<std::pair<string, string>*>				LIST_ITEM_VALUES;
	typedef std::tuple<string, string, int>						FORMATED_LIST_ITEM_VALUE;
	typedef std::vector<std::tuple<string, string, int>*>		FORMATED_LIST_VIEW_VALUES;

	static const char*		msgDef_ListItem		= "ListItem";
	static const char*		msgDef_Menu			= "MENU";

	static const char*		Button_Type_Submit	= "Submit";
	static const char*		Button_Type_Yes		= "BtnYes";
	static const char*		Button_Type_No		= "BtnNo";
	static const char*		Button_Type_Ok		= "BtnOk";

}