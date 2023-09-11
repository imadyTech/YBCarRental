#include "YB_ListHead.h"
#include "YB_ViewFactory.h"


const char		separator = '|';

void YBConsoleViews::YB_ListHead::Deserialize(string contents)
{
	YB_ViewItemBasis::Deserialize(contents);


	//Todo: this job should be done in Init (need add Init() to viewItems)
	int	posIndex = 3;
	char* formattedContent = new char[this->w];
	std::memset(formattedContent, ' ', w);
	formattedContent[this->w] = '\0';

	for (const auto& iterator : this->stringPairsMap)
	{
		//Hard protocol, ListHead item start with <col>
		size_t headStartPos = iterator.first.find(CONST_LIST_HEAD_STARTER);
		if (headStartPos == string::npos)
			continue;

		const char* content = iterator.first.c_str();
		content += CONST_VIEW_ITEM_STARTER_LENGTH;

		size_t contentLength = strlen(content);
		size_t gridWidth = std::stoi(iterator.second);
		size_t posX = isCentral ? posIndex + gridWidth / 2 - contentLength / 2 : posIndex;
		size_t posY = h / 2;
		//cache for listItem rendering
		std::pair<string, int>* newPair = new std::pair<string, int>(content, gridWidth);
		tableRowFormatter->push_back(newPair);

		if (posY <= h)
		{
			// Fill head title
			memcpy(formattedContent + posX, content, contentLength);
			// Draw table col separator
			memcpy(formattedContent + posIndex + gridWidth, &separator, 1);
		}
		// Move to next col
		posIndex += gridWidth;
	}
	this->Content = std::string(formattedContent);
}

void YBConsoleViews::YB_ListHead::OnReturn()
{
}

std::vector<char*> YBConsoleViews::YB_ListHead::Render()
{

	return YB_ViewItemBasis::Render();
}
