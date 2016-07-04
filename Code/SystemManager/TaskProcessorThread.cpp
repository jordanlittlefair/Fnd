#include "TaskProcessorThread.hpp"

#include <cassert>

using namespace Fnd::SystemManager;

TaskProcessorThread::TaskProcessorThread():
	_is_running(false)
{
}

void TaskProcessorThread::SetTaskProvider(TaskProviderPtr task_provider)
{
	assert(!_task_provider);
	
	if (!_task_provider)
	{
		_task_provider = task_provider;
	}
}

void TaskProcessorThread::Start()
{
	assert(_task_provider);
	
	if (!_task_provider)
	{
		return;
	}
	
	{
		std::lock_guard<std::mutex> lock(_is_running_mutex);
	
		if (_is_running)
		{
			return;
		}
		
		_is_running = true;
	}
	
	_thread = std::thread([&]()
	{
		while (IsRunning())
		{
			_task_provider->RunNextTask(true);
		}
	});
}

void TaskProcessorThread::Kill()
{
	// Provider must be dead so we're not waiting on any available tasks
	assert(_task_provider ? !_task_provider->IsAlive() : true);
	
	{
		std::lock_guard<std::mutex> lock(_is_running_mutex);
	
		if (!_is_running)
		{
			return;
		}
		
		_is_running = false;
	}
	
	_thread.join();
}

TaskProcessorThread::~TaskProcessorThread()
{
	Kill();
}

bool TaskProcessorThread::IsRunning() const
{
	std::lock_guard<std::mutex> lock(_is_running_mutex);
	
	return _is_running;
}
