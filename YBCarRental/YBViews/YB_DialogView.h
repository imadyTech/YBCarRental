#ifndef YB_DialogView_H
#define YB_DialogView_H

#include "YB_ViewBasis.h"

namespace YBConsoleViews
{
	class YB_DialogView : public YBConsoleViews::YB_ViewBasis
	{
	public:
		YB_DialogView() :YB_ViewBasis(&w, &h) {};
		YB_DialogView(string serializeString) :YB_DialogView()
		{
			this->Deserialize(serializeString);
			Init_Background(' ');
		};

		void			OnKey(int* keycode)					override;
		void			OnChildReturn(YB_ViewMessageBasis* msg)	override;
		vector<char*>	Render()							override;
	};
}

#endif // YB_DialogView_H