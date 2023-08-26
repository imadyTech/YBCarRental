#ifndef YB_Car_H
#define YB_Car_H

#include <string>
#include "YB_DataBasis.h"
using namespace std;
using namespace YBPersistence;


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

		string Make;
		string Model;
		int Year;
		int Mileage;
		bool IsAvailable;					//is the car available now?
		int MinRentPeriod;					//day
		int MaxRentPeriod;					//day
		double DayRentPrice;				//rental price per day;

		string* Serialize() override;
		void Serialize(std::stringstream& strStream) override;
		//void Serialize(ofstream* output) override;
		void Deserialize(string line);
		void Deserialize(string line, const char* separator) override;

		//copy assignment operator
		YB_Car& operator = (const YB_Car& other) {
			if (this != &other) {
				Make = other.Make;
				Model = other.Model;
				Year = other.Year;
				Mileage = other.Mileage;
				IsAvailable = other.IsAvailable;
				MinRentPeriod = other.MinRentPeriod;
				MaxRentPeriod = other.MaxRentPeriod;
				DayRentPrice = other.DayRentPrice;
				// Call parent class copy assignment operator
				YB_DataBasis::operator=(other);
			}
			return *this;
		}

	private:
		const char persistentSeparator = ';';//indicate how the persistence string was separated (for specific class, usually 1st level).
	};
}

#endif