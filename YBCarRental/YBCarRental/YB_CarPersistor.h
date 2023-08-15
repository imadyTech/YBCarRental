#include "YB_PersistorBasis.h"
#include "YB_Car.h"


namespace YBCarRental
{

	class YB_CarPersistor : YB_PersistorBasis<YB_Car>
	{
	public:
		YB_CarPersistor();
		YB_CarPersistor(string repository);

		void ReadAll();
		void Add(YB_Car car);
		YB_Car Get(int id);
	};
}

