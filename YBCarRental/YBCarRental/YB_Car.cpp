#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "YB_User.h"
#include "YB_Car.h"
using namespace std;

namespace YBCarRental
{
	YB_Car::~YB_Car()
	{
	}

	void YB_Car::Serialize(ofstream* output)
	{
		*output << Id << ";";
		*output << Make << ";";
		*output << Model << ";";
		*output << Year << ";";
		*output << Mileage << ";";
		*output << IsAvailable << ";";
		*output << MinRentPeriod << ";";
		*output << MaxRentPeriod << ";";
		*output << DayRentPrice << ";";
	}
	void YB_Car::Deserialize(string line)
	{
		//Id = to_integer(line);
	};

}


