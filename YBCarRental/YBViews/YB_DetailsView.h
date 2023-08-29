#ifndef YB_DetailsView_H
#define YB_DetailsView_H

#include "YB_ViewBasis.h"

namespace YBConsoleViews
{
	class YB_DetailsView : public YBConsoleViews::YB_ViewBasis
	{
	public:
		void			OnKey(int* keycode)				override;
		void			OnReturn(YB_ViewMessageBasis msg)	override;
		vector<char*>	Render()							override;
	};

}

#endif // YB_DetailsView_H