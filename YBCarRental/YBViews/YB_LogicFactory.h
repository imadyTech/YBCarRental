#pragma once
#include "YB_DataSource_Interface.h"


namespace YBConsoleViews {


	/// <summary>
	/// YB_LogicFactory is the abstrct bridge to bind the view objects and application logic services.
	/// </summary>
	class YB_LogicFactory
	{
	public:
		YB_LogicFactory() {};

		/// <summary>
		/// register a service instance defined in the repo file with tag "DataSource"
		/// </summary>
		/// <param name="sourceName"></param>
		/// <param name="service"></param>
		virtual bool RegisterDataSource(const char* sourceName, YB_DataSource_Interface* service) = 0;

		/// <summary>
		/// return the service instance found in the service pool
		/// </summary>
		/// <param name="sourceName"></param>
		/// <returns></returns>
		virtual YB_DataSource_Interface* FindDataSource(string* sourceName) = 0;					


		#pragma region Example code of using service function map instead of service class map
		/// <summary>
		/// !!! This function is not used (for C++ syntax learning).
		/// But it is possible to register a service function instead of register a service class like this.
		/// ============ (based on prompt from chatGPT) ============
		/// </summary>
		/// <param name="sourceName"></param>
		/// <param name=""></param>
		//virtual void Register_DataSource_Service(string* sourceName, string* (YBConsoleViews::YB_LogicFactory::*)(void));
		#pragma endregion

	protected:
		std::map<std::string*, YB_DataSource_Interface*> serviceInstanceMap;
	};
}