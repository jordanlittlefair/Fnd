#include "LambdaTaskTests.hpp"

#include "MockSystem.hpp"
#include "../../Code/SystemManager/LambdaTask.hpp"

using namespace Fnd::Test;
using namespace Fnd::Test::SystemManager;
using namespace Fnd::SystemManager;

LambdaTaskTests::LambdaTaskTests():
	UnitTestClass("LambdaTaskTests")
{
	AddTestCase( "TestGetParentSystemId", &LambdaTaskTests::TestGetParentSystemId, this );
	AddTestCase( "TestOnRunLambda", &LambdaTaskTests::TestOnRunLambda, this );
	AddTestCase( "TestSuccessStates", &LambdaTaskTests::TestSuccessStates, this );
}

void LambdaTaskTests::TestGetParentSystemId( TestCase& test_case )
{
	const SystemId id = 123;
	
	auto parent_system = std::make_shared<MockSystem>(id);
	
	auto lt = CreateLambdaTask( parent_system, [](){} );
	
	test_case.Assert( lt->GetParentSystemId() == id );
}

void LambdaTaskTests::TestOnRunLambda(Fnd::Test::TestCase &test_case )
{
	auto parent_system = std::make_shared<MockSystem>(123);

	bool hitOnRunLambda = false;

	auto lt = CreateLambdaTask( parent_system, [&]() { hitOnRunLambda = true; } );
	
	test_case.Assert( !hitOnRunLambda );
	
	lt->Run();
	
	test_case.Assert( hitOnRunLambda );
}

void LambdaTaskTests::TestSuccessStates( TestCase& test_case )
{
	auto parent_system = std::make_shared<MockSystem>(123);
	
	Task::State runningState = Task::State::Pending;
	
	std::shared_ptr<Task> delegate;
	
	auto lt = CreateLambdaTask( parent_system, [&]() { runningState = delegate->GetState(); } );
	
	delegate = lt;
	
	test_case.Assert( lt->GetState() == Task::State::Pending );
	
	lt->Run();
	
	test_case.Assert( runningState == Task::State::Running );
	test_case.Assert( lt->GetState() == Task::State::Complete );
}
