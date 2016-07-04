#pragma once

#include "../../Code/SystemManager/ITaskProvider.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{

class MockTaskProvider:
	public Fnd::SystemManager::ITaskProvider
{
public:
	
	MockTaskProvider();
	
	bool IsAlive() const;
	
	void SubmitTask(Fnd::SystemManager::TaskPtr task);
	
	void RunNextTask(const bool wait);
	
	void TriggerRunTask();
	
	unsigned int GetRunTaskCount() const;
	
	void Kill();
	
	~MockTaskProvider();
	
private:
	
	bool _is_alive;
	unsigned int _run_task_count;
	mutable std::mutex _count_mutex;
	
	mutable std::mutex _condition_mutex;
	std::condition_variable _has_task_condition;
};

}

}

}
