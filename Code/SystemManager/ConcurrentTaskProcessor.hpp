#pragma once

#include "ITaskConsumer.hpp"
#include "TaskProcessorThread.hpp"

namespace Fnd
{

namespace SystemManager
{

class ConcurrentTaskProcessor:
	public ITaskConsumer
{
public:

	ConcurrentTaskProcessor(const unsigned int num_threads);
	
	void SetTaskProvider(TaskProviderPtr task_provider);
	
	bool IsAlive() const;

	void Start();

	void Kill();

private:
	
	bool _is_running;
	
	mutable std::mutex _is_running_mutex;

	TaskProviderPtr _task_provider;
	
	std::vector<TaskProcessorThreadPtr> _threads;
};

}

}
