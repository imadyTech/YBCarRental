#pragma once
#include <stdexcept>

namespace YBCarRental
{
	/// <summary>
	/// define a base struct of custom erros -- to make life easier
	/// </summary>
	struct YB_ErrorBasis : public std::exception
	{
	public:
		virtual const char* what() const noexcept {
			return message;
		}

	protected:
		YB_ErrorBasis(const char* message) : message(message) {}
		const char* message;
	};

	//------------------------Inherited custom error types------------------------
	struct YB_RepositoryError : YB_ErrorBasis
	{
	public:
		YB_RepositoryError() : YB_ErrorBasis("YB_RepositoryError") {}
	};	
	
	struct YB_SerializeError : YB_ErrorBasis
	{
	public:
		YB_SerializeError() : YB_ErrorBasis("YB_SerializeError") {}
	};
	
	struct YB_DeSerializeError : YB_ErrorBasis
	{
	public:
		YB_DeSerializeError() : YB_ErrorBasis("YB_DeSerializeError") {}
	};

	struct YB_PersistorError : YB_ErrorBasis
	{
	public:
		YB_PersistorError() : YB_ErrorBasis("YB_PersistorError") {}
	};

	struct YB_ManagerLogicError : YB_ErrorBasis
	{
	public:
		YB_ManagerLogicError() : YB_ErrorBasis("YB_ManagerLogicError") {}
	};

	struct YB_ViewError : YB_ErrorBasis
	{
	public:
		YB_ViewError() : YB_ErrorBasis("YB_ViewError") {}
	};

	struct YB_DataModelError : YB_ErrorBasis
	{
	public:
		YB_DataModelError() : YB_ErrorBasis("YB_DataModelError") {}
	};

}