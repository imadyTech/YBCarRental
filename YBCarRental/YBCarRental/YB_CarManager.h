#ifndef YB_CarManager_H
#define YB_CarManager_H


#include "YB_CarPersistor.h"
#include "YB_ManagerBasis.h"

using namespace std;
using namespace YBPersistence;

namespace YBCarRental
{
	class YB_CarManager: public YB_ManagerBasis<YB_Car>
	{
	public:
		YB_CarManager() : YB_ManagerBasis<YB_Car>() {};
		YB_CarManager(string url): YB_ManagerBasis<YB_Car>(url) {};

		static bool AddCar(YB_Car car);
		static bool DeleteCar(YB_Car car);
		static bool DeleteCar(int carId);
		static bool UpdateCar(YB_Car car);
	};
}

#endif YB_CarManager_H