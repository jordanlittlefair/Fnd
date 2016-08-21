#include "ConcurrentTaskProcessor.hpp"

#include <cassert>

using namespace Fnd::SystemManager;

ConcurrentTaskProcessor::ConcurrentTaskProcessor(const unsigned int num_threads):
	_is_running(false)
{
	for (unsigned int i = 0; i < num_threads; ++i)
	{
		_threads.push_back(std::make_shared<TaskProcessorThread>());
	}
}

void ConcurrentTaskProcessor::SetTaskProvider(TaskProviderPtr task_provider)
{
	assert(!_task_provider);
	
	if (!_task_provider)
	{
		_task_provider = task_provider;
		
		for (auto& thread : _threads)
		{
			thread->SetTaskProvider(task_provider);
		}
	}
}

bool ConcurrentTaskProcessor::IsAlive() const
{
	std::lock_guard<std::mutex> lock(_is_running_mutex);
	
	return _is_running;
}

void ConcurrentTaskProcessor::Start()
{
	assert(_task_provider);
	
	{
		std::lock_guard<std::mutex> lock(_is_running_mutex);
	
		if (_is_running)
		{
			return;
		}
		
		_is_running = true;
	}
	
	for (auto& thread : _threads)
	{
		thread->Start();
	}
}

void ConcurrentTaskProcessor::Kill()
{
	{
		std::lock_guard<std::mutex> lock(_is_running_mutex);
		
		if (!_is_running)
		{
			return;
		}
		
		_is_running = false;
	}
	
	for (auto& thread : _threads)
	{
		thread->Kill();
	}
	
	_threads.clear();
}
