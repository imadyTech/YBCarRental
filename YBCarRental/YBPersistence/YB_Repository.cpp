#include "YB_Repository.h"
#include "YB_Errors.h"

namespace YBPersistence
{
	/// <summary>
	/// Cache all lines in the text file to a map<int, string> (allRecordLines)
	/// </summary>
	void YB_Repository::ReadAllLines()
	{
		ifstream input(repositoryURL);
		if (!input.is_open())
		{
			//cout << "The file is not opened!" << endl;
			isReady = false;
			throw YB_RepositoryError();
		}
		//clear the cache
		if (!allRecordLines.empty()) allRecordLines.clear();
		string line, cachedline;								//temp variables.
		while (std::getline(input, line)) {
			if (line.empty() && !cachedline.empty())			//ended with empty line
			{
				int index = extractIndex(cachedline);
				if (index > 0) {
					// Add the line to the map using the index as the key
					allRecordLines[index] = cachedline;
				}
				cachedline = "";
				continue;
			}
			else if (line.empty() && cachedline.empty())
			{
				break;
			}
			else {
				if (line.back() == this->lineBreakConnector)		//check if ended with a '&'
				{
					line.erase(line.length() - 1);
					cachedline = cachedline.append(line);
					continue;
				}
				else
				{
					cachedline = cachedline.append(line);
					continue;
				}
			}
		}
		isReady = true;
		input.close();
	}

	/// <summary>
	/// Get a line from the cache (NOT from the file!!!)
	/// </summary>
	/// <param name="index"></param>
	/// <returns></returns>
	string* YB_Repository::GetLine(int index)
	{
		if (!isReady)
			throw YB_RepositoryError();			//It is not allowed if never ReadAllLines().

		if (allRecordLines.empty())
			ReadAllLines();

		auto pairValue = allRecordLines.find(index);

		if (pairValue != allRecordLines.end()) {
			return &(pairValue->second);
		}
		else
			return nullptr;
	}

	/// <summary>
	/// search a ine includes the target, and return the integer Id.
	/// </summary>
	/// <param name="target"></param>
	/// <returns></returns>
	int YB_Repository::FindLine(string target)
	{
		if (!isReady)
			throw YB_RepositoryError();			//It is not allowed if never ReadAllLines().

		if (allRecordLines.empty())
			ReadAllLines();

		for (const auto& pairValue : allRecordLines)
		{
			if (pairValue.second.find(target) != std::string::npos) {
				return pairValue.first;
			}
		}
		return -1;
	}

	void YB_Repository::AddLine(string line)
	{
		int index = extractIndex(line);
		string* ptr = this->GetLine(index);
		if (ptr != nullptr)
			throw YB_RepoRecordExistedError();				//a line with identical index already exist in the file.

		allRecordLines.insert(std::make_pair(index, line)); //cache in the map
		this->SaveAll();									//persist to file
	}

	void YB_Repository::DeleteLine(int index)
	{
		string* ptr = this->GetLine(index);
		if (ptr == nullptr)
			throw YB_RepoRecordNotExistedError();			//no such record to delete
		else
		{
			map<int, string>::iterator record = allRecordLines.find(index);
			allRecordLines.erase(record);					//remove from cache
			this->SaveAll();								//persist to file
		}
	}

	void YB_Repository::UpdateLine(string line)
	{
		int index = extractIndex(line);
		string* ptr = this->GetLine(index);
		if (ptr == nullptr)
			throw YB_RepoRecordNotExistedError();			//no such record to update
		else
		{
			map<int, string>::iterator record = allRecordLines.find(index);
			record->second = line;							//update cache
			this->SaveAll();								//persist to file
		}
	}

	void YB_Repository::ClearAll()
	{
		if (!isReady)
			throw YB_RepositoryError();

		allRecordLines.clear();
		this->SaveAll();
	}

	//----------utility code//----------

	/// <summary>
	/// Extract the index from the line (1st word)
	/// </summary>
	/// <param name="line"></param>
	/// <returns></returns>
	int YB_Repository::extractIndex(string line)
	{
		int index = -1;
		size_t colonPos = line.find(":");

		if (colonPos != std::string::npos && colonPos < line.size() - 1) {
			std::string idStr = line.substr(colonPos + 1);
			std::istringstream stringStream(idStr);

			if (stringStream >> index) {
				return index;
			}
		}
		return -1;
	}

	void YB_Repository::SaveAll()
	{
		ofstream output(repositoryURL);
		if (!output.is_open()) {
			throw YB_RepositoryError();			//file open error
		}
		else
		{
			for (const auto& pair : allRecordLines) {
				output << pair.second << endl;
			}
			output.close();
		}
	}
}