#ifndef YB_TextViewItem_H
#define YB_TextViewItem_H

#include "YB_DataBasis.h"
#include "YB_ViewBasis.h"

using namespace YBPersistence;

namespace YBConsoleViews
{
	class YB_LoginView : public YBConsoleViews::YB_ViewBasis
	//class YB_LoginView : public YBPersistence::YB_DataBasis, protected YBConsoleViews::YB_ViewBasis
		//YB_DataBasis: allows the view to access persistence layer.
		//YB_ViewBasis: allows the view to inherit view layer properties and methods.
	{
	public:
		string* Serialize() override
		{
			return nullptr;
		};
		void Serialize(std::stringstream& strStream) override {};
		void Deserialize(string line, const char* separator) override {};


	};

}

#endif // YB_TextViewItem_H