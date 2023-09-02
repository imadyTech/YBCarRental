#pragma once
#include "YB_LogicFactory.h"
#include "YB_DataSource_Interface.h"
#include "YB_CarRentViewModels.h"
using namespace std;
using namespace YBConsoleViews;

namespace YBCarRental {

	class YB_CarRental_LogicFactory : public YBConsoleViews::YB_LogicFactory
	{
	public:
		YB_CarRental_LogicFactory() : YB_LogicFactory::YB_LogicFactory()
		{
		};

		/// <summary>
		/// register a service instance defined in the repo file with tag "DataSource"
		/// </summary>
		/// <param name="sourceName"></param>
		/// <param name="service"></param>
		bool RegisterDataSource(const char* sourceName, YB_DataSource_Interface* service) override;

		/// <summary>
		/// return the service instance found in the service pool
		/// </summary>
		/// <param name="sourceName"></param>
		/// <returns></returns>
		YB_DataSource_Interface* FindDataSource(string* sourceName) override;



		#pragma region Example code of using service function map instead of service class map
		//!!!it is possible to register a service function instead of register a service class like this.
		//!!!============ (based on prompt from chatGPT) ============
		//std::map<std::string, string* (YBCarRental::YB_CarRental_LogicFactory::*)(void)> mapping;									//service function map declaration
		//void Register_DataSource_Service(string* sourceName, string* (YBConsoleViews::YB_LogicFactory::*)(void)) override			//service registration
		//{
		//	mapping["Add"] = &YB_CarRental_LogicFactory::Add;																		//register service function
		//	string str = "Add";
		//	(this->*mapping[str])();
		//}
		//string* Add() {
		//	//some seudo sample code
		//}
		#pragma endregion

	};

}
