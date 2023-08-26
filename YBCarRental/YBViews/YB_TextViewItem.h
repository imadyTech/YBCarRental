#pragma once
#include "YB_ViewItemBasis.h"
#include <vector>


namespace YBConsoleViews
{
	class YB_TextViewItem : public YB_ViewItemBasis
	{
	public:
		vector<char*> Render() override;			// 1 line text
		void OnSelect() override;
		void OnReturn() override;
	};
}