#pragma once
#include "YB_ViewItemBasis.h"

namespace YBConsoleViews
{
	class ButtonViewItem : public YB_ViewItemBasis
	{
	public:
		int* targetViewId;					//Jump to a view
		YB_ViewItemBasis parentView;


		char* Render() override;			// 1 line text
		void OnSelect() override;
		void OnReturn() override;

	};

}