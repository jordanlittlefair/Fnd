#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{

class ConcurrentTaskProcessorTests:
public UnitTestClass
{
public:
	
	ConcurrentTaskProcessorTests();
	
private:
	
	void IsRunning_BeforeStart_False(TestCase& test_case);
	void IsRunning_AfterStart_True(TestCase& test_case);
	void IsRunning_AfterKill_False(TestCase& test_case);
	void Start_ProcessesTask_OneTask_OneThread(TestCase& test_case);
	void Start_ProcessesTask_TenTasks_FiveThreads(TestCase& test_case);
};

}

}

}
