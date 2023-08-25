#ifndef YB_ViewBasis_H
#define YB_ViewBasis_H

#include <iostream>
#include <map>
#include <vector>
#include "YB_ViewItemBasis.h"
#include "YB_ViewMessage.h"
#include "YB_DataBasis.h"

using namespace std;
using namespace YBPersistence;

namespace YBConsoleViews
{
	class YB_ViewBasis : public YBPersistence::YB_DataBasis
	{
	public:
		int* viewId;
		char* Title[64];							//max limit to 64 characters
		int* w, * h;								//view size, same as window size but need be passed in.

		YB_ViewBasis();
		YB_ViewBasis(int* width, int* height);

		void AddViewItem(YB_ViewItemBasis item);
		void AddViewItems(vector<YB_ViewItemBasis> items);
		void AddViewItems(vector<string> itemsDef);

		virtual string* Serialize() override;
		virtual void Deserialize(string line) override;
		//void Serialize(ofstream* output) override;

	protected:
		virtual vector<char*>* Render();			// multiple lines text
		virtual void OnKeyInput(char* keycode);
		virtual void OnItemReturned(YB_ViewMessageBasis msg);

	private:
		map<int, YB_ViewItemBasis> viewItems = {};
		vector<char*>* viewContent;
	};
}
#endif //YB_ViewBasis_H
