#ifndef YB_Car_H
#define YB_Car_H

#include <string>
#include "YB_DataBasis.h"
using namespace std;


namespace YBCarRental
{
	class YB_Car : public YB_DataBasis
	{
	public:
		YB_Car()
		{
			Id = -1;
			Make = "";
			Model = "";
			Year = -1;
			Mileage = -1;
			IsAvailable = true;
			MinRentPeriod = 1;
			MaxRentPeriod = 30;
			DayRentPrice = 0;
		};
		YB_Car(string make, string model, int year, int mileage) : YB_Car()
		{
			Make = make;
			Model = model;
			Year = year;
			Mileage = mileage;
		};

		YB_Car(string make, string model, int year, int mileage, int minRent, int maxRent, double dayPrice) : YB_Car()
		{
			Make = make;
			Model = model;
			Year = year;
			Mileage = mileage;
			MinRentPeriod = minRent;
			MaxRentPeriod = maxRent;
			DayRentPrice = dayPrice;
		}
		~YB_Car() override;

		int Id;
		string Make;
		string Model;
		int Year;
		int Mileage;
		bool IsAvailable;					//is the car available now?
		int MinRentPeriod;					//day
		int MaxRentPeriod;					//day
		double DayRentPrice;				//rental price per day;

		string* Serialize() override;
		void Serialize(ofstream* output) override;
		void Deserialize(string line) override;
	};
}

#endif