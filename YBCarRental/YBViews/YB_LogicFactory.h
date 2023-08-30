#pragma once
#include "YB_DataSource.h"


namespace YBConsoleViews {


	/// <summary>
	/// YB_LogicFactory is the abstrct bridge to bind the view objects and application logics.
	/// </summary>
	class YB_LogicFactory
	{
	public:
		virtual void RegisterDataSource();

		virtual YB_DataSource* FindDataSource(string* sourceName);		//sourceName is defined in the repo file with tag "Bind"

	};

}