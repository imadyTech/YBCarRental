#pragma once
#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace YBConsoleViews;

namespace YBCarTesting
{
	TEST_CLASS(YB_ViewItemTesting)
	{
	public:
		TEST_METHOD(ViewItem_New_Test)
		{
			int width = 120;
			YB_ViewItemBasis item = YB_ViewItemBasis(&width);

		}
	};
}