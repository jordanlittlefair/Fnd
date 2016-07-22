#include "TaskProcessorThreadTests.hpp"

#include "MockTaskProvider.hpp"
#include "../../Code/SystemManager/TaskProcessorThread.hpp"

using namespace Fnd::Test;
using namespace Fnd::Test::SystemManager;
using namespace Fnd::SystemManager;

TaskProcessorThreadTests::TaskProcessorThreadTests():
TestClass("TaskProcessorThreadTests")
{
	AddTestCase( "IsAlive_BeforeStart_False", &TaskProcessorThreadTests::IsAlive_BeforeStart_False, this );
	AddTestCase( "IsAlive_AfterStart_True", &TaskProcessorThreadTests::IsAlive_AfterStart_True, this );
	AddTestCase( "IsAlive_AfterKill_False", &TaskProcessorThreadTests::IsAlive_AfterKill_False, this );
	AddTestCase( "Start_ProcessesTask_One", &TaskProcessorThreadTests::Start_ProcessesTask_One, this );
	AddTestCase( "Start_ProcessesTask_Two", &TaskProcessorThreadTests::Start_ProcessesTask_Two, this );

}

void TaskProcessorThreadTests::IsAlive_BeforeStart_False(TestCase& test_case)
{
	TaskProcessorThread tpt;
	
	test_case.Assert(!tpt.IsAlive());
}

void TaskProcessorThreadTests::IsAlive_AfterStart_True(TestCase& test_case)
{
	TaskProcessorThread tpt;
	
	auto provider = std::make_shared<MockTaskProvider>();
	
	tpt.SetTaskProvider(provider);
	
	tpt.Start();
	
	test_case.Assert(tpt.IsAlive());
	
	provider->Kill();
}

void TaskProcessorThreadTests::IsAlive_AfterKill_False(TestCase& test_case)
{
	TaskProcessorThread tpt;
	
	auto provider = std::make_shared<MockTaskProvider>();
	
	tpt.SetTaskProvider(provider);
	
	tpt.Start();
	
	test_case.Assert(tpt.IsAlive());
	
	provider->Kill();
	
	tpt.Kill();
	
	test_case.Assert(!tpt.IsAlive());
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
