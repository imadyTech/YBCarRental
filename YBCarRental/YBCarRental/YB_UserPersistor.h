#include "YB_PersistorBasis.h"
#include "YB_User.h"



namespace YBCarRental
{
	class YB_UserPersistor : YB_PersistorBasis<YB_User>
	{
	public:
		YB_UserPersistor();
		YB_UserPersistor(string repository);

		void ReadAll();
		void Add(YB_User user);
		YB_User Get(int id);
	};
}