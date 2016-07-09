#include "MockTaskProvider.hpp"

using namespace Fnd::SystemManager;
using namespace Fnd::Test::SystemManager;

MockTaskProvider::MockTaskProvider():
	_is_alive(true),
	_run_task_count(0)
{
}

bool MockTaskProvider::IsAlive() const
{
	std::lock_guard<std::mutex> lock(_condition_mutex);

	return _is_alive;
}

void MockTaskProvider::SubmitTask(TaskPtr task)
{
	// Do nothing
}

void MockTaskProvider::RunNextTask(const bool wait)
{
	bool is_alive = true;
	{
		std::lock_guard<std::mutex> lock(_condition_mutex);
		
		is_alive = _is_alive;
	}
	
	if (is_alive)
	{
		if (wait)
		{
			std::unique_lock<std::mutex> lock(_condition_mutex);
		
			_has_task_condition.wait(lock);
		
			if (_is_alive)
			{
				std::lock_guard<std::mutex> lock(_count_mutex);
			
				++_run_task_count;
			}
		}
		else
		{
			std::lock_guard<std::mutex> lock(_count_mutex);
		
			++_run_task_count;
		}
	}
}

void MockTaskProvider::TriggerRunTask()
{
	_has_task_condition.notify_all();
}

unsigned int MockTaskProvider::GetRunTaskCount() const
{
	std::lock_guard<std::mutex> lock(_count_mutex);
	
	return _run_task_count;
}

void MockTaskProvider::Kill()
{
	std::lock_guard<std::mutex> lock(_condition_mutex);
	
	_is_alive = false;
	
	_has_task_condition.notify_all();
}

MockTaskProvider::~MockTaskProvider()
{
	Kill();
}