#ifndef YB_DetailsView_H
#define YB_DetailsView_H

#include "YB_ViewBasis.h"

namespace YBConsoleViews
{
	class YB_DetailsView : public YBConsoleViews::YB_ViewBasis
	{
	public:
		YB_DetailsView() :YB_ViewBasis(&w, &h) {};
		YB_DetailsView(string serializeString) :YB_DetailsView()
		{
			this->Deserialize(serializeString);
			Init_Background(' ');
		};




		void			OnKey(int* keycode)					override;
		void			OnChildReturn(YB_ViewMessageBasis* msg)	override;
		vector<char*>	Render()							override;
	};

}

#endif // YB_DetailsView_H