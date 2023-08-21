#ifndef YB_PersistorBasis_H
#define YB_PersistorBasis_H

// Your header file contents here

#include <string>
#include <map>
#include "YB_DataBasis.h"
#include "YB_Repository.h"
#include "YB_User.h"
#include "YB_Errors.h"

using namespace std;


namespace YBCarRental
{
	/// <summary>
	/// Object orientated layer of data persistence.
	/// </summary>
	/// <typeparam name="TData">The type parameter must be derived from YB_DataBasis</typeparam>
	template <class TData = YB_DataBasis>
	class YB_PersistorBasis
	{
	public:
		YB_PersistorBasis(void);
		YB_PersistorBasis(string url);

		string repositoryURL = "";

		//Note: for simplicity reason, this dataSet was designed to be exposed as public.
		//otherwise it should be hidden from direct external access.
		map<int, TData> dataSet = {};


		/// <summary>
		/// Read all records (objects) into memory
		/// </summary>
		virtual void GetAll();

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
		void Get(int id, TData* objResult);
		//overloaded forms of Get()
		TData* Get(int id);
		TData* Get(string username);

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

	template<class TData> // TData = YBDataBasis
	YB_PersistorBasis<TData>::YB_PersistorBasis<TData>()
	{
		repository = YB_Repository();
	};

	template<class TData> // TData = YBDataBasis
	YB_PersistorBasis<TData>::YB_PersistorBasis<TData>(string url)
	{
		repositoryURL = url;
		repository = YB_Repository(repositoryURL);
		GetAll();
	};



	template<class TData>
	void YB_PersistorBasis<TData>::GetAll() //cache to dataSet
	{
		if (!dataSet.empty())
			dataSet.clear();			//GetAll is invoked in the constructor so there's potential of repeated invocation.

		//repository.ReadAllLines();
		for (const auto& iter : repository.allRecordLines)
		{
			TData data;
			data.Deserialize(iter.second);
			//dataSet.push_back(data);
			dataSet.insert(std::make_pair(data.Id, data));
		}
	}

	template<class TData>
	void YB_PersistorBasis<TData>::Get(int id, TData* objResult)
	{
		auto iterator = dataSet.find(id);

		if (iterator != dataSet.end()) {
			*objResult = iterator->second;
		}
		else
			objResult = nullptr;

		// Outdated: 
		// unnecessary to get the object from repository. Persistor had the objects in constructor.
		//string* line = repository.GetLine(id);
		//if (objResult != nullptr) {
		//	//TData obj = *objResult;
		//	objResult->Deserialize(*line);
		//}
	}

	template<class TData>
	TData* YB_PersistorBasis<TData>::Get(int id)
	{
		auto iterator = dataSet.find(id);
		//auto iterator = std::find_if(dataSet.begin(), dataSet.end(),
		//	[id](const TData& data) {
		//		return data.Id == id;
		//	});

		if (iterator != dataSet.end()) {
			return &(iterator->second);
		}
		else
			return nullptr;
	}

	template<class TData>
	TData* YB_PersistorBasis<TData>::Get(string username)
	{
		int id=-1;
		for (const auto& entry : dataSet) {
			//data = entry.second;
			if (entry.second.UserName == username) {
				//as the entry was created in the for loop, so it will be destructed after for loop breaks.
				//int value will be copied so it won't loss.
				id = entry.second.Id;		
				break;
			}
		}
		return this->Get(id);
	}


	template<class TData>
	void YB_PersistorBasis<TData>::Add(TData data)
	{
		string* line = data.Serialize();
		try {
			repository.AddLine(*line);
		}
		catch (exception e)
		{
			throw YB_RepositoryError();
		}
		dataSet.insert(std::make_pair(data.Id, data));
	}

	template<class TData>
	bool YB_PersistorBasis<TData>::Delete(int id)
	{
		auto item = dataSet.find(id);
		if (item != dataSet.end()) {
			try {
				repository.DeleteLine(id);
			}
			catch (exception e) {
				return false;
			}
			dataSet.erase(item);
			return true;
		}
		return false;
	}

	template<class TData>
	bool YB_PersistorBasis<TData>::Update(TData data)
	{
		string* line = data.Serialize();
		auto item = dataSet.find(data.Id);
		if (item != dataSet.end()) {
			try {
				repository.UpdateLine(*line);
			}
			catch (exception e) {
				return false;
			}
			item->second = data;
			return true;
		}
		return false;
	}

}

#endif YB_PersistorBasis_H
