#pragma once

#include "ITaskProvider.hpp"

namespace Fnd
{

namespace SystemManager
{

class ITaskConsumer
{
public:
	
	virtual void SetTaskProvider(TaskProviderPtr task_provider) = 0;
	
	virtual bool IsRunning() const = 0;
	
	virtual void Start() = 0;
	
	virtual void Kill() = 0;
};

typedef std::shared_ptr<ITaskConsumer> ITaskConsumerPtr;

}

}
