#include "NameMappedSystem.hpp"

using namespace Fnd::SystemManager;

NameMappedSystem::NameMappedSystem(SystemIdNameMapperPtr system_id_name_mapper, const std::string& name):
	System(system_id_name_mapper->GenerateId(name), name)
{
}
