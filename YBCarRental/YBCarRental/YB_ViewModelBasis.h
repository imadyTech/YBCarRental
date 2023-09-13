#define _HAS_STD_BYTE 0
#pragma once
#include <map>
#include <string>
#include "YB_User.h"
#include "YB_Car.h"
#include "YB_Rent.h"
#include "YB_LogicFactory.h"
#include "YB_ManagerBasis.h"
#include "YB_Window.h"
#include "YB_Global_Header.h"

using namespace YBConsoleViews;
using namespace std;

class YBConsoleViews::YB_Window;


namespace YBCarRental {
	template<class TData = YB_DataBasis>
	class YB_ViewModelBasis : /*public TData,*/ public YBConsoleViews::YB_DataSource_Interface
	{
	public:
		YB_ViewModelBasis() {};
		YB_ViewModelBasis(YBConsoleViews::YB_Window* windowPtr) {
			this->windowPtr = windowPtr;
		};

		virtual string*					Get_PropertyValue(string* bindNamePtr)										override;
		virtual bool					Get_QuerySingle(int Id, vector<LIST_ITEM_VALUE*>& result)					override;
		virtual bool					Get_QueryByIndex(int index, vector<LIST_ITEM_VALUE*>& result)				override;
		virtual void					Get_QueryList(vector<LIST_ITEM_VALUES*>& result)							override;
		virtual YB_DataBasis*			Get_PrincipalData()															override;
		virtual YB_DataBasis*			Get_PrincipalData(int Id) 													override;
		virtual void					Set_PropertyValue(string* bindNamePtr, string* valuePtr)					override;
		virtual void					Set_PropertyValues(map<string, string>* values)								override;

		virtual map<string, string>* onListInitiated(string* tableHeadNames)										override
		{
			return nullptr;
		};							//tableheadNames format: Model/Make/Mileage
		virtual map<string, string>* onListInitiated(string* tableHeadNames, int pageNum, int size)					override
		{
			return nullptr;
		};		//Table paging, Todo...
		virtual void					onInit()																	override {};
		virtual void					onViewForwarded(YB_DataBasis* fromData)										override {};
		virtual void					onSubmit(map<string, string>* values)										override {};
		virtual void					onContentUpdated(string* bindName, string* newValue)						override {};
		virtual void					onItemFocused(string* bindName)												override {};
		virtual void					onItemSelected(string* bindName)											override {};
		virtual	void					onButtonClicked(string* buttonName)											override {};
		virtual void					onYesClicked()																override {};
		virtual void					onNoClicked()																override {};
		virtual void					onOkClicked()																override {};

		YB_Window* windowPtr = nullptr;
		TData* principalObject = {}; //the principal was introduced to represent the TData for each VM
	protected:
		YB_ManagerBasis<TData>* dataManagerPtr;

	};


	template<class TData>
	string*								YB_ViewModelBasis<TData>::Get_PropertyValue(string* bindName)
	{
		if (principalObject)
			return principalObject->FindValue(*bindName);
		else
			return nullptr;
	}

	template<class TData>
	inline bool							YB_ViewModelBasis<TData>::Get_QuerySingle(int Id, vector<LIST_ITEM_VALUE*>& result)
	{
		if (dataManagerPtr)
		{
			auto* dataPtr = dataManagerPtr->Get(Id);
			for (auto valueFieldIterator : result)
			{
				(*valueFieldIterator).second = *dataPtr->FindValue((*valueFieldIterator).first);
			}
			return true;
		}
		return false;
	}

	template<class TData>
	inline bool							YB_ViewModelBasis<TData>::Get_QueryByIndex(int index, vector<LIST_ITEM_VALUE*>& result)
	{
		if (dataManagerPtr)
		{
			//get all data :) in a map<int, TData>*
			auto dataMapPtr = dataManagerPtr->GetAll();
			if (index >= dataMapPtr->size())
				return false;
			int i = 0;
			//iterate the stupid map :(
			for (auto& mapIterator : *dataMapPtr)
			{
				if (i == index)
				{
					for (auto valueFieldIterator : result)
					{
						(*valueFieldIterator).second = *mapIterator.second.FindValue(valueFieldIterator->first);
					}
					return true;
				}
				i++;
			}
		}
	}

	template<class TData>
	inline void							YB_ViewModelBasis<TData>::Get_QueryList(vector<LIST_ITEM_VALUES*>& result)
	{
	}

	template<class TData>
	inline YB_DataBasis*				YB_ViewModelBasis<TData>::Get_PrincipalData()
	{
		return this->principalObject;
	}

	template<class TData>
	inline YB_DataBasis*				YB_ViewModelBasis<TData>::Get_PrincipalData(int Id)
	{
		this->principalObject = dataManagerPtr->Get(Id);
		return this->principalObject;
	}

	template<class TData>
	inline void							YB_ViewModelBasis<TData>::Set_PropertyValue(string* bindName, string* value)
	{
		//Todo: do you really need single property bind?
	}

	template<class TData>
	inline void							YB_ViewModelBasis<TData>::Set_PropertyValues(map<string, string>* values)
	{
		/* prompt from chatGPT:
		In C++, there is no built in support for setting the properties of an object by name at runtime
		like you might find in languages with reflection capabilities. C++ is a statically typed language,
		and properties or fields of an object are typically accessed directly through their names known at
		compile time.*/

		//size_t foundPos;
		//size_t endPos;
		//size_t keyLength;

		//for (const auto& kvp : *values) {
		//	std::string keyToReplace = kvp.first;
		//	std::string replacementValue = kvp.second;
		//	keyLength = keyToReplace.length();

		//	while ((foundPos = this->serializedString->find(kvp.first)) != std::string::npos) {
		//		endPos = this->serializedString->find(';', foundPos);
		//		this->serializedString->erase(foundPos + 1 + keyLength, endPos - foundPos - keyLength - 1);
		//		this->serializedString->insert(foundPos + 1 + keyLength, replacementValue);

		//		break;
		//	}
		//}
		//this->Deserialize(*this->serializedString);
	}

}