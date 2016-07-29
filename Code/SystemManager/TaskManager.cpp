#include "TaskManager.hpp"

#include "ConcurrentTaskProcessor.hpp"
#include "TaskQueue.hpp"

#include <cassert>
#include <thread>

using namespace Fnd::SystemManager;

TaskManager::TaskManager():
	_is_initialised(false)
{
}

bool TaskManager::IsInitialised() const
{
	return _is_initialised;
}

void TaskManager::Initialise()
{
	if (_is_initialised)
	{
		return;		// or throw an exception?
	}
	
	if (!_task_consumer)
	{
		const unsigned int num_threads = std::thread::hardware_concurrency();
		_task_consumer = std::make_shared<ConcurrentTaskProcessor>(num_threads);
	}
	
	if (!_task_provider)
	{
		_task_provider = std::make_shared<TaskQueue>();
	}
	
	_task_consumer->SetTaskProvider(_task_provider);
	
	_is_initialised = true;
}

bool TaskManager::IsAlive() const
{
	if (!_is_initialised)
	{
		return false;
	}
	
	assert(_task_consumer);
	
	return _task_consumer->IsAlive();
}

void TaskManager::Start()
{
	assert(_is_initialised);
	assert(_task_consumer);
	assert(_task_provider);
	
	_task_consumer->Start();
}

void TaskManager::Kill()
{
	if (!_is_initialised)
	{
		return;
	}
	
	if (_task_provider && _task_provider->IsAlive())
	{
		_task_provider->Kill();
	}
	
	if (_task_consumer && _task_consumer->IsAlive())
	{
		_task_consumer->Kill();
	}
}

void TaskManager::SetTaskConsumer(TaskConsumerPtr task_consumer)
{
	_task_consumer = task_consumer;
}

const ITaskConsumer& TaskManager::GetTaskConsumer() const
{
	assert(_task_consumer);
	
	return *_task_consumer;
}

ITaskConsumer& TaskManager::GetTaskConsumer()
{
	assert(_task_consumer);
	
	return *_task_consumer;
}

TaskConsumerPtr TaskManager::GetTaskConsumerPtr()
{
	return _task_consumer;
}

void TaskManager::SetTaskProvider(TaskProviderPtr task_provider)
{
	_task_provider = task_provider;
}

const ITaskProvider& TaskManager::GetTaskProvider() const
{
	assert(_task_provider);
	
	return *_task_provider;
}

ITaskProvider& TaskManager::GetTaskProvider()
{
	assert(_task_provider);
	
	return *_task_provider;
}

TaskProviderPtr TaskManager::GetTaskProviderPtr()
{
	return _task_provider;
}

TaskManager::~TaskManager()
{
	Kill();
}