#pragma once

#include "Task.hpp"

namespace Fnd
{

namespace SystemManager
{

class ITaskProvider
{
public:
	
	virtual bool IsAlive() const = 0;

	virtual void SubmitTask(TaskPtr task) = 0;
	
	virtual void RunNextTask(const bool wait) = 0;
	
	virtual void WaitForTasks() const = 0;
	
	virtual void WaitForTasks(const SystemId system_id[], const unsigned int num_ids) const = 0;
	
	virtual void Kill() = 0;
	
	virtual ~ITaskProvider() {}
};
	
typedef std::shared_ptr<ITaskProvider> TaskProviderPtr;
	
}
	
}
