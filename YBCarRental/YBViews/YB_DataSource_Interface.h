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
		YB_DataSource_Interface() {};

		virtual string*								Get_PropertyValue(string* bindNamePtr) = 0;
		virtual map<string, string>*				Get_PropertyValues() = 0;										
		virtual void								Set_PropertyValue(string* bindNamePtr, string* valuePtr) = 0;
		virtual void								Set_PropertyValues(map<string, string>* valuesPtr) = 0;
	};

}