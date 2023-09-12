#pragma once
#include <map>
#include <vector>
#include <string>
#include "YB_DataBasis.h"
#include "YB_Global_Header.h"

using namespace std;
using namespace YBPersistence;

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
		//get the value for a field
		virtual string*							Get_PropertyValue(string* bindNamePtr) = 0;
		//query an object and fill the result as indicated in a vector ref
		virtual bool							Get_QuerySingle(int Id, vector<LIST_ITEM_VALUE*>&) = 0;
		//query the source with a index (NOT Id) and fill the result to a vector
		virtual bool							Get_QueryByIndex(int index, vector<LIST_ITEM_VALUE*>& result) = 0;
		//???
		virtual void							Get_QueryList(vector<LIST_ITEM_VALUES*>&) = 0;
		//return the current principalData only.
		virtual YB_DataBasis*					Get_PrincipalData() = 0;
		//query an return an object by the object.Id, AND store the object as principalData at meantime.
		virtual YB_DataBasis*					Get_PrincipalData(int Id) = 0;
		virtual void							Set_PropertyValue(string* bindNamePtr, string* valuePtr) = 0;
		virtual void							Set_PropertyValues(map<string, string>* valuesPtr) = 0;

		//Fired in ViewBasis.Init()
		virtual map<string, string>*			onListInitiated(string* tableHeadNames) =0;								//tableheadNames format: Model/Make/Mileage
		virtual map<string, string>*			onListInitiated(string* tableHeadNames, int pageNum, int size) =0;		//Table paging, Todo...
		virtual void							onInit() = 0;
		virtual void							onSubmit(map<string, string>* values) =0;
		virtual void							onViewForwarded(YB_DataBasis* fromData) =0;
		virtual void							onContentUpdated(string* bindName, string* newValue) =0;
		virtual void							onItemFocused(string* bindName) =0;
		virtual void							onItemSelected(string* bindName) =0;
		virtual	void							onButtonClicked(string* buttonName) =0;
		virtual void							onYesClicked() =0;
		virtual void							onNoClicked() =0;
		virtual void							onOkClicked() =0;
		/// ==================                   more pre-defined interfaces to come                  ====================
	};

}