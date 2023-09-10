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

		string			ListHead;

		void			Deserialize(string line)													override
		{
			YB_ViewBasis::Deserialize(line);

			if (YB_DataBasis::FindValue("ListHead"))		ListHead = *YB_DataBasis::FindValue("ListHead");
		}


		void			Init()																		override;
		void			OnKey(int* keycode)															override;
		void			OnChildReturn(YB_ViewMessageBasis* msgPtr, YB_ViewItemBasis* fromItemPtr)	override;
		void			OnConfirmReturn(YB_ViewMessageBasis* msgPtr, YB_ViewBasis* fromViewPtr)		override;
		vector<char*>	Render()																	override;
	};
}

#endif // YB_ListView_H