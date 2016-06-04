#include "../Framework/TestSuite.hpp"

#include "../EntitySystemTests/ComponentTests.hpp"
#include "../EntitySystemTests/ComponentTemplateTests.hpp"
#include "../EntitySystemTests/ComponentContainerTests.hpp"
#include "../EntitySystemTests/ComponentContainerTemplateTests.hpp"
#include "../EntitySystemTests/ExceptionTests.hpp"
#include "../EntitySystemTests/ComponentManagerTests.hpp"
#include "../Framework/ConsoleResultPrinter.hpp"

#include <cassert>
using namespace Fnd::Test;

int main()
{
	TestSuite test_suite( "Test Suite" );
	
	ResultPrinterPtr result_printer = std::make_shared<ConsoleResultPrinter>();

	test_suite.SetResultPrinter(result_printer);

	/*
		New TestClasses should be added here.
	*/
	
	test_suite.AddTestClass<EntitySystem::ComponentTests>();
	test_suite.AddTestClass<EntitySystem::ComponentTemplateTests>();
	test_suite.AddTestClass<EntitySystem::ComponentContainerTests>();
	test_suite.AddTestClass<EntitySystem::ExceptionTests>();
	test_suite.AddTestClass<EntitySystem::ComponentContainerTemplateTests>();
	test_suite.AddTestClass<EntitySystem::ComponentManagerTests>();

	test_suite.Run();
	
	TestSuiteResult result = test_suite.GetResult();

	assert( result.GetSucceeded() );
	
	return 0;
}
