#pragma once
#include <map>
#include <vector>
#include <string>

using namespace std;

namespace YBConsoleViews
{
	/// <summary>
	/// Act as an interface for concrete data source objects.
	/// </summary>
	class YB_DataSource
	{
	public:
		///just pass the YB_DataBasis.stringPairsMap.
		virtual map<string, string>*				BindSingle(int id) = 0;								//return value of YBData.Serialize()
		virtual vector<map<string, string>*>		BindList() = 0;										//return list of YBData.Serialize()
		virtual void								UpdateSingle(map<string, string>* value) = 0;		//submit serialized fields value in string format
	};

}