#pragma once

#include "../Framework/TestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{

class TaskProcessorThreadTests:
	public TestClass
{
public:
	
	TaskProcessorThreadTests();
	
private:
	
	void IsRunning_BeforeStart_False(TestCase& test_case);
	void IsRunning_AfterStart_True(TestCase& test_case);
	void IsRunning_AfterKill_False(TestCase& test_case);
	void Start_ProcessesTask_One(TestCase& test_case);
	void Start_ProcessesTask_Two(TestCase& test_case);
};

}

}

}
