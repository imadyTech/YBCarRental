#ifndef YB_MenuView_H
#define YB_MenuView_H
#include "YB_ViewBasis.h"

namespace YBConsoleViews
{
	class YB_MenuView : public YBConsoleViews::YB_ViewBasis
	{
	public:
		void			OnKey(char* keycode)				override;
		void			OnReturn(YB_ViewMessageBasis msg)	override;
		vector<char*>	Render()							override;
	};
}
#endif // YB_MenuView_H