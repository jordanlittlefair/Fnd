#include "TaskQueueTests.hpp"

#include "MockSystem.hpp"
#include "MockTask.hpp"

#include "../../Code/SystemManager/TaskQueue.hpp"
#include "../../Code/SystemManager/LambdaTask.hpp"

#include <thread>

using namespace Fnd::Test;
using namespace Fnd::Test::SystemManager;
using namespace Fnd::SystemManager;

TaskQueueTests::TaskQueueTests():
UnitTestClass("TaskQueueTests")
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
	AddTestCase( "WaitForTasks_NoTasks_Return", &TaskQueueTests::WaitForTasks_NoTasks_Return, this );
	AddTestCase( "WaitForTasks_OneTask_WaitThenReturn", &TaskQueueTests::WaitForTasks_OneTask_WaitThenReturn, this );
	AddTestCase( "WaitForTasks_TwoTasks_WaitThenReturn", &TaskQueueTests::WaitForTasks_TwoTasks_WaitThenReturn, this );
	AddTestCase( "WaitForTasksWithIds_NoTasks_Return", &TaskQueueTests::WaitForTasksWithIds_NoTasks_Return, this );
	AddTestCase( "WaitForTasksWithIds_OneMatchingTask_WaitThenReturn", &TaskQueueTests::WaitForTasksWithIds_OneMatchingTask_WaitThenReturn, this );
	AddTestCase( "WaitForTasksWithIds_TwoMatchingTasksSameId_WaitThenReturn", &TaskQueueTests::WaitForTasksWithIds_TwoMatchingTasksSameId_WaitThenReturn, this );
	AddTestCase( "WaitForTasksWithIds_TwoMatchingTasksDifferentIds_WaitThenReturn", &TaskQueueTests::WaitForTasksWithIds_TwoMatchingTasksDifferentIds_WaitThenReturn, this );
	AddTestCase( "WaitForTasksWithIds_NoMatchingIds_Return", &TaskQueueTests::WaitForTasksWithIds_NoMatchingIds_Return, this );
	AddTestCase( "WaitForTasksWithIds_OneMatchingOneNotMatching_WaitThenReturn", &TaskQueueTests::WaitForTasksWithIds_OneMatchingOneNotMatching_WaitThenReturn, this );
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
	
	test_case.Assert(tq.GetNumPendingTasks() != 0);
	test_case.Assert(tq.GetNumTasks() != 0);
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

void TaskQueueTests::WaitForTasks_NoTasks_Return(TestCase& test_case)
{
	TaskQueue tq;
	
	tq.WaitForTasks();
}

void TaskQueueTests::WaitForTasks_OneTask_WaitThenReturn(TestCase& test_case)
{
	TaskQueue tq;
	
	SystemPtr system = std::make_shared<MockSystem>(123);
	
	// The task will 'run' and only complete once task_running is set to false and the condition is notified
	std::mutex task_mutex;
	std::atomic<bool> task_running(false);
	std::condition_variable task_running_condition;
	TaskPtr task = CreateLambdaTask(system, [&]()
	{
		std::unique_lock<std::mutex> lock(task_mutex);
		
		// Wait for the task to start
		task_running_condition.wait(lock,[&]
		{
			return task_running.load();
		});
		
		// Then wait for it to end
		task_running_condition.wait(lock,[&]
		{
			return !task_running;
		});
	});
	
	// Add the task so there's something to wait for
	tq.SubmitTask(task);
	
	std::atomic<bool> is_waiting(false);
	// This thread will wait for the task to complete and set the flag
	std::thread waiting_thread = std::thread([&]()
	{
		is_waiting = true;
		
		tq.WaitForTasks();
		
		is_waiting = false;
	});
	
	// This thread will process the tasks
	std::thread running_thread = std::thread([&]()
	{
		tq.RunNextTask(true);
	});
	
	// Force the task to start
	task_running = true;
	task_running_condition.notify_all();
	
	// The task is now running and the waiting_thread is waiting for it
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
	test_case.Assert(is_waiting, "Must be waiting");
	
	// Force the task to complete
	task_running = false;
	
	task_running_condition.notify_all();

	// Make sure the waiting_thread has finished now the task has completed
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
	waiting_thread.join();
	test_case.Assert(!is_waiting, "Must not be waiting");
	
	running_thread.join();
}

