#include "YB_Repository.h"

namespace YBCarRental
{
	/// <summary>
	/// Text stream orientated layer of data persistence.
	/// </summary>
	YB_Repository::YB_Repository()
	{

	}

	YB_Repository::YB_Repository(string url)
	{
	}

	YB_Repository::~YB_Repository()
	{
		input.close();
		output.close();
	}

	map<int, string> YB_Repository::ReadAllLines()
	{
		return map<int, string>();
	}

	void YB_Repository::AddLine(string line)
	{

	}

	void YB_Repository::DeleteLine(string line)
	{
	}

	void YB_Repository::UpdateLine(string line)
	{
	}

	void YB_Repository::ClearAll()
	{
	}

}