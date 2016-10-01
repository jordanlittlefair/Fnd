#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{

class TaskProcessorThreadTests:
	public UnitTestClass
{
public:
	
	TaskProcessorThreadTests();
	
private:
	
	void IsAlive_BeforeStart_False(TestCase& test_case);
	void IsAlive_AfterStart_True(TestCase& test_case);
	void IsAlive_AfterKill_False(TestCase& test_case);
	void Start_ProcessesTask_One(TestCase& test_case);
	void Start_ProcessesTask_Two(TestCase& test_case);
};

}

}

}
