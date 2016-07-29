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
	
	bool IsInitialised() const;
	
	void Initialise();
	
	bool IsAlive() const;
	
	void Start();
	
	void WaitForTasks() const;
	
	void WaitForTasks(const SystemId system_ids[], const unsigned int num_ids) const;
	
	void Kill();
	
	void SetTaskConsumer(TaskConsumerPtr task_consumer);
	
	const ITaskConsumer& GetTaskConsumer() const;

	ITaskConsumer& GetTaskConsumer();
	
	TaskConsumerPtr GetTaskConsumerPtr();
	
	void SetTaskProvider(TaskProviderPtr task_provider);

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
