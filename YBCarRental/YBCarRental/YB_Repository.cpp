#include "YB_Repository.h"

namespace YBCarRental
{
	/// <summary>
	/// Text stream orientated layer of data persistence.
	/// </summary>
	YB_Repository::YB_Repository()
	{

	}
	YB_Repository::YB_Repository(string url)
	{
		ifstream input(url);
		if (!input.is_open())
		{
			cout << "The file is not opened!" << endl;
			//throw std::runtime_error("The file is not opened!");
		}
		string line;
		while (getline(input, line)) {
			cout << line << endl;
		}
		input.close();


	}

	YB_Repository::~YB_Repository()
	{
		//output.close();
	}

	map<int, string> YB_Repository::ReadAllLines()
	{
		return map<int, string>();
	}

	void YB_Repository::AddLine(string line)
	{

	}

	void YB_Repository::DeleteLine(string line)
	{
	}

	void YB_Repository::UpdateLine(string line)
	{
	}

	void YB_Repository::ClearAll()
	{
	}

}