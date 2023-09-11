#ifndef YB_ListView_H
#define YB_ListView_H

#include "YB_Global_Header.h"
#include "YB_ViewBasis.h"
#include "YB_ListHead.h"

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
		int				ListRowCount;
		string			ListRowTemplate;
		void			Deserialize(string line)													override
		{
			YB_ViewBasis::Deserialize(line);

			if (YB_DataBasis::FindValue("ListHead"))		ListHead = *YB_DataBasis::FindValue("ListHead");
			if (YB_DataBasis::FindValue("ListRowCount"))	ListRowCount = std::stoi(*YB_DataBasis::FindValue("ListRowCount"));
			if (YB_DataBasis::FindValue("ListRowTemplate"))	ListRowTemplate = *YB_DataBasis::FindValue("ListRowTemplate");
		}


		void			Init()																		override;
		void			Bind()																		override;
		void			BindList()																	override;
		void			OnKey(int* keycode)															override;
		void			OnChildReturn(	YB_ViewMessageBasis* msgPtr, YB_ViewItemBasis* fromItemPtr)	override;
		void			OnConfirmReturn(YB_ViewMessageBasis* msgPtr, YB_ViewBasis* fromViewPtr)		override;
		vector<char*>	Render()																	override;

	private:
		YB_ListHead*	listHeadPtr;
	};
}

#endif // YB_ListView_H