#ifndef YB_ListView_H
#define YB_ListView_H

#include "YB_ViewBasis.h"

namespace YBConsoleViews
{
	class YB_ListView : public YBConsoleViews::YB_ViewBasis
	{
	public:
		YB_ListView() :YB_ViewBasis(&w, &h) {};
		YB_ListView(string serializeString) :YB_ListView()
		{
			this->Deserialize(serializeString);
			Init_Background(' ');
		};
		void			OnKey(int* keycode)						override;
		void			OnChildReturn(YB_ViewMessageBasis* Message)	override;
		vector<char*>	Render()								override;
	};
}

#endif // YB_ListView_H