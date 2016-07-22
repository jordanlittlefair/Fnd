#include "ConcurrentTaskProcessorTests.hpp"

#include "MockSystem.hpp"
#include "MockTaskProvider.hpp"
#include "../../Code/SystemManager/ConcurrentTaskProcessor.hpp"
#include "../../Code/SystemManager/LambdaTask.hpp"
#include "../../Code/SystemManager/TaskQueue.hpp"

using namespace Fnd::Test;
using namespace Fnd::Test::SystemManager;
using namespace Fnd::SystemManager;

ConcurrentTaskProcessorTests::ConcurrentTaskProcessorTests():
	TestClass("ConcurrentTaskProcessorTests")
{
	AddTestCase( "IsRunning_BeforeStart_False", &ConcurrentTaskProcessorTests::IsRunning_BeforeStart_False, this );
	AddTestCase( "IsRunning_AfterStart_True", &ConcurrentTaskProcessorTests::IsRunning_AfterStart_True, this );
	AddTestCase( "IsRunning_AfterKill_False", &ConcurrentTaskProcessorTests::IsRunning_AfterKill_False, this );
	AddTestCase( "Start_ProcessesTask_OneTask_OneThread", &ConcurrentTaskProcessorTests::Start_ProcessesTask_OneTask_OneThread, this );
	AddTestCase( "Start_ProcessesTask_TenTasks_FiveThreads", &ConcurrentTaskProcessorTests::Start_ProcessesTask_TenTasks_FiveThreads, this );
}

void ConcurrentTaskProcessorTests::IsRunning_BeforeStart_False(TestCase& test_case)
{
	ConcurrentTaskProcessor ctp(1);
	
	test_case.Assert(!ctp.IsAlive());
}

void ConcurrentTaskProcessorTests::IsRunning_AfterStart_True(TestCase& test_case)
{
	ConcurrentTaskProcessor ctp(1);
	
	auto provider = std::make_shared<MockTaskProvider>();
	
	ctp.SetTaskProvider(provider);
	
	ctp.Start();
	
	test_case.Assert(ctp.IsAlive());
	
	provider->Kill();

	ctp.Kill();
}

void ConcurrentTaskProcessorTests::IsRunning_AfterKill_False(TestCase& test_case)
{
	ConcurrentTaskProcessor ctp(1);
	
	auto provider = std::make_shared<MockTaskProvider>();
	
	ctp.SetTaskProvider(provider);
	
	ctp.Start();
	
	test_case.Assert(ctp.IsAlive());
	
	provider->Kill();
	
	ctp.Kill();
	
	test_case.Assert(!ctp.IsAlive());
}

void ConcurrentTaskProcessorTests::Start_ProcessesTask_OneTask_OneThread(TestCase& test_case)
{
	ConcurrentTaskProcessor ctp(1);
	
	auto provider = std::make_shared<TaskQueue>();
	
	auto system = std::make_shared<MockSystem>(123);
	
	ctp.SetTaskProvider(provider);
	
	ctp.Start();
	
	auto task = CreateLambdaTask(system, [&]()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	});
	
	provider->SubmitTask(task);
	
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	
	test_case.Assert(task->GetState() == Task::State::Complete);
	
	provider->Kill();
	
	ctp.Kill();
}

void ConcurrentTaskProcessorTests::Start_ProcessesTask_TenTasks_FiveThreads(TestCase& test_case)
{
	ConcurrentTaskProcessor ctp(5);
	
	auto provider = std::make_shared<TaskQueue>();
	
	auto system = std::make_shared<MockSystem>(123);
	
	ctp.SetTaskProvider(provider);
	
	std::vector<TaskPtr> tasks;
	std::map<std::thread::id,unsigned int> task_thread_ids;
	std::mutex task_thread_ids_mutex;
	
	for (unsigned int i = 0; i < 10; ++i)
	{
		auto task = CreateLambdaTask(system, [&,i]()
		{
			int index = i;
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			
			std::lock_guard<std::mutex> lock(task_thread_ids_mutex);
			task_thread_ids[std::this_thread::get_id()]++;
		});
		
		provider->SubmitTask(task);
		
		tasks.push_back(task);
	}

	ctp.Start();
	
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	
	provider->Kill();
	
	ctp.Kill();
	
	for (auto& task : tasks)
	{
		test_case.Assert(task->GetState() == Task::State::Complete);
	}
	
	test_case.Assert(task_thread_ids.size() == 5, "Each thread has executed tasks");
}
