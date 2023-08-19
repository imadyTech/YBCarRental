#ifndef YB_User_H
#define YB_User_H


#include <string>
#include "YB_DataBasis.h"

using namespace std;


namespace YBCarRental
{

	class YB_User : public YB_DataBasis
	{
		ofstream* myfile = nullptr;

	public:
		YB_User();
		YB_User(string username, int password);
		~YB_User() override;

		int	Id;					//The unique id of user;
		string UserName;		//max 12 alphabets;
		string FirstName;
		string FamilyName;
		string Password;		//max 6 digits alphabet/numerics;
		string UserRoles;		//multiple roles are allowed, separated by ":"
		bool LoginStatus;		//true: logged in; false: logged out;
		double Balance;		//Account Balance allows user to hire a car (fail to rent if no sufficient balance).

		void Serialize(ofstream* output) override;
		void Deserialize(string line) override;
	};

}

#endif YB_User_H