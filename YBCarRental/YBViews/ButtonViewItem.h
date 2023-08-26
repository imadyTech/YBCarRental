#pragma once
#include "YB_ViewItemBasis.h"
#include <vector>

namespace YBConsoleViews
{
	class ButtonViewItem : public YB_ViewItemBasis
	{
	public:
		int* targetViewId;					//Jump to a view
		YB_ViewItemBasis parentView;


		vector<char*> Render() override;			// 1 line text
		void OnSelect() override;
		void OnReturn() override;

	};

}