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
		/// <summary>
		/// Text stream orientated layer of data persistence.
		/// </summary>
		YB_Repository()
		{
			isReady = false;								//the persistence file is not verified yet, NOT ready.
		}
		YB_Repository(string url) : YB_Repository()
		{
			repositoryURL = url;
			ReadAllLines();
		}
		~YB_Repository()
		{
			//delete &allRecordLines;						//clear the allocated memory
		}

		bool								isReady = false; //status indicator
		void								ReadAllLines();
		string*								GetLine(int index);
		int									FindLine(string target);
		void								AddLine(string line);
		void								DeleteLine(int index);
		void								UpdateLine(string line);
		void								ClearAll();

		/// <summary>
		/// a TData record is serielized to a string and here caches all the records strings.
		/// Note: for simplicity reason, this data cache was designed to be exposed as public.
		/// </summary>
		map<int, string>					allRecordLines = {};
		string								repositoryURL="";


	private:
		const char							lineBreakConnector = '&'; //if a line in the repo file is ended with '&', then the next line will be concatenated.

		int									extractIndex(string line);
		void								SaveAll();
	};
}

#endif YB_Repository_H