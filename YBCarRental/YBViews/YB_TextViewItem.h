#pragma once
#include "YB_ViewItemBasis.h"

#pragma once
#include "YB_ViewItemBasis.h"

namespace YBConsoleViews
{
	class YB_TextViewItem : public YB_ViewItemBasis
	{
	public:
		char* Render() override;			// 1 line text
		void OnSelect() override;
		void OnReturn() override;
	};
}