#pragma once
#include <map>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

namespace YBConsoleViews {

	typedef std::vector<std::pair<string, int>*>				LIST_HEAD_TEMPLATE;
	typedef std::pair<string, string>							LIST_ITEM_VALUE;
	typedef std::vector<std::pair<string, string>*>				LIST_ITEM_VALUES;
	typedef std::tuple<string, string, int>						FORMATED_LIST_ITEM_VALUE;
	typedef std::vector<std::tuple<string, string, int>*>		FORMATED_LIST_VIEW_VALUES;

}