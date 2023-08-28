#ifndef YB_WelcomeView_H
#define YB_WelcomeView_H

#include "YB_ViewBasis.h"

namespace YBConsoleViews
{
	class YB_WelcomeView : public YBConsoleViews::YB_ViewBasis
	{
	public:
		void			OnKey(char* keycode)				override;
		void			OnReturn(YB_ViewMessageBasis msg)	override;
		vector<char*>	Render()							override;
	};
}

#endif // YB_WelcomeView_H