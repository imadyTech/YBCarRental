#pragma once
#include <string>
using namespace std;

namespace YBConsoleViews
{

	static const char* msgDef_Submit	= "SUBMIT";
	static const char* msgDef_Yes		= "YES";
	static const char* msgDef_No		= "NO";
	static const char* msgDef_Menu		= "MENU";
	static const char* msgDef_ListItem	= "ListItem";

	class YB_ViewMessageBasis
	{
	public:

		void operator()(char* message) {
			YB_ViewMessageBasis::Message = message;
		}

		const char* Message;
	protected:
		YB_ViewMessageBasis(const char* Message) : Message(const_cast<char*> (Message)) {}
	};



#pragma region ================= Concrete Messages ==================
	class YB_ButtonSubmitMessage :	public YB_ViewMessageBasis
	{
	public:
		YB_ButtonSubmitMessage()				: YB_ViewMessageBasis(msgDef_Submit) {}

	};	
	
	class YB_ButtonYesMessage :		public YB_ViewMessageBasis
	{
	public:
		YB_ButtonYesMessage()					: YB_ViewMessageBasis(msgDef_Yes) {}

	};

	class YB_ButtonNoMessage :		public YB_ViewMessageBasis
	{
	public:
		YB_ButtonNoMessage()					: YB_ViewMessageBasis(msgDef_No) {}
	};

	class YB_MenuItemMessage :		public YB_ViewMessageBasis
	{
	public:
		YB_MenuItemMessage()					: YB_ViewMessageBasis(msgDef_Menu) {}
		YB_MenuItemMessage(const string& link)	: YB_ViewMessageBasis(link.c_str()) {}
	};

	class YB_ListItemMessage :		public YB_ViewMessageBasis
	{
	public:
		YB_ListItemMessage()					: YB_ViewMessageBasis(msgDef_ListItem) {}
		YB_ListItemMessage(int id)	: YB_ViewMessageBasis(msgDef_ListItem) {
			this->itemId = id;
		}
		int itemId;
	};

	class YB_InputItemMessage :		public YB_ViewMessageBasis
	{
	public:

	};
#pragma endregion
}