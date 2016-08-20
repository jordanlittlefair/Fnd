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

	std::string GetName() const;
	
	void AddDependency(const SystemId& dependency);
	
	const std::vector<SystemId>& GetDependencies() const;
	
	bool IsInitialised() const;
	
	void Initialise();
	
	void Run();
	
	~System();
	
protected:

	System(const SystemId& id, const std::string& name);
	
	SystemPtr This();
	
	bool HasTaskProvider() const;
	
	void SubmitTask(TaskPtr task);
	
	void WaitForSystemTasks();

	virtual void OnInitialise() = 0;
	
	virtual void OnRun() = 0;
	
private:

	const SystemId _id;

	const std::string _name;
	
	bool _is_initialised;

	std::vector<SystemId> _dependencies;
	
	TaskProviderPtr _task_provider;
};

}

}
