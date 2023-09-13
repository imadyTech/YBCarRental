#ifndef YB_ManagerBasis_H
#define YB_ManagerBasis_H
#define _HAS_STD_BYTE 0
#include "YB_DataBasis.h"
#include "YB_PersistorBasis.h"
#include "YB_Errors.h"
using namespace YBPersistence;

namespace YBCarRental
{
	template <class TData = YB_DataBasis>
	class YB_ManagerBasis
	{
	public:
		YB_ManagerBasis(void)
		{
		}
		YB_ManagerBasis(string url) :YB_ManagerBasis()
		{

			//instantiate a persistor based on the url passed in.
			persistor = new YB_PersistorBasis<TData>(url);
		}

		/// <summary>
		/// Load and instantiate all view definitions from persistence.
		/// </summary>
		virtual void									LoadAll();

		/// <summary>
		/// Add a data record to the persistent repository
		/// </summary>
		/// <param name="data"></param>
		virtual bool									Add(TData data);

		/// <summary>
		/// Return an object from memory
		/// </summary>
		/// <param name="id"></param>
		/// <returns></returns>
		virtual TData*									Get(int id);

		virtual map<int, TData>*						GetAll();

		/// <summary>
		/// Delete an object from memory (will persisted later by Save() command.
		/// </summary>
		/// <param name="id"></param>
		/// <returns></returns>
		virtual bool									Delete(int id);

		/// <summary>
		/// Update an object from memory (will persisted later by Save() command.
		/// </summary>
		/// <param name="data"></param>
		/// <returns></returns>
		virtual bool									Update(TData data);

	protected:
		/// <summary>
		/// The persistor to manage TData objects at lower-layer .
		/// </summary>
		YB_PersistorBasis<TData>*						persistor;
		/// <summary>
		/// Create unique Id by iterating existing repo
		/// </summary>
		int												CreateIncrementId();

		///dictionary of id:object pair
		//map<int, TData> dataSet;
	};

	template<class TData>
	inline void									YB_ManagerBasis<TData>::LoadAll()
	{
		persistor->LoadAll();
	}

	template<class TData>
	inline TData*								YB_ManagerBasis<TData>::Get(int id)
	{
		return persistor->Get(id);
	}

	template<class TData>
	map<int, TData>*							YB_ManagerBasis<TData>::GetAll()
	{
		return persistor->GetAll();
	}

	template<class TData>
	inline bool									YB_ManagerBasis<TData>::Add(TData data)
	{
		try {
			persistor->Add(data);
			return true;
		}
		catch (exception e)
		{
			throw YB_PersistorError();
		}
	}

	template<class TData>
	inline bool									YB_ManagerBasis<TData>::Delete(int id)
	{
		try {
			return persistor->Delete(id);
		}
		catch (exception e)
		{
			throw YB_PersistorError();
		}
	}

	template<class TData>
	inline bool									YB_ManagerBasis<TData>::Update(TData data)
	{
		try {
			return persistor->Update(data);
		}
		catch (exception e)
		{
			throw YB_PersistorError();
		}
	}

	template<class TData>
	inline int									YB_ManagerBasis<TData>::CreateIncrementId()
	{
		if (!(&persistor->dataSet) || persistor->dataSet.size() == 0)
			return -1;
		int max = -1;
		for (auto& orderIterator : persistor->dataSet)
		{
			if (orderIterator.second.Id > max)
				max = orderIterator.second.Id;
		}
		return max+1;
	};

}
#endif // YB_ManagerBasis_H
