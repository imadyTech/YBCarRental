#ifndef YB_Repository_H
#define YB_Repository_H


#include <iostream>
#include <fstream>
#include <string>
#include <format>
#include <map>
#include <sstream>

using namespace std;


namespace YBCarRental
{
	/// <summary>
	/// Text stream orientated layer of data persistence.
	/// </summary>
	class YB_Repository
	{
	public:
		YB_Repository();
		YB_Repository(string url);
		~YB_Repository();

		void ReadAllLines();
		string* GetLine(int index);
		void AddLine(string line);
		void DeleteLine(string line);
		void UpdateLine(string line);
		void ClearAll();


	private:
		string repositoryURL="";

		/// <summary>
		/// a TData record is serielized to a string and here caches all the records strings.
		/// </summary>
		map<int, string> allRecordLines = {};


		//ifstream input;//C2280 error: ifstream defined but not instantiated result to C2280
		//ofstream output;
	};
}

#endif YB_Repository_H