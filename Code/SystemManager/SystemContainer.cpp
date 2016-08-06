#include "SystemContainer.hpp"

#include "Exceptions.hpp"
#include "ISystem.hpp"

#include <algorithm>

using namespace Fnd::SystemManager;

SystemContainer::SystemContainer():
	_is_initialised(false)
{
}

void SystemContainer::SetSystemGraph(SystemGraphPtr system_graph)
{
	_system_graph = system_graph;
}

void SystemContainer::SetTaskProvider(TaskProviderPtr task_provider)
{
	_task_provider = task_provider;
	
	for (auto& system : _systems)
	{
		system->SetTaskProvider(_task_provider);
	}
}

bool SystemContainer::IsInitialised() const
{
	return _is_initialised;
}

void SystemContainer::AddSystem(SystemPtr system)
{
	if (_is_initialised)
	{
		throw InvalidOperationException();
	}
	
	if ( std::find_if(_systems.begin(),_systems.end(),[&](const SystemPtr& existing_system)
			{
				return existing_system->GetId() == system->GetId();
			}) == _systems.end() )
	{
		system->SetTaskProvider(_task_provider);
	
		_systems.push_back(system);
	
		CalculateOptimalPath();
	}
	else
	{
		throw InvalidSystemIdException(system->GetId());
	}
}

void SystemContainer::Initialise()
{
	if (_is_initialised)
	{
		throw InvalidOperationException();
	}
	
	for (auto& system : _systems)
	{
		system->Initialise();
	}
	
	_is_initialised = true;
}

const std::vector<SystemPtr>& SystemContainer::GetOrderedSystems() const
{
	return _optimal_path;
}

void SystemContainer::CalculateOptimalPath()
{
	_system_graph->UpdateSystemNodes(_systems);
	
	std::vector<SystemId> path_ids = _system_graph->GetOptimalPath();
	
	_optimal_path.clear();
	
	for (auto systemId : path_ids)
	{
		auto iter = std::find_if(_systems.begin(), _systems.end(), [&](const SystemPtr& system)
		{
			return system->GetId() == systemId;
		});
								 
		_optimal_path.push_back(*iter);
	}
}
