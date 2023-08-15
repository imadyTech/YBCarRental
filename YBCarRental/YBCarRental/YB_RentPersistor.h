#include "YB_PersistorBasis.h"
#include "YB_Rent.h"



namespace YBCarRental
{
	class YB_RentPersistor : YB_PersistorBasis<YB_Rent>
	{
	public:
		YB_RentPersistor();
		YB_RentPersistor(string repository);

		void ReadAll();
		void Add(YB_Rent order);
		YB_Rent Get(int id);
	};
}

