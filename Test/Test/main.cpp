#include "../Framework/TestSuite.hpp"

#include "../SystemManagerTests/SystemManagerExceptionTests.hpp"
#include "../SystemManagerTests/SystemGraphNodeTests.hpp"
#include "../SystemManagerTests/SystemTests.hpp"
#include "../SystemManagerTests/SystemGraphTests.hpp"
#include "../SystemManagerTests/CyclicGraphCheckerTests.hpp"
#include "../SystemManagerTests/OptimalPathFinderTests.hpp"
#include "../SystemManagerTests/TaskTests.hpp"
#include "../SystemManagerTests/LambdaTaskTests.hpp"
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
	test_suite.AddTestClass<SystemManager::SystemManagerExceptionTests>();
	test_suite.AddTestClass<SystemManager::SystemGraphNodeTests>();
	test_suite.AddTestClass<SystemManager::SystemTests>();
	test_suite.AddTestClass<SystemManager::SystemGraphTests>();
	test_suite.AddTestClass<SystemManager::CyclicGraphCheckerTests>();
	test_suite.AddTestClass<SystemManager::OptimalPathFinderTests>();
	test_suite.AddTestClass<SystemManager::TaskTests>();
	test_suite.AddTestClass<SystemManager::LambdaTaskTests>();
	test_suite.Run();
	
	TestSuiteResult result = test_suite.GetResult();
	
	assert( result.GetSucceeded() );
	
	return 0;
}
