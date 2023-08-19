#include "YB_User.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
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

	void YB_User::Serialize(ofstream* output)
	{
		*output << Id			<<";";
		*output << UserName <<";";
		*output << LoginStatus 	<<";";
		*output << FirstName <<";";
		*output << FamilyName <<";";
		*output << Password 	<<";";
		*output << Balance 		<<";";
		*output << UserRoles <<";";
	}
	void YB_User::Deserialize(string line)
	{
		//Id = to_integer(line);
	};


}




