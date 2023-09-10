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

		/// ================== These are the interfaces between view elements to viewModel datasource ====================
		virtual string*							Get_PropertyValue(string* bindNamePtr) = 0;
		virtual map<string, string>*			Get_PropertyValues() = 0;										
		virtual void							Set_PropertyValue(string* bindNamePtr, string* valuePtr) = 0;
		virtual void							Set_PropertyValues(map<string, string>* valuesPtr) = 0;

		virtual void							onViewForwarded(YB_DataSource_Interface* from) =0;
		virtual map<string, string>*			onListInitiated(string* tableHeadNames) =0;								//tableheadNames format: Model/Make/Mileage
		virtual map<string, string>*			onListInitiated(string* tableHeadNames, int pageNum, int size) =0;		//Table paging, Todo...
		virtual void							onSubmit(map<string, string>* values) =0;
		virtual void							onContentUpdated(string* bindName, string* newValue) =0;
		virtual void							onItemFocused(string* bindName) =0;
		virtual void							onItemSelected(string* bindName) =0;
		virtual	void							onButtonClicked(string* buttonName) =0;
		virtual void							onYesClicked() =0;
		virtual void							onNoClicked() =0;
		/// ==================                   more pre-defined interfaces to come                  ====================
	};

}