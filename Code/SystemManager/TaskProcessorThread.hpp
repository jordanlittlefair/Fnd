#pragma once

#include "ITaskProcessorThread.hpp"
#include "ITaskProvider.hpp"

#include <thread>

namespace Fnd
{

namespace SystemManager
{

class TaskProcessorThread
{
public:
	
	TaskProcessorThread();
	
	void SetTaskProvider(TaskProviderPtr task_provider);
	
	bool IsRunning() const;
	
	void Start();
	
	void Kill();
	
	~TaskProcessorThread();
	
private:
	
	bool _is_running;
	
	mutable std::mutex _is_running_mutex;
	
	TaskProviderPtr _task_provider;
	
	std::thread _thread;
};
	
}
	
}
