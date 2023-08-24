#pragma once
#include <string>
using namespace std;

namespace YBConsoleViews
{
	class YB_ViewMessageBasis
	{
	public:
		string* msg;
	};


	class YB_ButtonYesMessage : YB_ViewMessageBasis
	{

	};
	class YB_ButtonNoMessage : YB_ViewMessageBasis
	{

	};
	class YB_ListItemMessage : YB_ViewMessageBasis
	{
	public:
		int itemId;
	};	
	
	class YB_InputItemMessage : YB_ViewMessageBasis
	{

	};
}