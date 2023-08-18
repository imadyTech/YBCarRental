#include "YB_UserPersistor.h"


namespace YBCarRental
{
	//YB_UserPersistor::YB_UserPersistor()
	//{

	//}
	//YB_UserPersistor::YB_UserPersistor(string repository)
	//{
	//}
	//YB_UserPersistor::YB_UserPersistor() : YB_PersistorBasis<YB_User>() {};
	//YB_UserPersistor::YB_UserPersistor(string repository) : YB_PersistorBasis<YB_User>(repository) {};

	void YB_UserPersistor::ReadAll()
	{

	}
	void YB_UserPersistor::Add(YB_User user)
	{
	}
	void YB_UserPersistor::Get(int id, YB_User& objResult)
	{
		YB_User bassis = YB_User();
		
	}
	bool YB_UserPersistor::Update(YB_User obj)
	{
		return false;
	}
	bool YB_UserPersistor::Delete(int id)
	{
		return false;
	}
}