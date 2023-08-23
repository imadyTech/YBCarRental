#ifndef YB_ViewBasis_H
#define YB_ViewBasis_H

#include <iostream>
#include <map>
#include <vector>
#include "YB_ViewItemBasis.h"

using namespace std;

namespace YBConsoleViews
{
	class YB_ViewBasis
	{
	public:
		char* viewId[6];
		int* w, * h;								//view size, same as window size but need be passed in.

		YB_ViewBasis(int* width, int* height);

		void AddViewItem(YB_ViewItemBasis item);
		void AddViewItems(vector<YB_ViewItemBasis> items);
		void AddViewItems(vector<string> itemsDef);

	protected:
		virtual vector<char*>* Render();			// multiple lines text
		virtual void OnSelect();
		virtual void OnReturn();

	private:
		map<int, YB_ViewItemBasis> viewItems;
	};
}
#endif YB_ViewBasis_H
