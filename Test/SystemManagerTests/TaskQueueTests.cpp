#include "TaskQueueTests.hpp"

#include "MockSystem.hpp"

#include "../../Code/SystemManager/TaskQueue.hpp"
#include "../../Code/SystemManager/LambdaTask.hpp"

#include <thread>

using namespace Fnd::Test;
using namespace Fnd::Test::SystemManager;
using namespace Fnd::SystemManager;

TaskQueueTests::TaskQueueTests():
TestClass("TaskQueueTests")
{
	AddTestCase( "IsAlive_OnStartup_True", &TaskQueueTests::IsAlive_OnStartup_True, this );
	AddTestCase( "IsAlive_AfterKill_False", &TaskQueueTests::IsAlive_AfterKill_False, this );
	AddTestCase( "SumbitTask_Single_Success", &TaskQueueTests::SumbitTask_Single_Success, this );
	AddTestCase( "RunNextTask_NoTasks_NoWait_Success", &TaskQueueTests::RunNextTask_NoTasks_NoWait_Success, this );
	AddTestCase( "RunNextTask_NoTasks_Wait_Success", &TaskQueueTests::RunNextTask_NoTasks_Wait_Success, this );
	AddTestCase( "RunNextTask_Single_NoWait_Success", &TaskQueueTests::RunNextTask_Single_NoWait_Success, this );
	AddTestCase( "RunNextTask_Single_Wait_Success", &TaskQueueTests::RunNextTask_Single_Wait_Success, this );
	AddTestCase( "SumbitTask_WhileRunningTask_Success", &TaskQueueTests::SumbitTask_WhileRunningTask_Success, this );
	AddTestCase( "GetNumPendingTasks_None", &TaskQueueTests::GetNumPendingTasks_None, this );
	AddTestCase( "GetNumPendingTasks_One", &TaskQueueTests::GetNumPendingTasks_One, this );
	AddTestCase( "GetNumTasks_None", &TaskQueueTests::GetNumTasks_None, this );
	AddTestCase( "GetNumTasks_OnePending", &TaskQueueTests::GetNumTasks_OnePending, this );
	AddTestCase( "GetNumTasks_OnePendingOneRunning", &TaskQueueTests::GetNumTasks_OnePendingOneRunning, this );
}

void TaskQueueTests::IsAlive_OnStartup_True(TestCase& test_case)
{
	TaskQueue tq;
	
	test_case.Assert(tq.IsAlive());
}

void TaskQueueTests::IsAlive_AfterKill_False(TestCase& test_case)
{
	TaskQueue tq;
	
	tq.Kill();
	
	test_case.Assert(!tq.IsAlive());
}

void TaskQueueTests::SumbitTask_Single_Success(TestCase& test_case)
{
	TaskQueue tq;
	
	SystemPtr system = std::make_shared<MockSystem>(123);
	
	TaskPtr task = CreateLambdaTask(system, [](){});
	
	tq.SubmitTask(task);
	
	test_case.Assert(tq.GetNumPendingTasks());
	test_case.Assert(tq.GetNumTasks());
}

void TaskQueueTests::RunNextTask_NoTasks_NoWait_Success(TestCase& test_case)
{
	TaskQueue tq;
	
	tq.RunNextTask(false);
}

void TaskQueueTests::RunNextTask_NoTasks_Wait_Success(TestCase& test_case)
{
	TaskQueue tq;
	
	bool has_killed_provider = false;
	
	std::thread kill_provider([&]()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		
		has_killed_provider = true;
		
		tq.Kill();
		
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	});
	
	test_case.Assert(!has_killed_provider);
	
	tq.RunNextTask(true); // Waits here until kill_provider thread kills tq
	
	kill_provider.join(); // Waits here until kill_provider thread finishes
	
	test_case.Assert(has_killed_provider);
}

void TaskQueueTests::RunNextTask_Single_NoWait_Success(TestCase& test_case)
{
	TaskQueue tq;
	
	SystemPtr system = std::make_shared<MockSystem>(123);
	
	TaskPtr task = CreateLambdaTask(system, [](){});
	
	tq.SubmitTask(task);
	
	test_case.Assert(task->GetState() == Task::State::Pending);
	
	tq.RunNextTask(false);
	
	test_case.Assert(task->GetState() == Task::State::Complete);
}

