#include "YB_ViewFactory.h"
#include "YB_LoginView.h"


namespace YBConsoleViews
{


	std::unique_ptr<YB_ViewBasis> YB_ViewFactory::CreateProduct(string viewType)
	{
		if (viewType == "MenuView") return std::make_unique<YB_LoginView>();
		if (viewType == "InputView") return std::make_unique<YB_LoginView>();
		if (viewType == "DetailsView") return std::make_unique<YB_LoginView>();
		if (viewType == "LoginView") return std::make_unique<YB_LoginView>();
		if (viewType == "WelcomeView") return std::make_unique<YB_LoginView>();
		if (viewType == "ListView") return std::make_unique<YB_LoginView>();
		if (viewType == "DialogView") return std::make_unique<YB_LoginView>();
		return nullptr;
	}
}