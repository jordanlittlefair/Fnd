#include "TaskQueue.hpp"

#include <cassert>

using namespace Fnd::SystemManager;

TaskQueue::TaskQueue():
	_is_alive(true)
{
}

bool TaskQueue::IsAlive() const
{
	std::lock_guard<std::mutex> lock(_tasks_mutex);
	
	return _is_alive;
}

unsigned int TaskQueue::GetNumPendingTasks() const
{
	std::lock_guard<std::mutex> lock(_tasks_mutex);
	
	return _pending_tasks.size();
}

unsigned int TaskQueue::GetNumTasks() const
{
	std::lock_guard<std::mutex> lock(_tasks_mutex);
	
	return _tasks.size();
}

void TaskQueue::SubmitTask(TaskPtr task)
{
	std::lock_guard<std::mutex> lock(_tasks_mutex);
	
	_tasks.push_back(task);
	
	_pending_tasks.push(task);
	
	_has_pending_condition.notify_one();
}

void TaskQueue::RunNextTask(const bool wait)
{
	TaskPtr current_task = GetNextTask(wait);
	
	if (current_task)
	{
		current_task->Run();
		
		CompleteTask(current_task);
	}
}

void TaskQueue::Kill()
{
	std::lock_guard<std::mutex> lock(_tasks_mutex);	// Use same mutex as tasks for thread safety with condition variable
	
	_is_alive = false;
	
	_has_pending_condition.notify_all();
}

TaskQueue::~TaskQueue()
{
	Kill();
}

TaskPtr TaskQueue::GetNextTask(const bool wait)
{
	bool is_alive = true;
	{
		std::lock_guard<std::mutex> lock(_tasks_mutex);
		
		is_alive = _is_alive;
	}
	
	if (is_alive)
	{
		if (wait)
		{
			WaitForTask();
			
			TaskPtr task = PopTask();
			
			if (task)
			{
				return task;
			}
			else
			{
				return GetNextTask(wait);
			}
		}
		else
		{
			return PopTask();
		}
	}
	else
	{
		return nullptr;
	}
}

TaskPtr TaskQueue::PopTask()
{
	std::lock_guard<std::mutex> lock(_tasks_mutex);
	
	if (!_pending_tasks.empty())
	{
		TaskPtr current_task = _pending_tasks.front();
		
		_pending_tasks.pop();
		
		return current_task;
	}
	else
	{
		return nullptr;
	}
}

void TaskQueue::CompleteTask(TaskPtr task)
{
	std::lock_guard<std::mutex> lock(_tasks_mutex);
	
	auto iter = std::find_if( _tasks.begin(), _tasks.end(), [&task](const TaskPtr& task_iter)
	{
		return task.get() == task_iter.get();
	} );
	
	if (iter != _tasks.end())
	{
		std::swap(_tasks.back(),*iter);
		
		_tasks.pop_back();
	}
}

void TaskQueue::WaitForTask()
{
	std::unique_lock<std::mutex> lock(_tasks_mutex);
	
	_has_pending_condition.wait( lock, [&]()
	{
		return !_pending_tasks.empty() || !_is_alive;
	} );
}
