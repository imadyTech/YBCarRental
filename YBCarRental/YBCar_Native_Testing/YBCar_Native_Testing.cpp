#include "pch.h"
#include "CppUnitTest.h"
#include "../YBCarRental/YB_UserPersistor.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace YBCarRental;

namespace YBCarNativeTesting
{
	TEST_CLASS(YBCarNativeTesting)
	{
	public:
		
		TEST_METHOD(YB_UserPersistorTest)
		{
			//Testing the persistors and how C++ template class and method works.
			//YB_User user = YB_User();       //OK
			//YB_PersistorBasis<YB_DataBasis> userPersistor = YB_PersistorBasis<YB_DataBasis>(); //Not tested
			//YB_PersistorBasis<YB_User> userPersistor = YB_PersistorBasis<YB_User>("This is where the data stored.");  //OK
			YBCarRental::YB_UserPersistor userPersistor = YBCarRental::YB_UserPersistor("This is where the user data stored."); //OK
			cout << userPersistor.repositoryURL << endl;
			//Assert::AreEqual( "This is where the user data stored." , userPersistor.repositoryURL.c_str());
		}
	};
}
