#pragma once

#include "ITaskProvider.hpp"

#include <map>
#include <mutex>
#include <queue>

namespace Fnd
{

namespace SystemManager
{

class TaskQueue:
	public ITaskProvider
{
public:
	
	TaskQueue();
	
	bool IsAlive() const;
	
	void SubmitTask(TaskPtr task);
	
	void RunNextTask(const bool wait);
	
	unsigned int GetNumPendingTasks() const;
	
	unsigned int GetNumTasks() const;
	
	void Kill();
	
	~TaskQueue();
	
private:
	
	TaskPtr GetNextTask(const bool wait);
	
	TaskPtr PopTask();
	
	void CompleteTask(TaskPtr task);
	
	void WaitForTask();	// Waits and returns when a task is available or the TaskQueue is killed (to prevent blocking).
	
private:
	
	bool _is_alive;	/// Set to false Kill is called so GetNextTasks knows it shouldn't expect any new tasks.
	
	std::vector<TaskPtr> _tasks;
	
	std::queue<TaskPtr> _pending_tasks;
	mutable std::mutex _tasks_mutex;
	std::condition_variable _has_pending_condition;
};

}
	
}
