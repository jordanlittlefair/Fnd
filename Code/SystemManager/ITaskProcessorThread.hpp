#pragma once

#include "ITaskProvider.hpp"

namespace Fnd
{

namespace SystemManager
{

class ITaskProcessorThread
{
public:
	
	virtual void SetTaskProvider(TaskProviderPtr task_provider) = 0;
	
	virtual void Start() = 0;
	
	virtual void Kill() = 0;
	
	virtual ~ITaskProcessorThread() {}
};

}

}
