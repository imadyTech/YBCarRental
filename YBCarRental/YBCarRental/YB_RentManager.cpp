#include "YB_RentManager.h"


namespace YBCarRental
{
	//YB_RentManager::YB_RentManager()
	//{
	//}
	bool YB_RentManager::PlaceOrder(int userId, int carId, tm startDate, int days)
	{
		std::time_t currentTime = std::time(nullptr);
		tm* today				= std::localtime(&currentTime);

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
	bool YB_RentManager::ApproveOrder(YB_Rent rentalOrder)
	{
		return false;
	}
	bool YB_RentManager::RejectOrder(YB_Rent rentalOrder)
	{
		return false;
	}
	bool YB_RentManager::ApproveOrder(int orderId)
	{
		return false;
	}
	bool YB_RentManager::RejectOrder(int orderId)
	{
		return false;
	}
}