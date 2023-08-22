#ifndef YB_ViewItemBasis_H
#define YB_ViewItemBasis_H

#include <string>

using namespace std;

namespace YBConsoleViews
{

	class YB_ViewItemBasis
	{
	public:
		char* viewId[6];
		int* x, * y;						//relative coordinate inside the view
		int* w, * h;
		bool* isHighlight;

	protected:
		virtual char* Render();			// 1 line text
		virtual void OnSelect();
		virtual void OnReturn();


	private:
		char* viewContent[];	//content for a line
	};

}
#endif