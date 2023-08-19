#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "YB_DataBasis.h"
#include "YB_Rent.h"
#include "YB_User.h"
#include "YB_Car.h"
#include "ctime"
using namespace std;


namespace YBCarRental
{
    YB_Rent::YB_Rent()
    {
    }
    YB_Rent::YB_Rent(YB_User user, YB_Car car, tm start, int days)
    {
    }
    YB_Rent::YB_Rent(int userId, int carId, tm start, int days)
    {
    }

	YB_Rent::~YB_Rent()
	{
	}

	void YB_Rent::Serialize(ofstream* output)
	{
		char buffer[32];

		*output << Id << ";";
		*output << UserId << ";";
		*output << CarId << ";";
		*output << strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &RentStart) << ";";
		*output << RentDays << ";";
		*output << Status << ";";
	}
	void YB_Rent::Deserialize(string line)
	{
		//Id = to_integer(line);
	};

}


