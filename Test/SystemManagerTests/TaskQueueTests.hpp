#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{

class TaskQueueTests:
	public UnitTestClass
{
public:

	TaskQueueTests();

private:

	void IsAlive_OnStartup_True(TestCase& test_case);
	void IsAlive_AfterKill_False(TestCase& test_case);
	void SumbitTask_Single_Success(TestCase& test_case);
	void RunNextTask_NoTasks_NoWait_Success(TestCase& test_case);
	void RunNextTask_NoTasks_Wait_Success(TestCase& test_case);
	void RunNextTask_Single_NoWait_Success(TestCase& test_case);
	void RunNextTask_Single_Wait_Success(TestCase& test_case);
	void SumbitTask_WhileRunningTask_Success(TestCase& test_case);
	void GetNumPendingTasks_None(TestCase& test_case);
	void GetNumPendingTasks_One(TestCase& test_case);
	void GetNumTasks_None(TestCase& test_case);
	void GetNumTasks_OnePending(TestCase& test_case);
	void GetNumTasks_OnePendingOneRunning(TestCase& test_case);
};

}

}

}
