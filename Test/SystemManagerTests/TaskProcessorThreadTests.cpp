#include "TaskProcessorThreadTests.hpp"

#include "MockTaskProvider.hpp"
#include "../../Code/SystemManager/TaskProcessorThread.hpp"

using namespace Fnd::Test;
using namespace Fnd::Test::SystemManager;
using namespace Fnd::SystemManager;

TaskProcessorThreadTests::TaskProcessorThreadTests():
TestClass("TaskProcessorThreadTests")
{
	AddTestCase( "IsRunning_BeforeStart_False", &TaskProcessorThreadTests::IsRunning_BeforeStart_False, this );
	AddTestCase( "IsRunning_AfterStart_True", &TaskProcessorThreadTests::IsRunning_AfterStart_True, this );
	AddTestCase( "IsRunning_AfterKill_False", &TaskProcessorThreadTests::IsRunning_AfterKill_False, this );
	AddTestCase( "Start_ProcessesTask_One", &TaskProcessorThreadTests::Start_ProcessesTask_One, this );
	AddTestCase( "Start_ProcessesTask_Two", &TaskProcessorThreadTests::Start_ProcessesTask_Two, this );

}

void TaskProcessorThreadTests::IsRunning_BeforeStart_False(TestCase& test_case)
{
	TaskProcessorThread tpt;
	
	test_case.Assert(!tpt.IsRunning());
}

void TaskProcessorThreadTests::IsRunning_AfterStart_True(TestCase& test_case)
{
	TaskProcessorThread tpt;
	
	auto provider = std::make_shared<MockTaskProvider>();
	
	tpt.SetTaskProvider(provider);
	
	tpt.Start();
	
	test_case.Assert(tpt.IsRunning());
	
	provider->Kill();
}

void TaskProcessorThreadTests::IsRunning_AfterKill_False(TestCase& test_case)
{
	TaskProcessorThread tpt;
	
	auto provider = std::make_shared<MockTaskProvider>();
	
	tpt.SetTaskProvider(provider);
	
	tpt.Start();
	
	test_case.Assert(tpt.IsRunning());
	
	provider->Kill();
	
	tpt.Kill();
	
	test_case.Assert(!tpt.IsRunning());
}

void TaskProcessorThreadTests::Start_ProcessesTask_One(TestCase& test_case)
{
	TaskProcessorThread tpt;
	
	auto provider = std::make_shared<MockTaskProvider>();
	
	tpt.SetTaskProvider(provider);
	
	tpt.Start();
	
	test_case.Assert(provider->GetRunTaskCount() == 0);
	
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	
	provider->TriggerRunTask();
	
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	
	test_case.Assert(provider->GetRunTaskCount() == 1);
	
	provider->Kill();
	
	tpt.Kill();
}

void TaskProcessorThreadTests::Start_ProcessesTask_Two(TestCase& test_case)
{
	TaskProcessorThread tpt;
	
	auto provider = std::make_shared<MockTaskProvider>();
	
	tpt.SetTaskProvider(provider);
	
	tpt.Start();
	
	test_case.Assert(provider->GetRunTaskCount() == 0);
	
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	
	provider->TriggerRunTask();
	
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	
	test_case.Assert(provider->GetRunTaskCount() == 1);
	
	provider->TriggerRunTask();
	
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	
	test_case.Assert(provider->GetRunTaskCount() == 2);
	
	provider->Kill();
	
	tpt.Kill();
}
