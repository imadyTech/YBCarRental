#ifndef YB_ViewItemBasis_H
#define YB_ViewItemBasis_H

#include <string>
#include <YB_DataBasis.h>

using namespace std;

namespace YBConsoleViews
{

	class YB_ViewItemBasis: public YBPersistence::YB_DataBasis
	{
	public:
		YB_ViewItemBasis(int* width) 
		{
			this->w = *width;
			viewContent = new char* [w]; 
			for (int i = 0; i < w; ++i){
				viewContent[i] = nullptr; 
			}

			x = 0;
			y = 0;
			w = 120;
			h = 1;
			isFocused = false;
			isSelected = false;
			isHidden = false;				//if an item is hidden, then the View will ignore it during rendering.

		}
		~YB_ViewItemBasis()
		{
			for (int i = 0; i < w; ++i){
				delete[] viewContent[i]; 
			}
			delete[] viewContent;
		}


		//int* viewId;						//Obsoleted, replaced by Id in YB_DataBasis
		int x,  y;						//relative coordinate inside the view
		int w;								//Width of the viewItem.
		int h;								//Height of the viewItem.
		bool isFocused;
		bool isSelected;
		bool isHidden;						//if an item is hidden, then the View will ignore it during rendering.
		//int* z;							//for simplicity, z will not be implemented, carefully place viewitems in order among the ViewItemRepo.txt definition.

		//copy assignment operator
		YB_ViewItemBasis& operator=(const YB_ViewItemBasis& other) {
			if (this != &other) {
				x = other.x;
				y = other.y;
				w = other.w;
				h = other.h;
				isFocused = other.isFocused;
				isSelected = other.isSelected;
				isHidden = other.isHidden;

				YB_DataBasis::operator=(other);
			}
			return *this;
		}

		virtual string* Serialize() override;
		virtual void Serialize(std::stringstream& strStream) override;
		void Deserialize(string line);
		virtual void Deserialize(string line, const char* separator) override;

	protected:
		virtual char* Render();				// 1 line text
		virtual void OnSelect();
		virtual void OnReturn();

		char** viewContent;					//content for a line

	private:
		const char persistentSeparator = '!';//indicate how the persistence string was separated (for 2nd level classes).
	};

}
#endif