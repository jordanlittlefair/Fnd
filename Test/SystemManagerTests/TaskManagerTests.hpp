#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{

class TaskManagerTests:
	public UnitTestClass
{
public:
	
	TaskManagerTests();
	
private:
	
	void Constructor_IsInitialised_False(TestCase& test_case);
	void Initialise_TaskProvider_IsSet(TestCase& test_case);
	void Initialise_TaskConsumer_IsSet(TestCase& test_case);
	void Initialise_IsInitialised(TestCase& test_case);
	void Start_BeforeInitialised_NotAlive(TestCase& test_case);
	void Start_AfterInitialised_Alive(TestCase& test_case);
	void IsAlive_BeforeStart_False(TestCase& test_case);
	void IsAlive_AfterStart_True(TestCase& test_case);
	void IsAlive_AfterKill_False(TestCase& test_case);
	void Kill_BeforeInitialise_DoNothing(TestCase& test_case);
	void Kill_BeforeStart_DoNothing(TestCase& test_case);
	void Kill_AfterStart_Success(TestCase& test_case);
	void Kill_Twice_DoNothing(TestCase& test_case);
	
	// All WaitForTasks() and WaitForTasksWithIds(,) tests are handled in TaskQueueTests - TaskManager is just a wrapper
};

}

}

}
