#pragma once

#include "System.hpp"
#include "SystemIdNameMapper.hpp"

namespace Fnd
{

namespace SystemManager
{

class NameMappedSystem:
	public System
{
protected:

	NameMappedSystem(SystemIdNameMapperPtr system_id_name_mapper, const std::string& name);
};

}

}
