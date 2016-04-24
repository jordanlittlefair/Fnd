#include "TaskTests.hpp"

#include "MockSystem.hpp"
#include "MockTask.hpp"

using namespace Fnd::Test::SystemManager;
using namespace Fnd::SystemManager;

TaskTests::TaskTests():
	TestClass("TaskTests")
{
	AddTestCase( "TestGetParentSystemId", &TaskTests::TestGetParentSystemId, this );
	AddTestCase( "TestRun", &TaskTests::TestRun, this );
	AddTestCase( "TestSuccessStates", &TaskTests::TestSuccessStates, this );
	AddTestCase( "TestErrorStatesAndException", &TaskTests::TestErrorStatesAndException, this );
}

void TaskTests::TestGetParentSystemId( TestCase& test_case )
{
	const ISystem::Id id = "_id_";
	
	auto parent_system = std::make_shared<MockSystem>(id);
	
	MockTask mt(parent_system);
	
	test_case.Assert( mt.GetParentSystemId() == id );
}

void TaskTests::TestRun(Fnd::Test::TestCase &test_case )
{
	auto parent_system = std::make_shared<MockSystem>("id");
	
	MockTask mt( parent_system );
	
	test_case.Assert( mt.GetOnRunHitCount() == 0 );
	
	mt.Run();
	
	test_case.Assert( mt.GetOnRunHitCount() == 1 );
}

void TaskTests::TestSuccessStates( TestCase& test_case )
{
	auto parent_system = std::make_shared<MockSystem>("id");

	MockTask mt( parent_system );
	
	test_case.Assert( mt.GetState() == Task::State::Pending );
	
	mt.Run();
	
	test_case.Assert( mt.GetStateInOnRun() == Task::State::Running );
	test_case.Assert( mt.GetState() == Task::State::Complete );
}

void TaskTests::TestErrorStatesAndException( TestCase& test_case )
{
	auto parent_system = std::make_shared<MockSystem>("id");
	
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
	catch ( const std::runtime_error& ex )
	{
		exceptionHit = true;
	}
	
	test_case.Assert(exceptionHit);
}
