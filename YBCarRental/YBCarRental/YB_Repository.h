#include <iostream>
#include <fstream>
#include <string>
#include <format>
#include <map>

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

		map<int, string> ReadAllLines();
		void AddLine(string line);
		void DeleteLine(string line);
		void UpdateLine(string line);
		void ClearAll();
	private:
		string repositoryURL;
	};
}