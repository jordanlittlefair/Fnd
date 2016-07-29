#pragma once

#include "ITaskConsumer.hpp"
#include "ITaskProvider.hpp"

namespace Fnd
{

namespace SystemManager
{

class TaskManager
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
	
	const ITaskConsumer& GetTaskConsumer() const;

	ITaskConsumer& GetTaskConsumer();
	
	TaskConsumerPtr GetTaskConsumerPtr();

	const ITaskProvider& GetTaskProvider() const;
	
	ITaskProvider& GetTaskProvider();
	
	TaskProviderPtr GetTaskProviderPtr();
	
	virtual ~TaskManager();
	
private:
	
	bool _is_initialised;
	
	TaskConsumerPtr _task_consumer;
	TaskProviderPtr _task_provider;
};
	
}
	
}
