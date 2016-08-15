#pragma once

#include "IIdFromNameGenerator.hpp"

#include <map>
#include <utility>

namespace Fnd
{

namespace Utility
{

template <typename IdType>
class IdNameMapper
{
public:
	
	IdNameMapper(std::shared_ptr<IIdFromNameGenerator<IdType>> id_from_name_generator):
		_generator(id_from_name_generator)
	{
	}
	
	IdType GenerateId(const std::string& name)
	{
		if (_name_to_id.find(name) != _name_to_id.end())
		{
			// TODO: Exception types
			throw std::runtime_error("Already generated an id for this name");
		}
		
		IdType id = _generator->GenerateIdFromName(name);
		
		if (_id_to_name.find(id) != _id_to_name.end())
		{
			std::string additional_string;
			
			do
			{
				// the generated id already exists, so generate a new id
				additional_string += (char)((rand() % (std::numeric_limits<char>::max() - 1)) + 1);
				
				id = _generator->GenerateIdFromName(name + additional_string);
			}
			while (_id_to_name.find(id) != _id_to_name.end());
		}
		
		_id_to_name[id] = name;
		_name_to_id[name] = id;
		
		return id;
	}
	
	bool IdHasBeenGenerated(const IdType& id) const
	{
		return _id_to_name.find(id) != _id_to_name.end();
	}
	
	bool IdHasBeenGeneratedForName(const std::string& name) const
	{
		return _name_to_id.find(name) != _name_to_id.end();
	}
	
	IdType GetId(const std::string& name) const
	{
		auto iter = _name_to_id.find(name);
		
		if (iter != _name_to_id.end())
		{
			return iter->second;
		}
		else
		{
			// TODO: Exception types
			throw std::runtime_error("Cant find Id for this name");
		}
	}
	
	std::string GetName(const IdType& id) const
	{
		auto iter = _id_to_name.find(id);
		
		if (iter != _id_to_name.end())
		{
			return iter->second;
		}
		else
		{
			// TODO: Exception types
			throw std::runtime_error("Cant find Id for this name");
		}
	}
	
private:
	
	std::shared_ptr<IIdFromNameGenerator<IdType>> _generator;
	
	std::map<IdType,std::string> _id_to_name;
	std::map<std::string,IdType> _name_to_id;
};

}

}
