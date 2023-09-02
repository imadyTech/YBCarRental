#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include "YB_User.h"
#include "YB_Car.h"
#include <vector>
using namespace std;

namespace YBCarRental
{
	YB_Car::~YB_Car()
	{
	}

	string*		YB_Car::Serialize()
	{
		std::stringstream ss;
		//Redirect to new function (instead of previous version overrided function)
		YB_Car::Serialize(ss);

		serializedString = new std::string(ss.str());
		return serializedString;
	}

	void		YB_Car::Serialize(std::stringstream& strStream)
	{
		strStream
			<< "Make:" << Make << ";"
			<< "Model:" << Model << ";"
			<< "Year:" << Year << ";"
			<< "Mileage:" << Mileage << ";"
			<< "IsAvailable:" << IsAvailable << ";"
			<< "MinRentPeriod:" << MinRentPeriod << ";"
			<< "MaxRentPeriod:" << MaxRentPeriod << ";"
			<< "DayRentPrice:" << DayRentPrice << ";";
	}

	//void YB_Car::Serialize(ofstream* output)
	//{
	//	*output << Id << ";"
	//		<< Make << ";"
	//		<< Model << ";"
	//		<< Year << ";"
	//		<< Mileage << ";"
	//		<< IsAvailable << ";"
	//		<< MinRentPeriod << ";"
	//		<< MaxRentPeriod << ";"
	//		<< DayRentPrice << ";";
	//}

	void		YB_Car::Deserialize(string line)
	{
		this->Deserialize(line, &persistentSeparator);
	}

	void		YB_Car::Deserialize(string line, const char* separator)
	{
		//std::vector<std::string>* words = YB_DataBasis::SplitLine(&line);	//Obsoleted

		YB_DataBasis::Deserialize(line, separator);

		//Id = std::stoi((*words)[0]);										//Obsoleted
		Make = *YB_DataBasis::FindValue("Make");
		Model = *YB_DataBasis::FindValue("Model");
		Year = std::stoi(*YB_DataBasis::FindValue("Year"));
		Mileage = std::stoi(*YB_DataBasis::FindValue("Mileage"));
		IsAvailable = *YB_DataBasis::FindValue("IsAvailable") == "1";
		MinRentPeriod = std::stoi(*YB_DataBasis::FindValue("MinRentPeriod"));
		MaxRentPeriod = std::stoi(*YB_DataBasis::FindValue("MaxRentPeriod"));
		DayRentPrice = std::stod(*YB_DataBasis::FindValue("DayRentPrice"));
	};

}


