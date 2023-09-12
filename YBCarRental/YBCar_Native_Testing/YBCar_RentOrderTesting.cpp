#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include "pch.h"
#include "CppUnitTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace YBCarRental;

namespace YBCarTesting
{
	TEST_CLASS(YBCar_RentOrderTesting)
	{
	public:
		TEST_METHOD(YB_Rent_SerializeTest)
		{
			std::time_t currentTime = std::time(nullptr);
			tm* date = std::localtime(&currentTime);
			YB_Rent* order = new YB_Rent();
			order->Id = 0001;
			order->UserId = 15;
			order->CarId = 1000;
			order->RentStart = *date;
			order->DateOfOrder = *date;
			order->RentDays = 5;
			order->Status = YB_Rental_Status_Pending;
			Logger::WriteMessage(order->Serialize()->c_str());;
		}
		TEST_METHOD(YB_Rent_DeSerializeTest)
		{
			YB_Rent* order = new YB_Rent();
			order->Deserialize("Id:001;UserId:15;CarId:1000;RentStart:2023-09-12;DateOfOrder:2023-09-12;RentDays:5;Status:pending;");

			std::time_t currentTime = std::time(nullptr);
			tm* date = std::localtime(&currentTime);
			//Assert::AreEqual(order->DateOfOrder, *date);

			Logger::WriteMessage((to_string(order->RentStart.tm_year)).c_str());
			Logger::WriteMessage((to_string(order->RentStart.tm_mon)).c_str());
			Logger::WriteMessage((to_string(order->RentStart.tm_mday)).c_str());
			Logger::WriteMessage((to_string(order->UserId)).c_str());
			Logger::WriteMessage((to_string(order->CarId)).c_str());

		}
	};
}

//enum YB_RentalStatus { pending = 0, approved = 1, rejected = 2, completed = 3 };
