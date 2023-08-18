#pragma once
#include "YB_PersistorBasis.h"
#include "YB_User.h"


namespace YBCarRental
{
	class YB_UserPersistor : public YB_PersistorBasis<YB_User>
	{
	public:
		using YB_PersistorBasis<YB_User>::YB_PersistorBasis;

		YB_UserPersistor() : YB_PersistorBasis<YB_User>() { int a = 0; };
		YB_UserPersistor(string repository) :YB_PersistorBasis<YB_User>(repository) {};

		void ReadAll() ;
		void Add(YB_User user);
		void Get(int id, YB_User& objResult);// : YB_PersistorBasis <YB_User>::Get(id, *objResult);
		bool Update(YB_User obj);
		bool Delete(int id);
	};
}