#ifndef YB_InputView_H
#define YB_InputView_H

#include "YB_ViewBasis.h"

namespace YBConsoleViews
{
	class YB_InputView : public YBConsoleViews::YB_ViewBasis
	{
	public:
		YB_InputView() :YB_ViewBasis(&w, &h) {};
		YB_InputView(string serializeString) :YB_InputView()
		{
			this->Deserialize(serializeString);
			Init_Background(' ');
		};

		void			OnKey(int* keycode)				override;
		void			OnChildReturn(YB_ViewMessageBasis msg)	override;
		vector<char*>	Render()							override;
	};
}

#endif // YB_InputView_H