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
	
	virtual ~ITaskProvider() {}
};
	
typedef std::shared_ptr<ITaskProvider> TaskProviderPtr;
	
}
	
}
