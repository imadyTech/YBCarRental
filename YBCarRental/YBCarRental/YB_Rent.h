#include <string>
#include "YB_DataBasis.h"
#include "YB_User.h"
#include "YB_Car.h"
#pragma once

using namespace std;


namespace YBCarRental
{
	/// <summary>
	/// The record of a rental order;
	/// </summary>
	class YB_Rent 
	{
	public:
		YB_Rent();
		YB_Rent(YB_User user, YB_Car car, tm start, int days);
		YB_Rent(int userId, int carId, tm start, int days);

		int ID;					//order id;
		int UserId;
		int CarId;
		tm RentStart;			//rental start date
		int RentDays;			//total days of rental
		YB_RentalStatus Status;	//


		 std::string Serialize() ;
		virtual void Deserialize(std::string line) ;
	};

}
