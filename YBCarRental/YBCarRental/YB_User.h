#pragma once
#include <string>
#include "YB_DataBasis.h"

using namespace std;


namespace YBCarRental
{

	class YB_User : public YB_DataBasis
	{
	public:
		YB_User();
		YB_User(string username, int password);

		int	Id;					//The unique id of user;
		string UserName;		//max 12 alphabets;
		string FirstName;
		string FamilyName;
		string Password;		//max 6 digits alphabet/numerics;
		string UserRoles;		//multiple roles are allowed, separated by ";"
		bool LoginStatus;		//true: logged in; false: logged out;
		int Balance;		//Account Balance allows user to hire a car (fail to rent if no sufficient balance).

		string Serialize();
		void Deserialize(string line);
	};
}
