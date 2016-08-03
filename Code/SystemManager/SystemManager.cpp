#include "SystemManager.hpp"

#include <cassert>

using namespace Fnd::SystemManager;

SystemManager::SystemManager():
	_is_initialised(false)
{
	
}

void SystemManager::SetTaskManager(TaskManagerPtr task_manager)
{
	_task_manager = task_manager;
}

void SystemManager::SetSystemContainer(SystemContainerPtr system_container)
{
	_system_container = system_container;
}

bool SystemManager::IsInitialised() const
{
	// TODO: this should be a method on _system_container
	return _is_initialised;
}

bool SystemManager::IsAlive() const
{
	assert(_task_manager);
	
	return _task_manager->IsAlive();
}

void SystemManager::AddSystem(SystemPtr system)
{
	assert(_system_container);
	
	_system_container->AddSystem(system);
}

void SystemManager::Initialise()
{
	assert(_task_manager);
	assert(_system_container);
	
	if (_is_initialised)
	{
		return; // TODO: or throw?
	}
	
	// TODO: initialise systems in _system_container
	
	_is_initialised = true;
}

void SystemManager::Start()
{
	assert(_task_manager);
	assert(_system_container);
	
	if (_task_manager->IsAlive())
	{
		return; // TODO: or throw?
	}
	
	if (!_is_initialised)
	{
		return; // TODO: or throw?
	}
	
	_task_manager->Start();
}

void SystemManager::Run()
{
	assert(_task_manager);
	assert(_system_container);
	
	const std::vector<SystemPtr>& systems = _system_container->GetOrderedSystems();
	
	for ( auto& system : systems )
	{
		system->Run();
	}
}

void SystemManager::Kill()
{
	if (!_task_manager)
	{
		return; // May not be set - when called in destructor (ie. an error occurs before it's set)
	}
	
	if (!_task_manager->IsAlive())
	{
		return; // TODO: or throw
	}
	
	_task_manager->Kill();
}

SystemManager::~SystemManager()
{
	Kill();
}
