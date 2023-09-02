#pragma once
#include <map>
#include <string>
#include "YB_User.h"
#include "YB_Car.h"
#include "YB_Rent.h"
#include "YB_LogicFactory.h"
#include "YB_ManagerBasis.h"

using namespace std;

namespace YBCarRental {
	template<class TData = YB_DataBasis>
	class YB_VMBasis : public TData, public YBConsoleViews::YB_DataSource_Interface
	{
	public:
		YB_VMBasis() {};

		virtual string* Get_PropertyValue(string* bindNamePtr)										override;
		virtual map<string, string>* Get_PropertyValues()											override;
		virtual void					Set_PropertyValue(string* bindNamePtr, string* valuePtr)	override;
		virtual void					Set_PropertyValues(map<string, string>* values)				override;

	protected:
		YB_ManagerBasis<TData>* dataManager{};
	};
	template<class TData>
	string* YBCarRental::YB_VMBasis<TData>::Get_PropertyValue(string* bindName)
	{
		return this->FindValue(*bindName);
	}

	template<class TData>
	map<string, string>* YBCarRental::YB_VMBasis<TData>::Get_PropertyValues()
	{
		return this->GetAllValues();
	}

	template<class TData>
	void YBCarRental::YB_VMBasis<TData>::Set_PropertyValue(string* bindName, string* value)
	{
		//Todo: do you really need single property bind?
	}

	template<class TData>
	void YBCarRental::YB_VMBasis<TData>::Set_PropertyValues(map<string, string>* values)
	{
		/* prompt from chatGPT:
		In C++, there is no built in support for setting the properties of an object by name at runtime
		like you might find in languages with reflection capabilities. C++ is a statically typed language,
		and properties or fields of an object are typically accessed directly through their names known at
		compile time.*/

		size_t foundPos;
		size_t endPos;
		size_t keyLength;

		for (const auto& kvp : *values) {
			std::string keyToReplace = kvp.first;
			std::string replacementValue = kvp.second;
			keyLength = keyToReplace.length();

			while ((foundPos = this->serializedString->find(kvp.first)) != std::string::npos) {
				endPos = this->serializedString->find(';', foundPos);
				this->serializedString->erase(foundPos + 1 + keyLength, endPos - foundPos - keyLength - 1);
				this->serializedString->insert(foundPos + 1 + keyLength, replacementValue);

				break;
			}
		}
		this->Deserialize(*this->serializedString);
	}


	class YB_UserVM : public YB_VMBasis<YB_User>
	{
	public:
		YB_UserVM(YB_ManagerBasis<YB_User>* manager) {
			dataManager = manager;
		}
		//string* Get_PropertyValue(string* bindNamePtr)										override {};

		//map<string, string>* Get_PropertyValues(string* bindNamePtr)						{
		//	return this->YB_VMBasis<YB_User>::Get_PropertyValue(bindNamePtr);
		//};
		//void					Set_PropertyValue(string* bindNamePtr, string* valuePtr)	override {};
		//void					Set_PropertyValues(map<string, string>* values)				override {};
	};
	class YB_UserListVM : public YB_VMBasis<YB_User>
	{
	public:
		//YB_UserListVM(YB_ManagerBasis<YB_User>* manager) {
		//	dataManager = manager;
		//}

	};
	class YB_CarVM : public YB_VMBasis<YB_Car>
	{

	};
	class YB_RentVM : public YB_VMBasis<YB_Rent>
	{

	};
}

