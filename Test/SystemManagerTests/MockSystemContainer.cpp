#include "MockSystemContainer.hpp"

using namespace Fnd::Test::SystemManager;
using namespace Fnd::SystemManager;


MockSystemContainer::MockSystemContainer():
	_is_initialised(false)
{
	
}

void MockSystemContainer::SetTaskProvider(TaskProviderPtr task_provider)
{
	_task_provider = task_provider;
}

bool MockSystemContainer::IsInitialised() const
{
	return _is_initialised;
}

void MockSystemContainer::AddSystem(SystemPtr system)
{
	_systems.push_back(system);
}

void MockSystemContainer::Initialise()
{
	for(auto& system : _systems)
	{
		system->Initialise();
	}
	
	_is_initialised = true;
}

const std::vector<SystemPtr>& MockSystemContainer::GetOrderedSystems() const
{
	return _systems;
}
