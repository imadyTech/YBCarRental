#ifndef YB_ViewItemBasis_H
#define YB_ViewItemBasis_H

#include <string>

using namespace std;

namespace YBConsoleViews
{

	class YB_ViewItemBasis
	{
	public:
		YB_ViewItemBasis(int* width)
		{
			this->w = width;
			viewContent = new char* [*w]; 
			for (int i = 0; i < *w; ++i){
				viewContent[i] = nullptr; 
			}

			*x = 0;
			*y = 0;
			viewId = nullptr;
			*isFocused = false;
			*isSelected = false;
			*isHidden = false;				//if an item is hidden, then the View will ignore it during rendering.

		}
		~YB_ViewItemBasis()
		{
			for (int i = 0; i < *w; ++i){
				delete[] viewContent[i]; 
			}
			delete[] viewContent;
		}
		int* viewId;						//
		int* x, * y;						//relative coordinate inside the view
		int* w;
		const int h = 1;					//For simplicity, the viewItem won't have height parameter but only 1 line.
		bool* isFocused;
		bool* isSelected;
		bool* isHidden;				//if an item is hidden, then the View will ignore it during rendering.
		//int z;							//for simplicity, z will not be implemented, carefully place viewitems in order among the ViewItemRepo.txt definition.

	protected:
		virtual char* Render();				// 1 line text
		virtual void OnSelect();
		virtual void OnReturn();

		char** viewContent;					//content for a line

	private:
	};

}
#endif