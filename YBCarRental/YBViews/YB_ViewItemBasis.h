#ifndef YB_ViewItemBasis_H
#define YB_ViewItemBasis_H

#include <string>
#include <vector>
#include <YB_DataBasis.h>

using namespace std;
using namespace YBPersistence;

namespace YBConsoleViews
{
	class YB_ViewItemBasis : public YBPersistence::YB_DataBasis
	{
	public:
		YB_ViewItemBasis(): YB_DataBasis::YB_DataBasis() {}
		YB_ViewItemBasis(int* width, int* height) : YB_ViewItemBasis()
		{
			this->w = *width;
			this->h = *height;
			x = 0;
			y = 0;
			isFocused = false;
			isSelected = false;
			isHidden = false;				//if an item is hidden, then the View will ignore it during rendering.

			persistentSeparator = '!';		//This is differ to other serializable objects.

		}
		~YB_ViewItemBasis()
		{
			for (char* ptr : viewArray) {
				delete[] ptr;
			}
			YB_ViewItemBasis::viewArray.clear();
		};


		//int* viewId;						//Obsoleted, replaced by Id in YB_DataBasis
		int x=0, y=0;							//relative coordinate inside the view
		int w=120;								//Width of the viewItem.
		int h=1;							//Height of the viewItem.
		bool isFocused = false;
		bool isSelected = false;
		bool isHidden = false;						//if an item is hidden, then the View will ignore it during rendering.
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
		};

		virtual string* Serialize() override;
		virtual void Serialize(std::stringstream& strStream) override;
		void Deserialize(string line);
		virtual void Deserialize(string line, const char* separator) override;

	protected:
		virtual std::vector<char*> Render();
		virtual void OnSelect();
		virtual void OnReturn();

		vector<char*> viewArray = {};
	};
}
#endif // YB_ViewItemBasis_H