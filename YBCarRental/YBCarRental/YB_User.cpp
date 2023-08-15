#include "YB_User.h"
#include <string>
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
	string YB_User::Serialize()
	{
		return string();
	}
	void YB_User::Deserialize(string line)
	{
	};
}


