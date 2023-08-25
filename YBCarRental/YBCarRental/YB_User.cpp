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
	/*void YB_User::Serialize(ofstream* output)
	{
		*output << Id			<<";"
			<< UserName <<";"
			<< LoginStatus 	<<";"
			<< FirstName <<";"
			<< FamilyName <<";"
			<< Password 	<<";"
			<< Balance 		<<";"
			<< UserRoles <<";";
	}*/

	void YB_User::Deserialize(string line, const char* separator)
	{
		//std::vector<std::string>* words = YB_DataBasis::SplitLine(&line);	//Obsoleted
		//YB_DataBasis::SplitLine(&line,  &persistentSeparator				//Obsoleted, line splited in base method

		//Id = std::stoi(*YB_DataBasis::FindValue("Id"));					//Obsoleted
		YB_DataBasis::Deserialize(line, &persistentSeparator);

		UserName = *YB_DataBasis::FindValue("UserName");
		LoginStatus = *YB_DataBasis::FindValue("LoginStatus") =="1";
		FirstName = *YB_DataBasis::FindValue("FirstName");
		FamilyName = *YB_DataBasis::FindValue("FamilyName");
		Password = *YB_DataBasis::FindValue("Password");
		Balance =std::stod(*YB_DataBasis::FindValue("Balance"));
		UserRoles = *YB_DataBasis::FindValue("UserRoles");
	};


}




