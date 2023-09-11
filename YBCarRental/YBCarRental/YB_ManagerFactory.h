#define _HAS_STD_BYTE 0

#pragma once
#include "YB_UserManager.h"
#include "YB_CarManager.h"
#include "YB_RentManager.h"
#include <filesystem>
#include "YB_Window.h"

using namespace YBCarRental;

/// <summary>
/// YB_ManagerFactory is somehow act as global DI (dependency injection) framework
/// you may use YBCarRental::YB_ManagerFactory::userMgr to access the logic maanager
/// </summary>
class YB_ManagerFactory
{
public:
	static YB_UserManager*	UserMgr;
	static YB_CarManager*	CarMgr;
	static YB_RentManager*	RentMgr;

	YB_ManagerFactory() {
		UserMgr = new YB_UserManager(currentDir.string() + "\\UserRepo.txt");
		UserMgr->LoadAll();

		CarMgr = new YB_CarManager(currentDir.string() + "\\CarRepo.txt");
		CarMgr->LoadAll();

		RentMgr = new YB_RentManager(currentDir.string() + "\\RentRepo.txt");
		RentMgr->LoadAll();
	}
private:
	std::filesystem::path	currentDir = std::filesystem::current_path();

};

