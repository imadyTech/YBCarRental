#include "YB_InputItem.h"

void YBConsoleViews::YB_InputItem::OnKey(int* keycode)
{
	if ((*keycode >= 65 && *keycode <= 90)					//Alphabet(Upper/Lower) and numbers
		|| (*keycode >= 48 && *keycode <= 57)
		|| (*keycode >= 97 && *keycode <= 122))
	{
		this->Content += *keycode;
	}
}

void YBConsoleViews::YB_InputItem::OnBackspace()
{
	auto length = this->Content.size();
	if (!this->Content.empty())
		this->Content.erase(length - 1);
}

void YBConsoleViews::YB_InputItem::OnBind(string* contents)
{
	//DO NOT INVOKE BASE FUNCTION
	//inputItem allows bind a nullptr content (e.g. register a new user), and differ from other items
	if (contents != nullptr)
		this->Content = *contents;
	else
		this->Content = "";
}

void YBConsoleViews::YB_InputItem::OnReturn()
{
	//DO NOT DELETE THIS EMPTY FUNCTION
	//InputItem won't response Return key
	//Nothing here - Delibrately leave blank code to override base action
}

std::vector<char*> YBConsoleViews::YB_InputItem::Render()
{
	return YB_ViewItemBasis::Render();
}
