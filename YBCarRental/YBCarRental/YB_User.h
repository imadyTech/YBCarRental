#ifndef YB_User_H
#define YB_User_H


#include <string>
#include "YB_DataBasis.h"

using namespace std;
using namespace YBPersistence;


namespace YBCarRental
{

	class YB_User : public YB_DataBasis
	{
		ofstream* myfile = nullptr;

	public:
		YB_User();
		YB_User(string username, int password);
		~YB_User() override;

		string UserName;				//max 12 alphabets; No verification in this application.
		string FirstName;
		string FamilyName;
		string Password;				//max 6 digits alphabet/numerics;
		string UserRoles;				//multiple roles are allowed, separated by "|"
		bool LoginStatus;				//true: logged in; false: logged out;
		double Balance;					//Account Balance allows user to hire a car (fail to rent if no sufficient balance).

		string* Serialize() override;	//The overrode parent function is deprecated, but this derived interface remain unchanged
		void Serialize(std::stringstream& strStream) override;
		//void Serialize(ofstream* output) override;
		void Deserialize(string line);
		void Deserialize(string line, const char* separator) override;


		YB_User& operator=(const YB_User& other) {
			if (this != &other) {
				// Perform deep copy of members
				UserName = other.UserName;
				FirstName = other.FirstName;
				FamilyName = other.FamilyName;
				Password = other.Password;
				UserRoles = other.UserRoles;
				LoginStatus = other.LoginStatus;
				Balance = other.Balance;

				YB_DataBasis::operator=(other);
			}
			return *this;
		}
	private:
		const char persistentSeparator = ';';//indicate how the persistence string was separated (for specific class, usually 1st level).

	};

}

#endif YB_User_H