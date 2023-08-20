#ifndef YB_DataBasis_H
#define YB_DataBasis_H



#include <string>
#pragma once

using namespace std;


namespace YBCarRental
{
	enum YB_RentalStatus { pending = 0, approved = 1, rejected = 2, completed = 3 };
	enum YB_UserRole { User = 0, Admin = 1 };

	class YB_DataBasis
	{
	public:
		YB_DataBasis();

		virtual string* Serialize();


		/// <summary>
		/// Serielize the object to a line of string (for data persistence)
		/// </summary>
		/// <returns></returns>
		virtual void Serialize(ofstream* output);

		/// <summary>
		/// Deserieliazation from string
		/// </summary>
		/// <param name="line"></param>
		/// <returns></returns>
		virtual void Deserialize(std::string line);


		virtual ~YB_DataBasis() {}
	};

}

#endif YB_DataBasis_H