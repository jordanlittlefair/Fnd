#include "SystemManager.hpp"

#include "Exceptions.hpp"

#include <cassert>

using namespace Fnd::SystemManager;

SystemManager::SystemManager():
	_is_initialised(false)
{
	
}

void SystemManager::SetSystemIdNameMapper(SystemIdNameMapperPtr system_id_name_mapper)
{
	_system_id_name_mapper = system_id_name_mapper;
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
	return _system_container && _system_container->IsInitialised();
}

bool SystemManager::IsAlive() const
{
	assert(_task_manager);
	
	return _task_manager->IsAlive();
}

SystemIdNameMapperPtr SystemManager::GetSystemIdNameMapper()
{
	assert(_system_id_name_mapper);

	return _system_id_name_mapper;
}

void SystemManager::RegisterSystem(SystemPtr system)
{
	assert(_system_container);
	
	if (_is_initialised)
	{
		throw InvalidOperationException();
	}
	
	_system_container->AddSystem(system);
}

void SystemManager::Initialise()
{
	assert(_task_manager);
	assert(_system_container);
	
	if (_is_initialised)
	{
		throw InvalidOperationException();
	}
	
	_system_container->SetTaskProvider(_task_manager->GetTaskProviderPtr());
	_system_container->Initialise();
	
	_task_manager->Initialise();
	
	_is_initialised = true;
}

void SystemManager::Start()
{
	assert(_task_manager);
	assert(_system_container);
	
	if (_task_manager->IsAlive())
	{
		throw InvalidOperationException();
	}
	
	if (!_is_initialised)
	{
		throw InvalidOperationException();
	}
	
	_task_manager->Start();
}

void SystemManager::Run()
{
	assert(_task_manager);
	assert(_system_container);
	
	if (!_is_initialised)
	{
		throw InvalidOperationException();
	}
	
	if (!_task_manager->IsAlive())
	{
		throw InvalidOperationException();
	}
	
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
		throw InvalidOperationException();
	}
	
	_task_manager->Kill();
}

SystemManager::~SystemManager()
{
}
