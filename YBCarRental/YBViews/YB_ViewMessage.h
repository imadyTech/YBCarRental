#pragma once
#include <string>
using namespace std;

namespace YBConsoleViews
{
	class YB_ViewMessageBasis
	{
	public:
		void operator()(char* message) {
			YB_ViewMessageBasis::msg = message;
		}
	protected:
		YB_ViewMessageBasis(const char* msg) : msg(const_cast<char*> (msg)) {}
		const char* msg;
	};


	class YB_ButtonSubmitMessage : public YB_ViewMessageBasis
	{
	public:
		YB_ButtonSubmitMessage() : YB_ViewMessageBasis("YB_ButtonSubmitMessage") {}

	};	
	
	class YB_ButtonYesMessage : public YB_ViewMessageBasis
	{
	public:
		YB_ButtonYesMessage() : YB_ViewMessageBasis("YB_ButtonYesMessage") {}

	};
	class YB_ButtonNoMessage : YB_ViewMessageBasis
	{
	public:

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
}