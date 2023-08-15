#include <string>
#include <vector>
#include "YB_DataBasis.h"
#include "YB_Repository.h"
#pragma once

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

	protected:
		YB_PersistorBasis();
		YB_PersistorBasis(string url);

		vector<TData> dataSet;

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
		virtual TData Get(int id);

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
		void ReadAllLines();
		string ReadLine(int id);
		void AddLine(string record);
		void UpdatLine(string record);
		void Clear();
		void Open(string path);
		void Save();
	};
}