void TaskQueueTests::WaitForTasks_TwoTasks_WaitThenReturn(TestCase& test_case)
{
	TaskQueue tq;
	
	SystemPtr system = std::make_shared<MockSystem>(123);
	
	// The task will 'run' and only complete once task_running is set to false and the condition is notified
	std::mutex task_mutex[2];
	std::atomic<bool> task_running[2];
	task_running[0] = task_running[1] = false;
	std::condition_variable task_running_condition[2];
	TaskPtr task[2];
	for(int i = 0; i < 2; ++i)
	{
		task[i] = CreateLambdaTask(system, [&,i]()
		{
			std::unique_lock<std::mutex> lock(task_mutex[i]);
			
			// Wait for the task to start
			task_running_condition[i].wait(lock,[&]
			{
				return !!task_running[i];
			});
			
			// Then wait for it to end
			task_running_condition[i].wait(lock,[&]
			{
				return !task_running[i];
			});
		});
	}
	
	// Add the task so there's something to wait for
	for(int i = 0; i < 2; ++i)
	{
		tq.SubmitTask(task[i]);
	}
	
	std::atomic<bool> is_waiting(false);
	// This thread will wait for the task to complete and set the flag
	std::thread waiting_thread = std::thread([&]()
	{
		is_waiting = true;
		 
		tq.WaitForTasks();
		
		is_waiting = false;
	});
	
	// This thread will process the tasks
	std::thread running_thread = std::thread([&]()
	{
		for(int i = 0; i < 2; ++i)
		{
			tq.RunNextTask(true);
		}
	});
	
	// The task waiting to run and the waiting_thread is waiting for it
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
	test_case.Assert(is_waiting, "Must be waiting");
	
	// Start the first task
	task_running[0] = true;
	task_running_condition[0].notify_all();
	
	// The first task is running and the waiting_thread is waiting for it
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
	test_case.Assert(is_waiting, "Must be waiting");
	
	// Finish the first task
	task_running[0] = false;
	task_running_condition[0].notify_all();
	
	// The first task has completed and the waiting_thread is waiting for the next task
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
	test_case.Assert(is_waiting, "Must be waiting");
	
	// Start the second task
	task_running[1] = true;
	task_running_condition[1].notify_all();
	
	// The second task is running and the waiting_thread is waiting for it
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
	test_case.Assert(is_waiting, "Must be waiting");
	
	// Finish the second task
	task_running[1] = false;
	task_running_condition[1].notify_all();
	
	// Make sure the waiting_thread has finished now the tasks have completed
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
	waiting_thread.join();
	test_case.Assert(!is_waiting, "Must not be waiting");
	
	running_thread.join();
}

void TaskQueueTests::WaitForTasksWithIds_NoTasks_Return(TestCase& test_case)
{
	TaskQueue tq;
	
	tq.WaitForTasks();
}

void TaskQueueTests::WaitForTasksWithIds_OneMatchingTask_WaitThenReturn(TestCase& test_case)
{
	TaskQueue tq;
	
	SystemPtr system = std::make_shared<MockSystem>(123);
	
	// The task will 'run' and only complete once task_running is set to false and the condition is notified
	std::mutex task_mutex;
	std::atomic<bool> task_running(false);
	std::condition_variable task_running_condition;
	TaskPtr task = CreateLambdaTask(system, [&]()
	{
		std::unique_lock<std::mutex> lock(task_mutex);
		
		// Wait for the task to start
		task_running_condition.wait(lock,[&]
		{
			return task_running.load();
		});
		
		// Then wait for it to end
		task_running_condition.wait(lock,[&]
		{
			return !task_running;
		});
	});
	
	// Add the task so there's something to wait for
	tq.SubmitTask(task);
	
	std::atomic<bool> is_waiting(false);
	// This thread will wait for the task to complete and set the flag
	std::thread waiting_thread = std::thread([&]()
	{
		is_waiting = true;
		
		SystemId system_ids[] = { system->GetId() };
		tq.WaitForTasks(system_ids, 1);
		 
		is_waiting = false;
	});
	
	// This thread will process the tasks
	std::thread running_thread = std::thread([&]()
	{
		tq.RunNextTask(true);
	});
	
	// Force the task to start
	task_running = true;
	task_running_condition.notify_all();
	
	// The task is now running and the waiting_thread is waiting for it
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
	test_case.Assert(is_waiting, "Must be waiting");
	
	// Force the task to complete
	task_running = false;
	task_running_condition.notify_all();
	
	// Make sure the waiting_thread has finished now the task has completed
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
	waiting_thread.join();
	test_case.Assert(!is_waiting, "Must not be waiting");
	
	running_thread.join();
}

