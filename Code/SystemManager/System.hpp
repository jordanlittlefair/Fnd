#pragma once

#include "ISystem.hpp"
#include "ITaskProvider.hpp"
#include "Task.hpp"

#include <string>
#include <vector>

namespace Fnd
{

namespace SystemManager
{

class System:
	public ISystem,
	public std::enable_shared_from_this<System>
{
public:
	
	void SetTaskProvider(TaskProviderPtr task_provider);
	
	SystemId GetId() const;
	
	void AddDependency(const SystemId& dependency);
	
	const std::vector<SystemId>& GetDependencies() const;
	
	void Run();
	
	~System();
	
protected:

	System(const SystemId& id);
	
	SystemPtr This();
	
	bool HasTaskProvider() const;
	
	void SubmitTask(TaskPtr task);
	
	void WaitForSystemTasks();

	virtual void OnRun() = 0;
	
private:

	const SystemId _id;

	std::vector<SystemId> _dependencies;
	
	TaskProviderPtr _task_provider;
};

}

}
