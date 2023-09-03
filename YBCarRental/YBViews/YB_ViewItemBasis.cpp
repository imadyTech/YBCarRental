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


	string*						YB_ViewItemBasis::Serialize()
	{
		std::stringstream ss;
		//Redirect to new function (instead of previous version overrided function)
		this->Serialize(ss);

		serializedString = new std::string(ss.str());
		return serializedString;
	}
	void						YB_ViewItemBasis::Serialize(std::stringstream& strStream)
	{
		YB_DataBasis::Serialize(strStream);
		strStream
			<< "x:"				<< x			<< YB_DataBasis::persistentSeparator
			<< "y:"				<< y			<< YB_DataBasis::persistentSeparator
			<< "w:"				<< w			<< YB_DataBasis::persistentSeparator
			<< "h:"				<< h			<< YB_DataBasis::persistentSeparator
			<< "ItemType:"		<< ItemType		<< YB_DataBasis::persistentSeparator
			<< "Content:"		<< Content		<< YB_DataBasis::persistentSeparator
			<< "Bind:"			<< Bind			<< YB_DataBasis::persistentSeparator
			<< "Background:"	<< Background	<< YB_DataBasis::persistentSeparator
			<< "isCentral:"		<< isCentral	<< YB_DataBasis::persistentSeparator
			<< "isFocused:"		<< isFocused	<< YB_DataBasis::persistentSeparator
			<< "isSelected:"	<< isSelected	<< YB_DataBasis::persistentSeparator
			<< "isHidden:"		<< isHidden		<< YB_DataBasis::persistentSeparator;
	}
	void						YB_ViewItemBasis::Deserialize(string line)
	{
		this->Deserialize(line, &persistentSeparator);
	}
	void						YB_ViewItemBasis::Deserialize(string line, const char* separator)
	{
		YB_DataBasis::Deserialize(line, separator);

		if (YB_DataBasis::FindValue("x"))			x = std::stoi(*YB_DataBasis::FindValue("x"));
		if (YB_DataBasis::FindValue("y"))			y = std::stoi(*YB_DataBasis::FindValue("y"));
		if (YB_DataBasis::FindValue("w"))			w = std::stoi(*YB_DataBasis::FindValue("w"));
		if (YB_DataBasis::FindValue("h"))			h = std::stoi(*YB_DataBasis::FindValue("h"));
		if (YB_DataBasis::FindValue("Bind"))		Bind = *YB_DataBasis::FindValue("Bind");
		if (YB_DataBasis::FindValue("ItemType"))	ItemType = *YB_DataBasis::FindValue("ItemType");
		if (YB_DataBasis::FindValue("Content"))		Content = *YB_DataBasis::FindValue("Content");
		if (YB_DataBasis::FindValue("Background"))	Background = *YB_DataBasis::FindValue("Background")->c_str();
		if (YB_DataBasis::FindValue("isCentral"))	isCentral = *YB_DataBasis::FindValue("isCentral") == "1";
		if (YB_DataBasis::FindValue("isFocused"))	isFocused = *YB_DataBasis::FindValue("isFocused") == "1";
		if (YB_DataBasis::FindValue("isSelected"))	isSelected = *YB_DataBasis::FindValue("isSelected") == "1";
		if (YB_DataBasis::FindValue("isHidden"))	isHidden = *YB_DataBasis::FindValue("isHidden") == "1";
	}

	/// <summary>
	/// CAUTION: BASE.RENDER() ALWASY RENDER CONTENT.
	/// CONTROL isHidden/isFocused BEHAVIOUR IN DERIVED.RENDER().
	/// </summary>
	/// <returns></returns>
	vector<char*>				YB_ViewItemBasis::Render()			//Todo: better to return a pointer
	{
		if (this->isFocused)
			this->Fill_Background(this->Background);
		else
			this->Clear_Background();

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
		////Unit testing code - to visualize a single item
		//for (const char* strPtr : viewArray) {
		//	std::cout << strPtr << std::endl;
		//}
		////Unit testing code - to visualize a single item
		return YB_ViewItemBasis::viewArray;
	}
	void						YB_ViewItemBasis::Init_Background(char background)
	{
		//fill the view background with a char
		for (int i = 0; i < YB_ViewItemBasis::h; ++i) {
			char* newLine = new char[YB_ViewItemBasis::w + 1];
			std::memset(newLine, background, YB_ViewItemBasis::w);
			newLine[YB_ViewItemBasis::w] = '\0'; // Null-terminate the string
			YB_ViewItemBasis::viewArray.push_back(newLine);
		}
	}
	void						YB_ViewItemBasis::Fill_Background(char background)
	{
		//fill the view background with a char
		for (int i = 0; i < YB_ViewItemBasis::h; ++i) {
			std::memset(YB_ViewItemBasis::viewArray[i], background, YB_ViewItemBasis::w);
		}
	}
	void						YB_ViewItemBasis::Clear_Background()
	{
		//fill the view background with a char
		for (int i = 0; i < YB_ViewItemBasis::h; ++i) {
			std::memset(YB_ViewItemBasis::viewArray[i], ' ', YB_ViewItemBasis::w);
		}
	}
	void						YB_ViewItemBasis::OnFocus() {
		this->isFocused = true;
	}
	void						YB_ViewItemBasis::OnLostFocus() {
		this->isFocused = false;
	}
}