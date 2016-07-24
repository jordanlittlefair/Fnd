#include "TaskTests.hpp"

#include "MockSystem.hpp"
#include "MockTask.hpp"

#include <thread>

using namespace Fnd::Test;
using namespace Fnd::Test::SystemManager;
using namespace Fnd::SystemManager;

TaskTests::TaskTests():
	UnitTestClass("TaskTests")
{
	AddTestCase( "TestGetParentSystemId", &TaskTests::TestGetParentSystemId, this );
	AddTestCase( "TestRun", &TaskTests::TestRun, this );
	AddTestCase( "TestSuccessStates", &TaskTests::TestSuccessStates, this );
	AddTestCase( "TestErrorStatesAndException", &TaskTests::TestErrorStatesAndException, this );
	AddTestCase( "TestWait_Complete", &TaskTests::TestWait_Complete, this );
	AddTestCase( "TestWait_Exception", &TaskTests::TestWait_Exception, this );
}

void TaskTests::TestGetParentSystemId( TestCase& test_case )
{
	const SystemId id = 123;
	
	auto parent_system = std::make_shared<MockSystem>(id);
	
	MockTask mt(parent_system);
	
	test_case.Assert( mt.GetParentSystemId() == id );
}

void TaskTests::TestRun(Fnd::Test::TestCase &test_case )
{
	auto parent_system = std::make_shared<MockSystem>(123);
	
	MockTask mt( parent_system );
	
	test_case.Assert( mt.GetOnRunHitCount() == 0 );
	
	mt.Run();
	
	test_case.Assert( mt.GetOnRunHitCount() == 1 );
}

void TaskTests::TestSuccessStates( TestCase& test_case )
{
	auto parent_system = std::make_shared<MockSystem>(123);

	MockTask mt( parent_system );
	
	test_case.Assert( mt.GetState() == Task::State::Pending );
	
	mt.Run();
	
	test_case.Assert( mt.GetStateInOnRun() == Task::State::Running );
	test_case.Assert( mt.GetState() == Task::State::Complete );
}

void TaskTests::TestErrorStatesAndException( TestCase& test_case )
{
	auto parent_system = std::make_shared<MockSystem>(123);
	
	MockTask mt( parent_system );
	mt.SetForceError( std::runtime_error("Forced exception") );
	
	test_case.Assert( mt.GetState() == Task::State::Pending );
	
	mt.Run();
	
	test_case.Assert( mt.GetStateInOnRun() == Task::State::Running );
	test_case.Assert( mt.GetState() == Task::State::ExceptionThrown );
	
	bool exceptionHit = false;
	
	try
	{
		mt.RethrowException();
	}
	catch (const std::runtime_error&)
	{
		exceptionHit = true;
	}
	
	test_case.Assert(exceptionHit);
}

void TaskTests::TestWait_Complete( TestCase& test_case )
{
	auto parent_system = std::make_shared<MockSystem>(123);
	
	MockTask mt( parent_system );
	
	test_case.Assert( mt.GetState() == Task::State::Pending );
	
	std::thread run_thread( [&]() { std::this_thread::sleep_for(std::chrono::milliseconds(100)); mt.Run(); } );
	
	mt.Wait();
	
	test_case.Assert( mt.GetStateInOnRun() == Task::State::Running );
	test_case.Assert( mt.GetState() == Task::State::Complete );
	
	run_thread.join();
}

void TaskTests::TestWait_Exception( TestCase& test_case )
{
	auto parent_system = std::make_shared<MockSystem>(123);
	
	MockTask mt( parent_system );
	mt.SetForceError( std::runtime_error("Forced exception") );
	
	test_case.Assert( mt.GetState() == Task::State::Pending );
	
	std::thread run_thread( [&]() { std::this_thread::sleep_for(std::chrono::milliseconds(100)); mt.Run(); } );
	
	mt.Wait();
	
	test_case.Assert( mt.GetStateInOnRun() == Task::State::Running );
	test_case.Assert( mt.GetState() == Task::State::ExceptionThrown );
	
	bool exceptionHit = false;
	
	try
	{
	mt.RethrowException();
	}
	catch (const std::runtime_error&)
	{
	exceptionHit = true;
	}
	
	test_case.Assert(exceptionHit);
	
	run_thread.join();
}