void TaskQueueTests::RunNextTask_Single_Wait_Success(TestCase& test_case)
{
	TaskQueue tq;
	
	SystemPtr system = std::make_shared<MockSystem>(123);
	
	TaskPtr task = CreateLambdaTask(system, [](){});
	
	tq.SubmitTask(task);
	
	test_case.Assert(task->GetState() == Task::State::Pending);
	
	tq.RunNextTask(true);
	
	test_case.Assert(task->GetState() == Task::State::Complete);
}

void TaskQueueTests::SumbitTask_WhileRunningTask_Success(TestCase& test_case)
{
	TaskQueue tq;
	
	SystemPtr system = std::make_shared<MockSystem>(123);
	
	TaskPtr task = CreateLambdaTask(system, [](){});
	
	bool is_submitted = false;
	
	std::thread submit_thread([&]()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		
		tq.SubmitTask(task);
		
		is_submitted = true;
		
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	});
	
	test_case.Assert(task->GetState() == Task::State::Pending);
	
	tq.RunNextTask(true); // Waits here until the task is sumbitted and completed
	
	submit_thread.join(); // Waits here until submit_thread finishes
	
	test_case.Assert(is_submitted);
	test_case.Assert(task->GetState() == Task::State::Complete);
}

void TaskQueueTests::GetNumPendingTasks_None(TestCase& test_case)
{
	TaskQueue tq;
	
	test_case.Assert(tq.GetNumPendingTasks() == 0);
}

void TaskQueueTests::GetNumPendingTasks_One(TestCase& test_case)
{
	TaskQueue tq;
	
	SystemPtr system = std::make_shared<MockSystem>(123);
	
	TaskPtr task = CreateLambdaTask(system, [](){});
	
	tq.SubmitTask(task);

	test_case.Assert(tq.GetNumPendingTasks() == 1);
}

void TaskQueueTests::GetNumTasks_None(TestCase& test_case)
{
	TaskQueue tq;
	
	test_case.Assert(tq.GetNumTasks() == 0);
}

void TaskQueueTests::GetNumTasks_OnePending(TestCase& test_case)
{
	TaskQueue tq;
	
	SystemPtr system = std::make_shared<MockSystem>(123);
	
	TaskPtr task = CreateLambdaTask(system, [](){});
	
	tq.SubmitTask(task);
	
	test_case.Assert(tq.GetNumTasks() == 1);
}

void TaskQueueTests::GetNumTasks_OnePendingOneRunning(TestCase& test_case)
{
	TaskQueue tq;
	
	SystemPtr system = std::make_shared<MockSystem>(123);
	
	std::mutex task_mutex;
	bool task_running = false;
	std::condition_variable task_running_condition;
	
	TaskPtr running_task = CreateLambdaTask(system, [&]()
	{
		std::unique_lock<std::mutex> lock(task_mutex);
		
		task_running = true;
			
		task_running_condition.wait(lock,[&]
		{
			return !task_running;
		});
	});
	
	TaskPtr pending_task = CreateLambdaTask(system, [](){});
	
	tq.SubmitTask(running_task);
	tq.SubmitTask(pending_task);
	
	test_case.Assert(tq.GetNumPendingTasks() == 2);
	test_case.Assert(tq.GetNumTasks() == 2);
	
	std::thread run_task_thread([&]()
	{
		tq.RunNextTask(true); // Waits here until the first task (running_task) is complete
	});
	
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	
	test_case.Assert(tq.GetNumPendingTasks() == 1);
	test_case.Assert(tq.GetNumTasks() == 2);
	
	// Stop the thread from running - it should complete after the call to notify_all()
	task_running = false;
	task_running_condition.notify_all();
	
	run_task_thread.join();	// Waits here until the first task (running_task) is complete
	
	test_case.Assert(running_task->GetState() == Task::State::Complete);
	test_case.Assert(pending_task->GetState() == Task::State::Pending);
	
	test_case.Assert(tq.GetNumPendingTasks() == 1);
	test_case.Assert(tq.GetNumTasks() == 1);
	
}
