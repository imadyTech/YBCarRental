#ifndef YB_DataBasis_H
#define YB_DataBasis_H
#include <string>
#include <map>
#include <sstream>

using namespace std;


namespace YBPersistence
{
	enum YB_RentalStatus { pending = 0, approved = 1, rejected = 2, completed = 3 };
	enum YB_UserRole { User = 0, Admin = 1 };

	class YB_DataBasis
	{
	public:
		YB_DataBasis();
		virtual ~YB_DataBasis() {};

		int Id;


		/// <summary>
		/// Serielize the object to a line of string (implemented by derived classes)
		/// </summary>
		/// <returns></returns>
		virtual string* Serialize();

		/// <summary>
		/// Serielize the object to a line of string (for data persistence)
		/// </summary>
		/// <returns></returns>
		//virtual void Serialize(ofstream* output);

		/// <summary>
		/// Deserieliazation from string
		/// </summary>
		/// <param name="line"></param>
		/// <returns></returns>
		virtual void Deserialize(std::string line, const char* separator);

	protected:
		/// <summary>
		/// Reuseable code to split a string with a spliter (1st level: ';' 2nd level '!')
		/// </summary>
		/// <param name="line">for 2nd level sub items, you must use '!' as separator, NOT ';'.</param>
		/// <returns></returns>
		map<std::string, std::string>* SplitLine(std::string* line, const char* separator)
		{
			if (!stringPairsMap.empty())	//if the map is not empty, then very likely it was resued so you need clean.
				stringPairsMap.clear();

			std::istringstream strStream(*line);
			std::string pairedWord;

			while (std::getline(strStream, pairedWord, *separator)) {
				stringPairsMap.insert(*SplitToPair(&pairedWord));
			}
			return &stringPairsMap;
		};

		pair<string, string>* SplitToPair(std::string* line) {

			size_t colonPos = (*line).find(':');
			if (colonPos != std::string::npos) {
				string key = (*line).substr(0, colonPos);
				string value = (*line).substr(colonPos + 1);
				std::pair<string, string> pair(key, value);
				return &pair;
			}
			else
				return nullptr;
		}

		std::string* FindValue(std::string key)
		{
			auto iterator = stringPairsMap.find(key);
			std::string* value=nullptr;

			if (iterator != stringPairsMap.end()) {
				*value = iterator->second;
			}
			else
				value = nullptr;
			return value;
		}
	private:
		/// <summary>
		/// cached key/value map, pls be cautious when resusing
		/// </summary>
		std::map<std::string, std::string> stringPairsMap;

	};
}
#endif // YB_DataBasis_H