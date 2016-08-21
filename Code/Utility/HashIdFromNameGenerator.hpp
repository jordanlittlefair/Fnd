#pragma once

#include "IIdFromNameGenerator.hpp"

namespace Fnd
{

namespace Utility
{

template <typename IdType>
class HashIdFromNameGenerator:
	public IIdFromNameGenerator<IdType>
{
public:
	
	static_assert(std::is_integral<IdType>::value, "IdType must be an integer if used in HashIdFromNameGenerator");
	
	IdType GenerateIdFromName(const std::string& name) const
	{
		IdType hash = 5381;
		
		for (unsigned int i = 0; i < name.size(); ++i)
		{
			hash = ((hash << 5) + hash) + name[i];
		}
		
		return hash;
	}
};

}

}