void TaskQueueTests::WaitForTasksWithIds_TwoMatchingTasksSameId_WaitThenReturn(TestCase& test_case)
{
	TaskQueue tq;
	
	SystemPtr system = std::make_shared<MockSystem>(123);
	
	// The task will 'run' and only complete once task_running is set to false and the condition is notified
	std::mutex task_mutex[2];
	std::atomic<bool> task_running[2];
	task_running[0] = task_running[1] = false;
	std::condition_variable task_running_condition[2];
	TaskPtr task[2];
	for(int i = 0; i < 2; ++i)
	{
		task[i] = CreateLambdaTask(system, [&,i]()
		{
			std::unique_lock<std::mutex> lock(task_mutex[i]);
		   
			// Wait for the task to start
			task_running_condition[i].wait(lock,[&]
			{
				return !!task_running[i];
			});
		   
			// Then wait for it to end
			task_running_condition[i].wait(lock,[&]
			{
				return !task_running[i];
			});
		});
	}
	
	// Add the task so there's something to wait for
	for(int i = 0; i < 2; ++i)
	{
		tq.SubmitTask(task[i]);
	}
	
	std::atomic<bool> is_waiting(false);
	// This thread will wait for the task to complete and set the flag
	std::thread waiting_thread = std::thread([&]()
	{
		is_waiting = true;
		
		SystemId system_ids[] = { system->GetId() };
		
		tq.WaitForTasks(system_ids, 1);
		 
		is_waiting = false;
	});
	
	// This thread will process the tasks
	std::thread running_thread = std::thread([&]()
	{
		for(int i = 0; i < 2; ++i)
		{
			tq.RunNextTask(true);
		}
	});
	
	// The task waiting to run and the waiting_thread is waiting for it
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
	test_case.Assert(is_waiting, "Must be waiting");
	
	// Start the first task
	task_running[0] = true;
	task_running_condition[0].notify_all();
	
	// The first task is running and the waiting_thread is waiting for it
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
	test_case.Assert(is_waiting, "Must be waiting");
	
	// Finish the first task
	task_running[0] = false;
	task_running_condition[0].notify_all();
	
	// The first task has completed and the waiting_thread is waiting for the next task
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
	test_case.Assert(is_waiting, "Must be waiting");
	
	// Start the second task
	task_running[1] = true;
	task_running_condition[1].notify_all();
	
	// The second task is running and the waiting_thread is waiting for it
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
	test_case.Assert(is_waiting, "Must be waiting");
	
	// Finish the second task
	task_running[1] = false;
	task_running_condition[1].notify_all();
	
	// Make sure the waiting_thread has finished now the tasks have completed
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
	waiting_thread.join();
	test_case.Assert(!is_waiting, "Must not be waiting");
	
	running_thread.join();
}

void TaskQueueTests::WaitForTasksWithIds_TwoMatchingTasksDifferentIds_WaitThenReturn(TestCase& test_case)
{
	TaskQueue tq;
	
	SystemPtr system[] = { std::make_shared<MockSystem>(123), std::make_shared<MockSystem>(456) };
	
	// The task will 'run' and only complete once task_running is set to false and the condition is notified
	std::mutex task_mutex[2];
	std::atomic<bool> task_running[2];
	task_running[0] = task_running[1] = false;
	std::condition_variable task_running_condition[2];
	TaskPtr task[2];
	for(int i = 0; i < 2; ++i)
	{
		task[i] = CreateLambdaTask(system[i], [&,i]()
		{
			std::unique_lock<std::mutex> lock(task_mutex[i]);

			// Wait for the task to start
			task_running_condition[i].wait(lock,[&]
			{
				return !!task_running[i];
			});

			// Then wait for it to end
			task_running_condition[i].wait(lock,[&]
			{
				return !task_running[i];
			});
		});
	}
	
	// Add the task so there's something to wait for
	for(int i = 0; i < 2; ++i)
	{
		tq.SubmitTask(task[i]);
	}
	
	std::atomic<bool> is_waiting(false);
	// This thread will wait for the task to complete and set the flag
	std::thread waiting_thread = std::thread([&]()
	{
		is_waiting = true;

		SystemId system_ids[] = { system[0]->GetId(), system[1]->GetId() };

		tq.WaitForTasks(system_ids, 2);

		is_waiting = false;
	});
	
	// This thread will process the tasks
	std::thread running_thread = std::thread([&]()
	{
		for(int i = 0; i < 2; ++i)
		{
			tq.RunNextTask(true);
		}
	});
	
	// The task waiting to run and the waiting_thread is waiting for it
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
	test_case.Assert(is_waiting, "Must be waiting");
	
	// Start the first task
	task_running[0] = true;
	task_running_condition[0].notify_all();
	
	// The first task is running and the waiting_thread is waiting for it
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
	test_case.Assert(is_waiting, "Must be waiting");
	
	// Finish the first task
	task_running[0] = false;
	task_running_condition[0].notify_all();
	
	// The first task has completed and the waiting_thread is waiting for the next task
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
	test_case.Assert(is_waiting, "Must be waiting");
	
	// Start the second task
	task_running[1] = true;
	task_running_condition[1].notify_all();
	
	// The second task is running and the waiting_thread is waiting for it
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
	test_case.Assert(is_waiting, "Must be waiting");
	
	// Finish the second task
	task_running[1] = false;
	task_running_condition[1].notify_all();
	
	// Make sure the waiting_thread has finished now the tasks have completed
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
	waiting_thread.join();
	test_case.Assert(!is_waiting, "Must not be waiting");
	
	running_thread.join();
}

