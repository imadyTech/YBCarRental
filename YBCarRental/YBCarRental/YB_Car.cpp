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

	string* YB_Car::Serialize()
	{
		std::stringstream ss;
		ss << Id << ";"
			<< Make << ";"
			<< Model << ";"
			<< Year << ";"
			<< Mileage << ";"
			<< IsAvailable << ";"
			<< MinRentPeriod << ";"
			<< MaxRentPeriod << ";"
			<< DayRentPrice << ";";
		std::string* serializedString = new std::string(ss.str());
		return serializedString;
	}

	void YB_Car::Serialize(ofstream* output)
	{
		*output << Id << ";"
			<< Make << ";"
			<< Model << ";"
			<< Year << ";"
			<< Mileage << ";"
			<< IsAvailable << ";"
			<< MinRentPeriod << ";"
			<< MaxRentPeriod << ";"
			<< DayRentPrice << ";";
	}

	void YB_Car::Deserialize(string line)
	{
		std::vector<std::string> words;

		std::istringstream strStream(line);
		std::string word;

		while (std::getline(strStream, word, ';')) {
			words.push_back(word);
		}
		Id = std::stoi(words[0]);
		Make = words[1];
		Model = words[2];
		Year = std::stoi(words[3]);
		Mileage = std::stoi(words[4]);
		IsAvailable = (words[5]=="1");
		MinRentPeriod = std::stoi(words[6]);
		MaxRentPeriod = std::stoi(words[7]);
		DayRentPrice = std::stod(words[8]);
	};

}


