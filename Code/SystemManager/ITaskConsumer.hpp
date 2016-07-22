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
	
	virtual bool IsAlive() const = 0;
	
	virtual void Start() = 0;
	
	virtual void Kill() = 0;
	
	virtual ~ITaskConsumer() {}
};

typedef std::shared_ptr<ITaskConsumer> TaskConsumerPtr;

}

}
