#ifndef YB_PersistorBasis_H
#define YB_PersistorBasis_H

// Your header file contents here

#include <string>
#include <vector>
#include "YB_DataBasis.h"
#include "YB_Repository.h"
#include "YB_User.h"

using namespace std;


namespace YBCarRental
{
	/// <summary>
	/// Object orientated layer of data persistence.
	/// </summary>
	/// <typeparam name="TData"></typeparam>
	template <class TData = YB_DataBasis>
	class YB_PersistorBasis
	{
	public:
		YB_PersistorBasis(void);
		YB_PersistorBasis(string url);

		string repositoryURL;

	protected:

		/// <summary>
		/// Read all records (objects) into memory
		/// </summary>
		virtual void ReadAll();

		/// <summary>
		/// Add a data record to the persistent repository
		/// </summary>
		/// <param name="data"></param>
		virtual void Add(TData data);

		/// <summary>
		/// Return an object from memory
		/// </summary>
		/// <param name="id"></param>
		/// <returns></returns>
		virtual void Get(int id, TData& objResult);

		/// <summary>
		/// Delete an object from memory (will persisted later by Save() command.
		/// </summary>
		/// <param name="id"></param>
		/// <returns></returns>
		virtual bool Delete(int id);

		/// <summary>
		/// Update an object from memory (will persisted later by Save() command.
		/// </summary>
		/// <param name="data"></param>
		/// <returns></returns>
		virtual bool Update(TData data);


	private:
		/// <summary>
		/// The file repository to store data records.
		/// </summary>
		YB_Repository repository;

		vector<TData> dataSet;



		void ReadAllLines();
		string ReadLine(int id);
		void AddLine(string record);
		void UpdatLine(string record);
		void Clear();
		void Open(string path);
		void Save();
	};

	template<class TData> // TData = YBDataBasis
	YB_PersistorBasis<TData>::YB_PersistorBasis<TData>()
	{
	};

	template<class TData> // TData = YBDataBasis
	YB_PersistorBasis<TData>::YB_PersistorBasis<TData>(string url)
	{
		repositoryURL = url;
	};

	template<class TData>
	void YB_PersistorBasis<TData>::ReadAll()
	{
	}
	template<class TData>
	void YB_PersistorBasis<TData>::Add(TData data)
	{
	}
	template<class TData>
	void YB_PersistorBasis<TData>::Get(int id, TData& objResult)
	{
	}
	template<class TData>
	bool YB_PersistorBasis<TData>::Delete(int id)
	{
		return false;
	}
	template<class TData>
	bool YB_PersistorBasis<TData>::Update(TData data)
	{
		return false;
	}


	//----------------Private Implementation------------------//
	template<class TData>
	inline void YB_PersistorBasis<TData>::ReadAllLines()
	{
	}
	template<class TData>
	inline string YB_PersistorBasis<TData>::ReadLine(int id)
	{
		return string();
	}
	template<class TData>
	inline void YB_PersistorBasis<TData>::AddLine(string record)
	{
	}
	template<class TData>
	inline void YB_PersistorBasis<TData>::UpdatLine(string record)
	{
	}
	template<class TData>
	inline void YB_PersistorBasis<TData>::Clear()
	{
	}
	template<class TData>
	inline void YB_PersistorBasis<TData>::Open(string path)
	{
	}
	template<class TData>
	inline void YB_PersistorBasis<TData>::Save()
	{
	}
}

#endif YB_PersistorBasis_H
