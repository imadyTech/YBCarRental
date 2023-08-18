#include "pch.h"
#include "../YBCarRental/YB_UserPersistor.h"
#include "../YBCarRental/YB_PersistorBasis.h"
TEST(TestCaseName, YB_UserPersistorTest) {
	YBCarRental::YB_UserPersistor userPersistor = YBCarRental::YB_UserPersistor("This is where the user data stored."); //OK
	//cout << userPersistor.repositoryURL << endl;

	EXPECT_EQ(userPersistor.repositoryURL, "This is where the user data stored.");
	//EXPECT_TRUE(true);

}