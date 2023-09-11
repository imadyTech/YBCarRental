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

using namespace YBConsoleViews;
using namespace std;

class YBConsoleViews::YB_Window;


namespace YBCarRental {
	template<class TData = YB_DataBasis>
	class YB_ViewModelBasis : /*public TData,*/ public YBConsoleViews::YB_DataSource_Interface
	{
	public:
		YB_ViewModelBasis() {};

		virtual string*					Get_PropertyValue(string* bindNamePtr)										override;
		virtual void					Get_QuerySingle (int Id, vector<std::pair<string, string>*>& result)	override;
		virtual void					Get_QueryList(vector<vector<std::pair<string, string>*>*>& result)		override;
		virtual void					Set_PropertyValue(string* bindNamePtr, string* valuePtr)					override;
		virtual void					Set_PropertyValues(map<string, string>* values)								override;

		virtual map<string, string>*	onListInitiated(string* tableHeadNames) { return nullptr; };							//tableheadNames format: Model/Make/Mileage
		virtual map<string, string>*	onListInitiated(string* tableHeadNames, int pageNum, int size) { return nullptr; };		//Table paging, Todo...
		virtual void					onInit()													{};
		virtual void					onViewForwarded(YB_DataSource_Interface* from)				{};
		virtual void					onSubmit(map<string, string>* values)						{};
		virtual void					onContentUpdated(string* bindName, string* newValue)		{};
		virtual void					onItemFocused(string* bindName)								{};
		virtual void					onItemSelected(string* bindName)							{};
		virtual	void					onButtonClicked(string* buttonName)							{};
		virtual void					onYesClicked()												{};
		virtual void					onNoClicked()												{};

		YB_Window*						windowPtr = nullptr;
		TData*							principalObject = {}; //the principal was introduced to represent the TData for each VM
	protected:
		YB_ManagerBasis<TData>*			dataManagerPtr;

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
	inline void							YB_ViewModelBasis<TData>::Get_QuerySingle(int Id, vector<std::pair<string, string>*>& result)
	{
		if (dataManagerPtr)
		{
			auto data = dataManagerPtr->Get(Id);
			for (auto tupIterator: result)
			{
				(*tupIterator).second = *data->FindValue((*tupIterator).first);
			}
		}
	}

	template<class TData>
	inline void							YB_ViewModelBasis<TData>::Get_QueryList(vector<vector<std::pair<string, string>*>*>& result)
	{
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