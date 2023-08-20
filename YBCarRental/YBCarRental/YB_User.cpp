#include "YB_User.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <vector>
using namespace std;


namespace YBCarRental
{
	YB_User::YB_User()
	{
		Id = -1;
		Balance = -1;
		LoginStatus = false;
		UserName = "";
		Password = "";
	}
	YB_User::YB_User(string username, int password) : YB_User::YB_User()
	{
		UserName = username;
		Password = password;
	}

	YB_User::~YB_User()
	{
	}

	string* YB_User::Serialize()
	{
		std::stringstream ss;
		ss << Id << ";"
			<< UserName << ";"
			<< LoginStatus << ";"
			<< FirstName << ";"
			<< FamilyName << ";"
			<< Password << ";"
			<< Balance << ";"
			<< UserRoles<<";";
		std::string* serializedString = new std::string(ss.str());
		return serializedString;
	}

	//batch serialization to filestream
	void YB_User::Serialize(ofstream* output)
	{
		*output << Id			<<";"
			<< UserName <<";"
			<< LoginStatus 	<<";"
			<< FirstName <<";"
			<< FamilyName <<";"
			<< Password 	<<";"
			<< Balance 		<<";"
			<< UserRoles <<";";
	}

	void YB_User::Deserialize(string line)
	{
		std::vector<std::string> words;

		std::istringstream strStream(line);
		std::string word;

		while (std::getline(strStream, word, ';')) {
			words.push_back(word);
		}
		Id = std::stoi( words[0]);
		UserName = words[1];
		LoginStatus = (words[2]=="1");
		FirstName = words[3];
		FamilyName = words[4];
		Password = words[5];
		Balance =std::stod(words[6]);
		UserRoles = words[7];
	};


}




