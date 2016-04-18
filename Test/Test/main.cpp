#include "../Framework/TestSuite.hpp"

#include "../SystemManagerTests/SystemGraphNodeTests.hpp"
#include "../SystemManagerTests/SystemTests.hpp"

#include <cassert>

using namespace Fnd::Test;

int main()
{
	TestSuite test_suite( "Test Suite" );
	
	/*
		New TestClasses should be added here.
	*/
	test_suite.AddTestClass<SystemManager::SystemGraphNodeTests>();
	test_suite.AddTestClass<SystemManager::SystemTests>();
	
	test_suite.Run();
	
	TestSuiteResult result = test_suite.GetResult();
	
	assert( result.GetSucceeded() );
	
	return 0;
}
