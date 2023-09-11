// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

#include "../YBCarRental/YB_UserManager.h"
#include "../YBCarRental/YB_UserPersistor.h"
#include "../YBCarRental/YB_User.h"
#include "YB_Car.h"
#include "YB_Rent.h"
#include "YB_ViewItemBasis.h"
#include "YB_ViewBasis.h"
#include "YB_ViewFactory.h"
#include "YB_ViewItemFactory.h"

using namespace YBCarRental;
using namespace YBConsoleViews;

namespace YBCarTesting
{

	YB_User CreateSimulativeNormalUser();
	YB_User CreateSimulativeAdminUser();
}

// add headers that you want to pre-compile here

#endif //PCH_H
