#pragma once

#include "ITaskProcessorThread.hpp"
#include "ITaskConsumer.hpp"

#include <thread>

namespace Fnd
{

namespace SystemManager
{

class TaskProcessorThread:
	public ITaskConsumer
{
public:
	
	TaskProcessorThread();
	
	void SetTaskProvider(TaskProviderPtr task_provider);
	
	bool IsAlive() const;
	
	void Start();
	
	void Kill();
	
	~TaskProcessorThread();
	
private:
	
	bool _is_running;
	
	mutable std::mutex _is_running_mutex;
	
	TaskProviderPtr _task_provider;
	
	std::thread _thread;
};
	
typedef std::shared_ptr<TaskProcessorThread> TaskProcessorThreadPtr;
	
}
	
}
