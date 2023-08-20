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

	string* YB_Rent::Serialize()
	{
		std::stringstream ss;
		char buffer[32];
		ss << Id << ";"
			<< UserId << ";"
			<< CarId << ";"
			<< strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &RentStart) << ";"
			<< RentDays << ";"
			<< Status << ";";
		std::string* serializedString = new std::string(ss.str());
		return serializedString;
	}

	void YB_Rent::Serialize(ofstream* output)
	{
		char buffer[10];

		*output << Id << ";"
			<< UserId << ";"
			<< CarId << ";"
			<< strftime(buffer, sizeof(buffer), "%Y-%m-%d", &RentStart) << ";"
			<< RentDays << ";"
			<< Status << ";";
	}


	void YB_Rent::Deserialize(string line)
	{
		std::vector<std::string> words;

		std::istringstream strStream(line);
		std::string word;

		while (std::getline(strStream, word, ';')) {
			words.push_back(word);
		}
		Id = std::stoi(words[0]);
		UserId = std::stoi(words[1]);
		CarId = std::stoi(words[2]);
		//sscanf(words[3].c_str(), "%Y-%m-%d", &RentStart.tm_year, &RentStart.tm_mon, &RentStart.tm_mday);
		int year, month, day;
		if (sscanf_s(words[3].c_str(), "%d-%d-%d", &year, &month, &day) == 3) {
			RentStart.tm_year = year - 1900; // Adjust year by 1900
			RentStart.tm_mon = month - 1;    // Adjust month by 1
			RentStart.tm_mday = day;
		}
		else {
			throw YB_DeSerializeError();
		}
		RentDays = std::stoi(words[4]);
		Status = words[5];
	};

}


