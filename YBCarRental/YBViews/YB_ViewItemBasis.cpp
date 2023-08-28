#pragma once
#include <vector>
#include <iostream>
#include "YB_ViewItemBasis.h"

using namespace std;
namespace YBConsoleViews {


	YB_ViewItemBasis::YB_ViewItemBasis() : YB_DataBasis::YB_DataBasis()
	{
		this->persistentSeparator = '!';								//Arbitrate declaration of the persistence separator;
	}

	YB_ViewItemBasis::YB_ViewItemBasis(int width, int height) : YB_ViewItemBasis::YB_ViewItemBasis()
	{
		this->w = width;
		this->h = height;
	}

	YB_ViewItemBasis::~YB_ViewItemBasis()
	{
		//for (char* ptr : viewArray) {
		//	delete[] ptr;
		//}
		//this->viewArray.clear();
	};



	vector<char*> YB_ViewItemBasis::Render()
	{
		if (!isHidden) {
			if (isFocused)
				FillBackground(this->Background);
			else
				ClearBackground();

			// Calculate the position of content
			const char* content = Content.c_str();
			size_t newContentLength = strlen(content);
			size_t posX = isCentral ? w / 2 - newContentLength / 2 : 3;
			size_t posY = h / 2;

			// Calculate the remaining length of the original content
			if (posY <= h)
			{
				size_t remainingLength = strlen(viewArray[posY]) - posX;
				memcpy(viewArray[posY] + posX, content, newContentLength);
			}

			for (const char* strPtr : viewArray) {
				std::cout << strPtr << std::endl;
			}
		}
		return YB_ViewItemBasis::viewArray;
	}

	void YB_ViewItemBasis::OnKey(char* keycode)
	{
	}

	void YB_ViewItemBasis::OnSelect()
	{
	}

	void YB_ViewItemBasis::OnReturn()
	{
	}

	string* YB_ViewItemBasis::Serialize()
	{
		std::stringstream ss;
		//Redirect to new function (instead of previous version overrided function)
		this->Serialize(ss);

		std::string* serializedString = new std::string(ss.str());
		return serializedString;
	}

	void YB_ViewItemBasis::Serialize(std::stringstream& strStream)
	{
		YB_DataBasis::Serialize(strStream);
		strStream
			<< "x:" << x << YB_DataBasis::persistentSeparator
			<< "y:" << y << YB_DataBasis::persistentSeparator
			<< "w:" << w << YB_DataBasis::persistentSeparator
			<< "h:" << h << YB_DataBasis::persistentSeparator
			<< "ItemType:" << ItemType << YB_DataBasis::persistentSeparator
			<< "Content:" << Content << YB_DataBasis::persistentSeparator
			<< "Background:" << Background << YB_DataBasis::persistentSeparator
			<< "isCentral:" << isCentral << YB_DataBasis::persistentSeparator
			<< "isFocused:" << isFocused << YB_DataBasis::persistentSeparator
			<< "isSelected:" << isSelected << YB_DataBasis::persistentSeparator
			<< "isHidden:" << isHidden << YB_DataBasis::persistentSeparator;
	}

	void YB_ViewItemBasis::Deserialize(string line)
	{
		this->Deserialize(line, &persistentSeparator);
	}

	void YB_ViewItemBasis::Deserialize(string line, const char* separator)
	{
		YB_DataBasis::Deserialize(line, separator);

		x = std::stoi(*YB_DataBasis::FindValue("x"));
		y = std::stoi(*YB_DataBasis::FindValue("y"));
		w = std::stoi(*YB_DataBasis::FindValue("w"));
		h = std::stoi(*YB_DataBasis::FindValue("h"));
		ItemType = *YB_DataBasis::FindValue("ItemType");
		Content = *YB_DataBasis::FindValue("Content");
		Background = *YB_DataBasis::FindValue("Background")->c_str();
		isCentral = *YB_DataBasis::FindValue("isCentral") == "1";
		isFocused = *YB_DataBasis::FindValue("isFocused") == "1";
		isSelected = *YB_DataBasis::FindValue("isSelected") == "1";
		isHidden = *YB_DataBasis::FindValue("isHidden") == "1";
	}

	void YB_ViewItemBasis::InitBackground(char background)
	{
		//fill the view background with a char
		for (int i = 0; i < YB_ViewItemBasis::h; ++i) {
			char* newLine = new char[YB_ViewItemBasis::w + 1];
			std::memset(newLine, background, YB_ViewItemBasis::w);
			newLine[YB_ViewItemBasis::w] = '\0'; // Null-terminate the string
			YB_ViewItemBasis::viewArray.push_back(newLine);
		}
	}
	void YB_ViewItemBasis::FillBackground(char background)
	{
		//fill the view background with a char
		for (int i = 0; i < YB_ViewItemBasis::h; ++i) {
			std::memset(YB_ViewItemBasis::viewArray[i], background, YB_ViewItemBasis::w);
		}
	}
	void YB_ViewItemBasis::ClearBackground()
	{
		//fill the view background with a char
		for (int i = 0; i < YB_ViewItemBasis::h; ++i) {
			std::memset(YB_ViewItemBasis::viewArray[i], ' ', YB_ViewItemBasis::w);
		}
	}
}