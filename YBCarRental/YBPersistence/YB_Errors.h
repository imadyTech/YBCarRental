#pragma once
#include <stdexcept>
#include <string>
using namespace std;

namespace YBPersistence
{
	/// <summary>
	/// define a base struct of custom erros -- to make life easier
	/// </summary>
	struct YB_ErrorBasis : public std::exception
	{
	public:
		virtual const char* what() const noexcept {
			return msg;
		}

		//With this operator Functor you can:
		//try {
		//}
		//catch (exception e) {
		//	YB_BindingError error;
		//	error(const_cast<char*>("custom error"));
		//	throw error;
		//}
		void operator()(char* message)  {
			YB_ErrorBasis::msg = message;
		}

	protected:
		YB_ErrorBasis(const char* msg) : msg(const_cast<char*> (msg)) {}
		const char* msg;
	};

	//------------------------Repository custom error types------------------------
	struct YB_RepositoryError : YB_ErrorBasis
	{
	public:
		YB_RepositoryError() : YB_ErrorBasis("YB_RepositoryError") {}
	};	
	
	struct YB_RepoRecordExistedError : YB_ErrorBasis
	{
	public:
		YB_RepoRecordExistedError() : YB_ErrorBasis("YB_Repo:Record Already Existed.") {}
	};	
	
	struct YB_RepoRecordNotExistedError : YB_ErrorBasis
	{
	public:
		YB_RepoRecordNotExistedError() : YB_ErrorBasis("YB_Repo:Record Does Not Existed.") {}
	};	
	

	//------------------------Datamodels custom error types------------------------
	struct YB_DataModelError : YB_ErrorBasis
	{
	public:
		YB_DataModelError() : YB_ErrorBasis("YB_DataModelError") {}
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

	struct YB_BindingError : YB_ErrorBasis
	{
	public:
		YB_BindingError() : YB_ErrorBasis("YB_BindingError") {}
	};

	struct YB_ReverseBindingError : YB_ErrorBasis
	{
	public:
		YB_ReverseBindingError( ) : YB_ErrorBasis("YB_ReverseBindingError") {}
	};



	struct YB_PersistorError : YB_ErrorBasis
	{
	public:
		YB_PersistorError() : YB_ErrorBasis("YB_PersistorError") {}
	};	

	struct YB_FactoryError : YB_ErrorBasis
	{
	public:
		YB_FactoryError() : YB_ErrorBasis("YB_FactoryError") {}
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

}