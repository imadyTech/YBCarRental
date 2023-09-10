#include "YB_ListHead.h"
#include "YB_ViewFactory.h"


const char		separator = '|';

void YBConsoleViews::YB_ListHead::OnReturn()
{
}

std::vector<char*> YBConsoleViews::YB_ListHead::Render()
{
	if (isHidden) {
		return YB_ViewItemBasis::viewArray;
	}

	YB_ViewItemBasis::Render();							//for listhead, only the background will be rendered

	int				posIndex = 3;
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

		if (posY <= h)
		{
			// Fill head title
			memcpy(viewArray[posY] + posX, content, contentLength);
			// Draw table col separator
			memcpy(viewArray[posY] + posIndex + gridWidth, &separator, 1);
		}
		// Move to next col
		posIndex += gridWidth;
	}
	return YB_ViewItemBasis::viewArray;
}
