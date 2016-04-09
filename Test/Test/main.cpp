#include "../Framework/TestSuite.hpp"

#include "../EntitySystemTests/ComponentTests.hpp"
#include "../EntitySystemTests/ComponentTemplateTests.hpp"

#include <cassert>

using namespace Fnd::Test;

int main()
{
	TestSuite test_suite( "Test Suite" );
	
	/*
		New TestClasses should be added here.
	*/
	
	test_suite.AddTestClass<EntitySystem::ComponentTests>();
	test_suite.AddTestClass<EntitySystem::ComponentTemplateTests>();

	test_suite.Run();
	
	TestSuiteResult result = test_suite.GetResult();

	assert( result.GetSucceeded() );
	
	return 0;
}
