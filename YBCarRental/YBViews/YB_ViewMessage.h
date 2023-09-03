#pragma once
#include <string>
using namespace std;

namespace YBConsoleViews
{

	static const char* msgDef_Submit	= "SUBMIT";
	static const char* msgDef_Yes		= "YES";
	static const char* msgDef_No		= "NO";

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
	class YB_ButtonSubmitMessage : public YB_ViewMessageBasis
	{
	public:
		YB_ButtonSubmitMessage() : YB_ViewMessageBasis(msgDef_Submit) {}

	};	
	
	class YB_ButtonYesMessage : public YB_ViewMessageBasis
	{
	public:
		YB_ButtonYesMessage() : YB_ViewMessageBasis(msgDef_Yes) {}

	};

	class YB_ButtonNoMessage : YB_ViewMessageBasis
	{
	public:
		YB_ButtonNoMessage() : YB_ViewMessageBasis(msgDef_No) {}
	};

	class YB_ListItemMessage : YB_ViewMessageBasis
	{
	public:
		int itemId;
	};

	class YB_InputItemMessage : YB_ViewMessageBasis
	{
	public:

	};
#pragma endregion
}