#pragma once

#include "ITaskConsumer.hpp"
#include "ITaskProvider.hpp"

#include <memory>

namespace Fnd
{

namespace SystemManager
{

class ITaskManager
{
public:
	
	virtual bool IsInitialised() const = 0;
	
	virtual void Initialise() = 0;
	
	virtual bool IsAlive() const = 0;
	
	virtual void Start() = 0;
	
	virtual void Kill() = 0;
	
	virtual TaskConsumerPtr GetTaskConsumerPtr() = 0;
	
	virtual TaskProviderPtr GetTaskProviderPtr() = 0;
	
	virtual ~ITaskManager() {}
};
	
typedef std::shared_ptr<ITaskManager> TaskManagerPtr;

}

}
