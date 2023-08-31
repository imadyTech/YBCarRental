#ifndef YB_WelcomeView_H
#define YB_WelcomeView_H

#include "YB_ViewBasis.h"

namespace YBConsoleViews
{
	class YB_WelcomeView : public YBConsoleViews::YB_ViewBasis
	{
	public:
		YB_WelcomeView() :YB_ViewBasis(&w, &h) {};
		YB_WelcomeView(string serializeString) :YB_WelcomeView()
		{
			this->Deserialize(serializeString);
			Init_Background(' ');
		};

		void					OnKey(int* keycode)						override;
		void					OnChildReturn(YB_ViewMessageBasis msg)	override;
		vector<char*>			Render()								override;

	};
}

#endif // YB_WelcomeView_H