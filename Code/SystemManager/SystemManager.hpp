#pragma once

#include "ISystemContainer.hpp"
#include "ISystemManager.hpp"
#include "ITaskManager.hpp"

namespace Fnd
{
	
namespace SystemManager
{

class SystemManager:
	public ISystemManager
{
public:
	
	SystemManager();
	
	void SetTaskManager(TaskManagerPtr task_manager);
	
	void SetSystemContainer(SystemContainerPtr system_container);
	
	bool IsInitialised() const;
	
	bool IsAlive() const;
	
	void AddSystem(SystemPtr system);
	
	void Initialise();
	
	void Start();
	
	void Run();
	
	void Kill();
	
	~SystemManager();
	
private:
	
	bool _is_initialised;
	
	TaskManagerPtr _task_manager;
	
	SystemContainerPtr _system_container;
};
	
}
	
}
