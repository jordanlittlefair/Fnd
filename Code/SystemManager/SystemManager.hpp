#pragma once

#include "ISystemContainer.hpp"
#include "ISystemManager.hpp"
#include "ITaskManager.hpp"

#include "SystemIdNameMapper.hpp"

namespace Fnd
{
	
namespace SystemManager
{

class SystemManager:
	public ISystemManager
{
public:
	
	SystemManager();

	void SetSystemIdNameMapper(SystemIdNameMapperPtr system_id_name_mapper);
	
	void SetTaskManager(TaskManagerPtr task_manager);
	
	void SetSystemContainer(SystemContainerPtr system_container);
	
	bool IsInitialised() const;
	
	bool IsAlive() const;

	SystemIdNameMapperPtr GetSystemIdNameMapper();
	
	void RegisterSystem(SystemPtr system);
	
	void Initialise();
	
	void Start();
	
	void Run();
	
	void Kill();
	
	~SystemManager();
	
private:
	
	bool _is_initialised;

	SystemIdNameMapperPtr _system_id_name_mapper;
	
	TaskManagerPtr _task_manager;
	
	SystemContainerPtr _system_container;
};
	
}
	
}
