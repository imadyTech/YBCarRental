#ifndef YB_ListView_H
#define YB_ListView_H

#include "YB_ViewBasis.h"

namespace YBConsoleViews
{
	class YB_ListView : public YBConsoleViews::YB_ViewBasis
	{
	public:
		void			OnKey(char* keycode)				override;
		void			OnReturn(YB_ViewMessageBasis msg)	override;
		vector<char*>	Render()							override;
	};
}

#endif // YB_ListView_H