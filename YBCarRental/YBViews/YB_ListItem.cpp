#include "YB_ListItem.h"
#include "YB_ViewFactory.h"

void YBConsoleViews::YB_ListItem::OnBind(string* contents)
{
	if (contents)
		this->Content = *contents;
}


void YBConsoleViews::YB_ListItem::OnBind(vector<tuple<string, string, int>*>* valueFormatter)
{
	this->row = valueFormatter;

	int	posIndex = 3;
	const char separator = '|';
	char* formattedContent = new char[this->w];
	std::memset(formattedContent, ' ', w);
	formattedContent[this->w] = '\0';
	for (const auto& iterator : *row)
	{
		const char* content		= std::get<1>(*iterator).c_str();
		size_t contentLength	= strlen(content);
		size_t gridWidth		= std::get<2>(*iterator);
		size_t posX				= isCentral ? posIndex + gridWidth / 2 - contentLength / 2 : posIndex;
		size_t posY				= h / 2;
		if (h > 0)
		{
			// Fill item
			memcpy(formattedContent + posX, content, contentLength);
			// Draw table col separator
			memcpy(formattedContent + posIndex + gridWidth, &separator, 1);
		}
		// Move to next col
		posIndex += gridWidth;
	}
	this->Content = std::string(formattedContent);
}



void YBConsoleViews::YB_ListItem::OnReturn()
{
	YB_ListItemMessage* Message = new YB_ListItemMessage(std::stoi(this->Bind));
	this->parent->OnChildReturn(Message, this);
}

std::vector<char*> YBConsoleViews::YB_ListItem::Render()
{
	YB_ViewItemBasis::Render();
	YB_ViewItemBasis::RenderFocus("*>");
	return YB_ViewItemBasis::viewArray;
}
