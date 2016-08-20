#include "TaskManager.hpp"

#include "ConcurrentTaskProcessor.hpp"
#include "Exceptions.hpp"
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
	assert(_task_consumer);
	
	if (_is_initialised)
	{
		throw InvalidOperationException();
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

TaskConsumerPtr TaskManager::GetTaskConsumerPtr()
{
	return _task_consumer;
}

void TaskManager::SetTaskProvider(TaskProviderPtr task_provider)
{
	_task_provider = task_provider;
}

TaskProviderPtr TaskManager::GetTaskProviderPtr()
{
	return _task_provider;
}

TaskManager::~TaskManager()
{
	Kill();
}