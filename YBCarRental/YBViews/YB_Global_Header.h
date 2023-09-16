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

	static const char*				msgDef_ListItem				= "ListItem";
	static const char*				msgDef_Menu					= "MENU";

	static const char*				VIEWITEM_TYPE_BUTTON		= "ButtonItem";
	static const char*				VIEWITEM_TYPE_TEXT			= "TextItem";
	static const char*				VIEWITEM_TYPE_INPUT			= "InputItem";
	static const char*				VIEWITEM_TYPE_HEAD			= "ListHead";
	static const char*				VIEWITEM_TYPE_LISTITEM		= "ListItem";

	static const char*				Button_Type_Submit			= "Submit";
	static const char*				Button_Type_Delete			= "BtnDelete";
	static const char*				Button_Type_Yes				= "BtnYes";
	static const char*				Button_Type_No				= "BtnNo";
	static const char*				Button_Type_Ok				= "BtnOk";

	//when submit, the binded item's content will be passed to the datasource VM
	//EXAMPLE: a button with 'Bind:ButtonContent!' the the button's content will be passed.
	//if you need retrieve which button is clicked, just use "(*valuesMapPtr)["ButtonContent"]"
	static const char*				SUBMIT_BINDKEY_BUTTONCONTENT= "ButtonContent";

	static const std::string		INIT_VIEW					= "MainMenuView";
	static const std::string		EXIT_VIEW					= "ByeByeView";
	static const std::string		MAIN_VIEW					= "MainMenuView";
	static const std::string		USER_MAIN_VIEW				= "UserMenu";
	static const std::string		ADMIN_MAIN_VIEW				= "AdminMenu";
	static const std::string		ERROR_VIEW					= "ErrorView";
	

	static const std::string		PROMPT_MESSAGEBOX_VIEW_ITEM = "Id:99990!x:2!y:01!w:116!h:27!ItemType:ButtonItem!Content:!ButtonType:BtnOk!Background:.!isCentral:1!isFocused:1!isSelected:0!isHidden:1!;";

}