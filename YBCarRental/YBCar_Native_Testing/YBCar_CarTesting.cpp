#pragma once
#include "pch.h"
#include "CppUnitTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace YBCarRental;

namespace YBCarTesting
{
	TEST_CLASS(YBCar_CarTesting)
	{
	public:
		TEST_METHOD(YB_CarSerializeTest)
		{
			//OK
			YB_Car car = YB_Car();
			car.Make = "Ford";
			car.Model = "Mustang";
			car.Year = 2015;
			car.Mileage = 6666;
			car.MinRentPeriod = 1;
			car.MaxRentPeriod = 10;
			car.IsAvailable = true;
			car.DayRentPrice = 100;
			Logger::WriteMessage(car.Serialize()->c_str());
		}
	};
}

