#ifndef YB_MenuView_H
#define YB_MenuView_H
#include "YB_ViewBasis.h"

namespace YBConsoleViews
{
	class YB_MenuView : public YBConsoleViews::YB_ViewBasis
	{
	public:
		YB_MenuView() :YB_ViewBasis(&w, &h) {};
		YB_MenuView(string serializeString) :YB_MenuView()
		{
			this->Deserialize(serializeString);
			Init_Background(' ');
		};
		void			OnKey(int* keycode)						override;
		void			OnChildReturn(YB_ViewMessageBasis* msg)	override;
		vector<char*>	Render()								override;
	};
}
#endif // YB_MenuView_H