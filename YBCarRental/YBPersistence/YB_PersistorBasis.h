#ifndef YB_PersistorBasis_H
#define YB_PersistorBasis_H

// Your header file contents here

#include <string>
#include <map>
#include "YB_DataBasis.h"
#include "YB_Repository.h"
//#include "YB_User.h"
#include "YB_Errors.h"

using namespace std;


namespace YBPersistence
{
	/// <summary>
	/// Object orientated layer of data persistence.
	/// </summary>
	/// <typeparam name="TData">The type parameter must be derived from YB_DataBasis</typeparam>
	template <class TData = YB_DataBasis>
	class YB_PersistorBasis
	{
	public:
		YB_PersistorBasis(void) {
			repository = new YB_Repository();
		};
		YB_PersistorBasis(string url) : YB_PersistorBasis() {
			repositoryURL = url;
			repository = new YB_Repository(repositoryURL);
			LoadAll();
		};
		~YB_PersistorBasis() {
			delete repository;
		};

		string repositoryURL = "";


		/// <summary>
		/// Read all records (objects) into memory
		/// </summary>
		virtual void				LoadAll();

		/// <summary>
		/// Add a data record to the persistent repository
		/// </summary>
		/// <param name="data"></param>
		virtual void				Add(TData data);

		/// <summary>
		/// Return an object from memory
		/// </summary>
		/// <param name="id"></param>
		/// <returns></returns>
		void						Get(int id, TData* objResult);

		TData*						Get(int id);

		map<int, TData>*			GetAll();

		/// <summary>
		/// Delete an object from memory (will persisted later by Save() command.
		/// </summary>
		/// <param name="id"></param>
		/// <returns></returns>
		virtual bool				Delete(int id);

		/// <summary>
		/// Update an object from memory (will persisted later by Save() command.
		/// </summary>
		/// <param name="data"></param>
		/// <returns></returns>
		virtual bool				Update(TData data);

		//Note: for simplicity reason, this dataSet was designed to be exposed as public.
		//otherwise it should be hidden from direct external access.

		map<int, TData>				dataSet = {}; //!!!DO NOT MODIFY THE dataSet to pointers. OR YOU NEED DEVELOP A TDataFactory FOR INSTANCE CREATION.
	private:
		/// <summary>
		/// The file repository to store data records.
		/// </summary>
		YB_Repository*				repository;
	};

	template<class TData>
	void							YB_PersistorBasis<TData>::LoadAll() //cache to dataSet
	{
		if (!dataSet.empty())
			//GetAll is invoked in the constructor so there's potential of repeated invocation.
			dataSet.clear();

		//repository.ReadAllLines();
		for (const auto& iter : repository->allRecordLines)
		{
			TData data;
			data.Deserialize(iter.second);
			dataSet.insert(std::make_pair(data.Id, data));
		}
	}

	template<class TData>
	void							YB_PersistorBasis<TData>::Get(int id, TData* objResult)
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
	TData*							YB_PersistorBasis<TData>::Get(int id)
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
	map<int, TData>*				YB_PersistorBasis<TData>::GetAll()
	{
		//std::map<int, TData*>* tDataPointerMap = new std::map<int, TData*>;
		//for (auto iterator : dataSet) {
		//	TData* data = &iterator.second;
		//	tDataPointerMap->insert(std::make_pair(iterator.first, data));
		//}

		//return tDataPointerMap;
		return &dataSet;
	}

	template<class TData>
	void							YB_PersistorBasis<TData>::Add(TData data)
	{
		string* line = data.Serialize();
		try {
			repository->AddLine(*line);
		}
		catch (exception e)
		{
			throw YB_RepositoryError();
		}
		dataSet.insert(std::make_pair(data.Id, data));
	}

	template<class TData>
	bool							YB_PersistorBasis<TData>::Delete(int id)
	{
		auto item = dataSet.find(id);
		if (item != dataSet.end()) {
			try {
				repository->DeleteLine(id);
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
	bool							YB_PersistorBasis<TData>::Update(TData data)
	{
		string* line	= data.Serialize();
		auto item		= dataSet.find(data.Id);
		if (item == dataSet.end())					//Fail to find the item to update.
			return false;

		try {
			repository->UpdateLine(*line);
		}
		catch (exception e) {
			return false;							//Persisting failed.
		}

		item->second = std::move(data);
		return true;								//Succeed.
	}

}

#endif // YB_PersistorBasis_H
