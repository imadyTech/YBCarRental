#pragma once
#include <map>
#include <vector>
#include <string>

using namespace std;

namespace YBConsoleViews
{
	/// <summary>
	/// Abstract interface for concrete data source objects.
	/// </summary>
	class YB_DataSource_Interface
	{
	public:
		virtual string*								Get_PropertyValue(int id) = 0;						
		virtual string*								Get_PropertyValue(string* bindName) = 0;
		virtual map<string, string>*				Get_PropertyValues() = 0;										
		virtual void								Set_PropertyValues(string* bindName, string* value) = 0;
	};

}