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
	void WaitForTasks_NoTasks_Return(TestCase& test_case);
	void WaitForTasks_OneTask_WaitThenReturn(TestCase& test_case);
	void WaitForTasks_TwoTasks_WaitThenReturn(TestCase& test_case);
	void WaitForTasksWithIds_NoTasks_Return(TestCase& test_case);
	void WaitForTasksWithIds_OneMatchingTask_WaitThenReturn(TestCase& test_case);
	void WaitForTasksWithIds_TwoMatchingTasksSameId_WaitThenReturn(TestCase& test_case);
	void WaitForTasksWithIds_TwoMatchingTasksDifferentIds_WaitThenReturn(TestCase& test_case);
	void WaitForTasksWithIds_NoMatchingIds_Return(TestCase& test_case);
	void WaitForTasksWithIds_OneMatchingOneNotMatching_WaitThenReturn(TestCase& test_case);
};

}

}

}
