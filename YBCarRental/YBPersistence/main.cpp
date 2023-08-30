#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int extractIndex(string line)
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

int main()
{
	map<int, string> allRecordLines = {};

	ifstream input("E:/YB800ProSE/YBCarRental/YBCarRental/YBCar_Native_Testing/CarRepo.txt");
	if (!input.is_open())
	{
		cout << "The file is not opened!" << endl;
	}
	string line, cachedline;
	//clear the cache
	if (!allRecordLines.empty()) allRecordLines.clear();
	while (std::getline(input, line)) {

		if (line.back() == '&') {				//check if ended with a '&'
			line.erase(line.length() - 1);
			cachedline = cachedline.append(line);
			continue;
		}
		else {
			if (cachedline.empty()) cachedline = line;

			int index = extractIndex(cachedline);
			if (index > 0) {
				// Add the line to the map using the index as the key
				allRecordLines[index] = cachedline;
			}
			cachedline = "";
		}
	}
	input.close();

}
