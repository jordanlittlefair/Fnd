#include "MockSystemContainer.hpp"

using namespace Fnd::Test::SystemManager;
using namespace Fnd::SystemManager;


MockSystemContainer::MockSystemContainer()
{
	
}

void MockSystemContainer::SetTaskProvider(TaskProviderPtr task_provider)
{
	_task_provider = task_provider;
}

void MockSystemContainer::AddSystem(SystemPtr system)
{
	_systems.push_back(system);
}

const std::vector<SystemPtr>& MockSystemContainer::GetOrderedSystems() const
{
	return _systems;
}