void TaskQueueTests::WaitForTasksWithIds_NoMatchingIds_Return(TestCase& test_case)
{
	TaskQueue tq;
	
	SystemPtr system = std::make_shared<MockSystem>(123);
	
	// The task will 'run' and only complete once task_running is set to false and the condition is notified
	std::mutex task_mutex;
	std::atomic<bool> task_running(false);
	std::condition_variable task_running_condition;
	TaskPtr task = CreateLambdaTask(system, [&]()
	{
		std::unique_lock<std::mutex> lock(task_mutex);

		// Wait for the task to start
		task_running_condition.wait(lock,[&]
		{
			return task_running.load();
		});

		// Then wait for it to end
		task_running_condition.wait(lock,[&]
		{
			return !task_running;
		});
	});
	
	// Add the task so there's something to wait for
	tq.SubmitTask(task);
	
	std::atomic<bool> is_waiting(false);
	// This thread will wait for the task to complete and set the flag
	std::thread waiting_thread = std::thread([&]()
	{
		is_waiting = true;

		SystemId system_ids[] = { 456 };
		tq.WaitForTasks(system_ids, 1);

		is_waiting = false;
	});
	
	// This thread will process the tasks
	std::thread running_thread = std::thread([&]()
	{
		tq.RunNextTask(true);
	});
	
	// Force the task to start
	task_running = true;
	task_running_condition.notify_all();
	
	// The task is now running but the waiting_thread should not be waiting
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
	test_case.Assert(!is_waiting, "Must be waiting");
	
	// Force the task to complete
	task_running = false;
	task_running_condition.notify_all();
	
	// Make sure the waiting_thread has finished now the task has completed
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
	waiting_thread.join();
	test_case.Assert(!is_waiting, "Must not be waiting");
	
	running_thread.join();
}

void TaskQueueTests::WaitForTasksWithIds_OneMatchingOneNotMatching_WaitThenReturn(TestCase& test_case)
{
	TaskQueue tq;
	
	SystemPtr system[] = { std::make_shared<MockSystem>(123), std::make_shared<MockSystem>(456) };
	
	// The task will 'run' and only complete once task_running is set to false and the condition is notified
	std::mutex task_mutex[2];
	std::atomic<bool> task_running[2];
	task_running[0] = task_running[1] = false;
	std::condition_variable task_running_condition[2];
	TaskPtr task[2];
	for(int i = 0; i < 2; ++i)
	{
		task[i] = CreateLambdaTask(system[i], [&,i]()
		{
			std::unique_lock<std::mutex> lock(task_mutex[i]);
		   
			// Wait for the task to start
			task_running_condition[i].wait(lock,[&]
			{
				return !!task_running[i];
			});
			
			// Then wait for it to end
			task_running_condition[i].wait(lock,[&]
			{
				return !task_running[i];
			});
	   });
	}
	
	// Add the task so there's something to wait for
	for(int i = 0; i < 2; ++i)
	{
		tq.SubmitTask(task[i]);
	}
	
	std::atomic<bool> is_waiting(false);
	// This thread will wait for the task to complete and set the flag
	std::thread waiting_thread = std::thread([&]()
	{
		is_waiting = true;
		
		SystemId system_ids[] = { system[0]->GetId() };
		
		tq.WaitForTasks(system_ids,1);
		
		is_waiting = false;
	 });
	
	// This thread will process the tasks
	std::thread running_thread = std::thread([&]()
	{
		for(int i = 0; i < 2; ++i)
		{
			tq.RunNextTask(true);
		}
	});
	
	// The task waiting to run and the waiting_thread is waiting for it
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
	test_case.Assert(is_waiting, "Must be waiting");
	
	// Start the first task
	task_running[0] = true;
	task_running_condition[0].notify_all();
	
	// The first task is running and the waiting_thread is waiting for it
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
	test_case.Assert(is_waiting, "Must be waiting");
	
	// Finish the first task
	task_running[0] = false;
	task_running_condition[0].notify_all();
	
	// The first task has completed and the waiting_thread doesn't need to wait for the second task
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
	test_case.Assert(!is_waiting, "Must not be waiting");
	
	// Start the second task
	task_running[1] = true;
	task_running_condition[1].notify_all();
	
	// The second task is running but the waiting_thread is not waiting for it
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
	test_case.Assert(!is_waiting, "Must not be waiting");
	
	// Finish the second task
	task_running[1] = false;
	task_running_condition[1].notify_all();
	
	// Make sure the waiting_thread has finished now the tasks have completed
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
	waiting_thread.join();
	test_case.Assert(!is_waiting, "Must not be waiting");
	
	running_thread.join();
}
