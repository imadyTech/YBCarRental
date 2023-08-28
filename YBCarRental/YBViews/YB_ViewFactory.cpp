#include "YB_ViewFactory.h"

namespace YBConsoleViews
{

	std::unique_ptr<YB_ViewBasis> YB_ViewFactory::CreateProduct(const string serializeString)
	{
		YB_ViewBasis* basePtr = new YB_ViewBasis();
		basePtr->Deserialize(serializeString);

		string type = basePtr->ViewType;
		if (type == "MenuView") {
			return std::make_unique<MenuView>();
		}
		if (type == "WelcomeView") {
			return std::make_unique<WelcomeView>();
		}
		if (type == "InputView") {
			return std::make_unique<InputView>();
		}
		if (type == "DialogView") {
			return std::make_unique<DialogView>();
		}
		if (type == "ListView") {
			return std::make_unique<ListView>();
		}
		if (type == "DetailsView") {
			return std::make_unique<DetailsView>();
		}
		return nullptr;
	}
}