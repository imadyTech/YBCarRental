#ifndef YB_Rent_H
#define YB_Rent_H

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
		int RentDays;			//total days of rental
		string Status;	//

		string* Serialize() override;
		void Serialize(ofstream* output) override;
		void Deserialize(string line) override;

	};

}

#endif
