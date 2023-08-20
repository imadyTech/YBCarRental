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
		repositoryURL = url;

	}

	YB_Repository::~YB_Repository()
	{
		//output.close();
	}

	void YB_Repository::ReadAllLines()
	{
		//clear the cache
		if (!allRecordLines.empty()) allRecordLines.clear();

		ifstream input(repositoryURL);
		if (!input.is_open())
		{
			cout << "The file is not opened!" << endl;
			//throw std::runtime_error("The file is not opened!");
		}
		string line;
		while (std::getline(input, line)) {
			int index; // Variable to hold the extracted index
			std::istringstream stringStream(line);
			// Extract the index from the line
			if (stringStream >> index) {
				// Add the line to the map using the index as the key
				allRecordLines[index] = line;
			}
		}


		input.close();
	}

	string* YB_Repository::GetLine(int index)
	{
		auto ptr = allRecordLines.find(index);

		if (ptr != allRecordLines.end()) {
			return &(ptr->second);
		}
		else
			return nullptr;
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