#include "YB_CarPersistor.h"

using namespace std;

namespace YBCarRental
{
	class YB_CarManager
	{
		YB_CarManager();

		static bool AddCar(YB_Car car);
		static bool DeleteCar(YB_Car car);
		static bool DeleteCar(int carId);
		static bool UpdateCar(YB_Car car);
	};
}