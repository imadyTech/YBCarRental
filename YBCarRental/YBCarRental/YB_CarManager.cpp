#include "YB_Car.h"
#include "YB_CarManager.h"


namespace YBCarRental
{
	bool					YB_CarManager::AddCar(YB_Car* carPtr)
	{
		auto existingCar = this->Get(carPtr->Id);
		if (existingCar)
		{
			return false; //already exist
		}
		return this->Add(*carPtr);
	}

	bool					YB_CarManager::DeleteCar(YB_Car* carPtr)
	{
		auto existingCar = this->Get(carPtr->Id);
		if (!existingCar)
		{
			return false; //car doesn't exist
		}
		return this->Delete(carPtr->Id);
	}

	bool					YB_CarManager::DeleteCar(int carId)
	{
		auto existingCar = this->Get(carId);
		if (!existingCar)
		{
			return false; //car doesn't exist
		}
		return this->Delete(carId);
	}

	bool					YB_CarManager::UpdateCar(YB_Car* carPtr)
	{
		auto existingCar = this->Get(carPtr->Id);
		if (!existingCar)
		{
			return false; //car doesn't exist
		}
		return this->Update(*carPtr);
	}

	YB_Car*					YB_CarManager::GetCar(int carId)
	{
		return this->Get(carId);
	}

	YB_Car*					YB_CarManager::GetCarByIndex(int index)
	{
		int i = 0;
		auto cars = this->ListCars();
		if (index >= cars->size())
			return nullptr;

		for (auto& carIterator : *cars)
		{
			if (i == index)
				return &carIterator.second;
			i++;
		}
		return nullptr;
	}

	map<int, YB_Car>*		YB_CarManager::ListCars()
	{
		return YB_ManagerBasis<YB_Car>::GetAll();
	}
}
