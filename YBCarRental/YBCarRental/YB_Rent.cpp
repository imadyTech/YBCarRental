#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include "ctime"
#include <vector>
#include "YB_DataBasis.h"
#include "YB_Rent.h"
#include "YB_User.h"
#include "YB_Car.h"
#include "YB_Errors.h"
using namespace std;


namespace YBCarRental
{
	YB_Rent::YB_Rent()
	{
		persistentSeparator = ';';

	}
	YB_Rent::YB_Rent(YB_User user, YB_Car car, tm start, int days):YB_Rent()
	{
	}
	YB_Rent::YB_Rent(int userId, int carId, tm start, int days):YB_Rent()
	{
	}
	YB_Rent::~YB_Rent()
	{
	}

	string*			YB_Rent::Serialize()
	{
		std::stringstream ss;
		//Redirect to new function (instead of previous version overrided function)
		YB_Rent::Serialize(ss);

		serializedString = new std::string(ss.str());
		return serializedString;
	}

	void			YB_Rent::Serialize(std::stringstream& strStream)
	{
		YB_DataBasis::Serialize(strStream);

		char buffer[20]; strftime(buffer, sizeof(buffer), "%Y-%m-%d", &RentStart);
		char buffer1[20]; strftime(buffer1, sizeof(buffer1), "%Y-%m-%d", &DateOfOrder);
		strStream
			<< "UserId:" << UserId << ";"
			<< "CarId:" << CarId << ";"
			<< "RentStart:" << buffer << ";"
			<< "DateOfOrder:" << buffer1<< ";"
			<< "RentDays:" << RentDays << ";"
			<< "Status:" << Status << ";";
	}

	void			YB_Rent::Deserialize(string line)
	{
		this->Deserialize(line, &persistentSeparator);
	}

	void			YB_Rent::Deserialize(string line, const char* separator)
	{
		//std::vector<std::string>* words = YB_DataBasis::SplitLine(&line);	//Obsoleted
		YB_DataBasis::Deserialize(line, separator);

		//Id = std::stoi((*words)[0]);										//Obsoleted
		UserId		= std::stoi(*YB_DataBasis::FindValue("UserId"));
		CarId		= std::stoi(*YB_DataBasis::FindValue("CarId"));
		RentDays	= std::stoi(*YB_DataBasis::FindValue("RentDays"));
		Status		= *YB_DataBasis::FindValue("Status");
		//sscanf(words[3].c_str(), "%Y-%m-%d", &RentStart.tm_year, &RentStart.tm_mon, &RentStart.tm_mday);
		int year, month, day;
		const char* rentStart	= (*YB_DataBasis::FindValue("RentStart")).c_str();
		if (sscanf_s(rentStart, "%d-%d-%d", &year, &month, &day) == 3) {
			RentStart.tm_year = year - 1900; // Adjust year by 1900
			RentStart.tm_mon = month - 1;    // Adjust month by 1
			RentStart.tm_mday = day;
		}
		else {
			throw YB_DeSerializeError();
		}
		const char* dateOfOrder = (*YB_DataBasis::FindValue("RentStart")).c_str();
		if (sscanf_s(dateOfOrder, "%d-%d-%d", &year, &month, &day) == 3) {
			DateOfOrder.tm_year = year - 1900; // Adjust year by 1900
			DateOfOrder.tm_mon = month - 1;    // Adjust month by 1
			DateOfOrder.tm_mday = day;
		}
		else {
			throw YB_DeSerializeError();
		}
		//RentDays = std::stoi(*YB_DataBasis::FindValue("RentDays"));
		//Status = *YB_DataBasis::FindValue("Status");
	};

}


