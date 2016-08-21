#include "MockNameMappedSystem.hpp"

using namespace Fnd::SystemManager;
using namespace Fnd::Test::SystemManager;

MockNameMappedSystem::MockNameMappedSystem(Fnd::SystemManager::SystemIdNameMapperPtr system_id_name_mapper, const std::string& name):
	NameMappedSystem(system_id_name_mapper, name)
{
}

void MockNameMappedSystem::OnInitialise()
{
}

void MockNameMappedSystem::OnRun()
{
}
