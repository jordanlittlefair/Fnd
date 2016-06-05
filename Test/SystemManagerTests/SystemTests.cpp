#include "SystemTests.hpp"

#include "MockSystem.hpp"

using namespace Fnd::Test;
using namespace Fnd::Test::SystemManager;

SystemTests::SystemTests():
	TestClass("SystemTests")
{
	AddTestCase( "TestGetId", &SystemTests::TestGetId, this );
	AddTestCase( "TestAddDependency", &SystemTests::TestAddDependency, this );
	AddTestCase( "TestAddDependency_Duplicate", &SystemTests::TestAddDependency_Duplicate, this );
}

void SystemTests::TestGetId( TestCase& test_case )
{
	const MockSystem::Id id = "system_id";
	
	MockSystem system( id );
	
	test_case.Assert( system.GetId() == id );
}

void SystemTests::TestAddDependency( TestCase& test_case )
{
	const MockSystem::Id dep1 = "dep1";
	const MockSystem::Id dep2 = "dep2";

	MockSystem system( "id" );
	
	system.AddDependency( dep1 );
	
	test_case.Assert( system.GetDependencies().size() == 1 );
	test_case.Assert( std::find( system.GetDependencies().begin(), system.GetDependencies().end(), dep1 ) != system.GetDependencies().end() );
	test_case.Assert( std::find( system.GetDependencies().begin(), system.GetDependencies().end(), dep2 ) == system.GetDependencies().end() );
	
	system.AddDependency( dep2 );

	test_case.Assert( system.GetDependencies().size() == 2 );
	test_case.Assert( std::find( system.GetDependencies().begin(), system.GetDependencies().end(), dep1 ) != system.GetDependencies().end() );
	test_case.Assert( std::find( system.GetDependencies().begin(), system.GetDependencies().end(), dep2 ) != system.GetDependencies().end() );
}

void SystemTests::TestAddDependency_Duplicate( TestCase& test_case )
{
	const MockSystem::Id dep1 = "dep1";
	
	MockSystem system( "id" );
	
	system.AddDependency( dep1 );
	
	test_case.Assert( system.GetDependencies().size() == 1 );
	test_case.Assert( std::find( system.GetDependencies().begin(), system.GetDependencies().end(), dep1 ) != system.GetDependencies().end() );
	
	system.AddDependency( dep1 );
	
	test_case.Assert( system.GetDependencies().size() == 1 );
	test_case.Assert( std::find( system.GetDependencies().begin(), system.GetDependencies().end(), dep1 ) != system.GetDependencies().end() );
}
