#include "YB_RentManager.h"


namespace YBCarRental
{
	//YB_RentManager::YB_RentManager()
	//{
	//}
	bool YB_RentManager::PlaceOrder(int userId, int carId, tm startDate, int days)
	{
		time_t rawtime;
		struct tm* today{};
		localtime_s(today, &rawtime);


		YB_Rent* order = new YB_Rent();
		order->UserId		= userId;
		order->CarId		= carId;
		order->RentStart	= startDate;
		order->RentDays		= days;
		order->DateOfOrder	= *today;
		order->Status		= YB_Rental_Status_Pending;
		order->Id			= YB_ManagerBasis::CreateIncrementId();

		persistor->Add(*order);
		return true;
	}
	bool YB_RentManager::ApproveOrder(YB_Rent* rentalOrder)
	{
		if (!rentalOrder || rentalOrder->Status!= YB_Rental_Status_Pending) return false;
		try
		{
			rentalOrder->Status = YB_Rental_Status_Approved;
			YB_ManagerBasis::Update(*rentalOrder);
			return true;
		}
		catch (exception e) {
			return false;
		}
	}
	bool YB_RentManager::RejectOrder(YB_Rent* rentalOrder)
	{
		if (!rentalOrder || rentalOrder->Status!= YB_Rental_Status_Pending) return false;
		try
		{
			rentalOrder->Status = YB_Rental_Status_Rejected;
			YB_ManagerBasis::Update(*rentalOrder);
			return true;
		}
		catch (exception e) {
			return false;
		}
	}
	bool YB_RentManager::ApproveOrder(int orderId)
	{
		auto orderPtr = YB_ManagerBasis::Get(orderId);

		return this->ApproveOrder(orderPtr);
	}
	bool YB_RentManager::RejectOrder(int orderId)
	{
		auto orderPtr = YB_ManagerBasis::Get(orderId);

		return this->RejectOrder(orderPtr);
	}
}