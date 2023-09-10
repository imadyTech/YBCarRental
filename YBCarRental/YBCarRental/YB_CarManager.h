#ifndef YB_CarManager_H
#define YB_CarManager_H


#include "YB_CarPersistor.h"
#include "YB_ManagerBasis.h"
#include "YB_Car.h"
#include <map>

using namespace std;
using namespace YBPersistence;

namespace YBCarRental
{
	class YB_CarManager: public YB_ManagerBasis<YB_Car>
	{
	public:
		YB_CarManager() : YB_ManagerBasis<YB_Car>() {};
		YB_CarManager(string url): YB_ManagerBasis<YB_Car>(url) {};

		bool						AddCar(YB_Car* carPtr);
		bool						DeleteCar(YB_Car* carPtr);
		bool						DeleteCar(int carId);
		bool						UpdateCar(YB_Car* carPtr);
		YB_Car*						GetCar(int carId);
		map<int, YB_Car*>*			ListCars();
	};
}

#endif YB_CarManager_H