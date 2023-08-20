#ifndef YB_ManagerBasis_H
#define YB_ManagerBasis_H

#include "YB_DataBasis.h"
#include "YB_PersistorBasis.h"
#include "YB_Errors.h"

namespace YBCarRental
{
	template <class TData = YB_DataBasis>
	class YB_ManagerBasis
	{

	public:
		YB_ManagerBasis(void);
		YB_ManagerBasis(string url);

	protected:
		/// <summary>
		/// Add a data record to the persistent repository
		/// </summary>
		/// <param name="data"></param>
		bool Add(TData data);

		/// <summary>
		/// Return an object from memory
		/// </summary>
		/// <param name="id"></param>
		/// <returns></returns>
		TData* Get(int id);

		/// <summary>
		/// Delete an object from memory (will persisted later by Save() command.
		/// </summary>
		/// <param name="id"></param>
		/// <returns></returns>
		bool Delete(int id);

		/// <summary>
		/// Update an object from memory (will persisted later by Save() command.
		/// </summary>
		/// <param name="data"></param>
		/// <returns></returns>
		bool Update(TData data);


	private:
		/// <summary>
		/// The persistor to manage TData objects at lower-layer .
		/// </summary>
		YB_PersistorBasis<TData> persistor;

		///dictionary of id:object pair
		map<int, TData> dataSet;
	};

#pragma region Constructors definition
	template<class TData>
	inline YB_ManagerBasis<TData>::YB_ManagerBasis(void)
	{
	}
	template<class TData>
	inline YB_ManagerBasis<TData>::YB_ManagerBasis(string url)
	{
		//instantiate a persistor based on the url passed in.
		persistor = YB_PersistorBasis<TData>(url);
	}

#pragma endregion




	template<class TData>
	inline TData* YB_ManagerBasis<TData>::Get(int id)
	{
		TData* ptr = nullptr;
		//if TData already existed in the cache, then return the cached object
		if (dataSet.find(id) != dataSet.end())
			ptr = &dataSet[id];
		//otherwise will take from persistance
		else
		{
			ptr = new TData();
			persistor.Get(id, ptr);
		}
		return ptr;
	}
	template<class TData>
	inline bool YB_ManagerBasis<TData>::Add(TData data)
	{
		try {
			persistor.Add(data);
		}
		catch (exception e)
		{
			throw YB_PersistorError();
		}
		return false;
	}
	template<class TData>
	inline bool YB_ManagerBasis<TData>::Delete(int id)
	{
		return false;
	}
	template<class TData>
	inline bool YB_ManagerBasis<TData>::Update(TData data)
	{
		return false;
	}

}
#endif YB_ManagerBasis_H
