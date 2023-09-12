#ifndef YB_Rent_H
#define YB_Rent_H

#include <string>
#include "YB_DataBasis.h"
#include "YB_User.h"
#include "YB_Car.h"
#pragma once

using namespace std;
using namespace YBPersistence;


namespace YBCarRental
{
	static const char* YB_Rental_Status_Pending		= "pending";
	static const char* YB_Rental_Status_Approved	= "approved";
	static const char* YB_Rental_Status_Rejected	= "rejected";
	static const char* YB_Rental_Status_Completed	= "completed";

	/// <summary>
	/// The record of a rental order;
	/// </summary>
	class YB_Rent : public YB_DataBasis
	{
	public:
		YB_Rent();
		YB_Rent(YB_User user, YB_Car car, tm start, int days);
		YB_Rent(int userId, int carId, tm start, int days);
		~YB_Rent() override;

		int UserId;
		int CarId;
		tm RentStart;			//rental start date
		tm DateOfOrder;			//date placed order
		int RentDays;			//total days of rental
		string Status;			//

		string* Serialize() override;
		void Serialize(std::stringstream& strStream) override;
		//void Serialize(ofstream* output) override;
		void Deserialize(string line);
		void Deserialize(string line, const char* separator) override;

		//copy assignment operator 
		YB_Rent& operator=(const YB_Rent& other) {
			if (this != &other) {
				UserId = other.UserId;
				CarId = other.CarId;
				RentStart = other.RentStart;
				DateOfOrder = other.DateOfOrder;
				RentDays = other.RentDays;
				Status = other.Status;
				// Call parent class copy assignment operator
				YB_DataBasis::operator=(other);
			}
			return *this;
		}
	};

}

#endif
