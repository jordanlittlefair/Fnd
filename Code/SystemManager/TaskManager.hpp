#pragma once

#include "ITaskConsumer.hpp"
#include "ITaskManager.hpp"
#include "ITaskProvider.hpp"

namespace Fnd
{

namespace SystemManager
{

class TaskManager:
	public ITaskManager
{
public:
	
	TaskManager();
	
	void SetTaskConsumer(TaskConsumerPtr task_consumer);
	
	void SetTaskProvider(TaskProviderPtr task_provider);
	
	bool IsInitialised() const;
	
	void Initialise();
	
	bool IsAlive() const;
	
	void Start();
	
	void Kill();
		
	TaskConsumerPtr GetTaskConsumerPtr();

	TaskProviderPtr GetTaskProviderPtr();
	
	virtual ~TaskManager();
	
private:
	
	bool _is_initialised;
	
	TaskConsumerPtr _task_consumer;
	TaskProviderPtr _task_provider;
};
	
}
	
}
