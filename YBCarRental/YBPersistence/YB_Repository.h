#ifndef YB_Repository_H
#define YB_Repository_H


#include <iostream>
#include <fstream>
#include <string>
#include <format>
#include <map>
#include <sstream>

using namespace std;


namespace YBPersistence
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

		bool isReady = false;

		void ReadAllLines();
		string* GetLine(int index);
		int FindLine(string target);
		void AddLine(string line);
		void DeleteLine(int index);
		void UpdateLine(string line);
		void ClearAll();

		/// <summary>
		/// a TData record is serielized to a string and here caches all the records strings.
		/// Note: for simplicity reason, this data cache was designed to be exposed as public.
		/// </summary>
		map<int, string> allRecordLines = {};


	private:
		string repositoryURL="";

		int extractIndex(string line);
		void SaveAll();
	};
}

#endif YB_Repository_H