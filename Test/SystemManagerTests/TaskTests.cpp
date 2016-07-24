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
