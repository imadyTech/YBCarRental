#ifndef YB_ViewItemBasis_H
#define YB_ViewItemBasis_H

#include <string>
#include <vector>
#include <YB_DataBasis.h>
//#include "YB_ViewBasis.h"

using namespace std;
using namespace YBPersistence;

namespace YBConsoleViews
{
	class YB_ViewItemBasis : public YBPersistence::YB_DataBasis
	{
	public:
		YB_ViewItemBasis();
		YB_ViewItemBasis(int width, int height);
		~YB_ViewItemBasis();

		#pragma region copy assignment operator
		YB_ViewItemBasis& operator=(const YB_ViewItemBasis& other) {
			if (this != &other) {
				x = other.x;
				y = other.y;
				w = other.w;
				h = other.h;
				ItemType = other.ItemType;
				Content = other.Content;
				Background = other.Background;
				isCentral = other.isCentral;
				isFocused = other.isFocused;
				isSelected = other.isSelected;
				isHidden = other.isHidden;
				viewArray = other.viewArray;

				YB_DataBasis::operator=(other);
			}
			return *this;
		};	
		#pragma endregion

#
		int								x=0, y=0;							//relative coordinate inside the view
		int								w=100;								//Width of the viewItem.
		int								h=1;								//Height of the viewItem.
		string							ItemType;
		string							Content;
		char							Background = ' ';
		bool							isCentral = true;
		bool							isFocused = false;
		bool							isSelected = false;
		bool							isHidden = false;					//if an item is hidden, then the View will ignore it during rendering.

		virtual string*					Serialize() override;
		virtual void					Serialize(std::stringstream& strStream) override;
		void							Deserialize(string line);
		virtual void					Deserialize(string line, const char* separator) override;

		virtual void					OnKey(int* keycode);
		virtual void					OnBackspace();
		virtual void					OnReturn();
		virtual std::vector<char*>		Render();
		void							Init_Background(char background);
		void							Fill_Background(char background);
		void							Clear_Background();
	protected:
		vector<char*>					viewArray;
		//YB_ViewBasis					parent;
	};


}
#endif // YB_ViewItemBasis_H