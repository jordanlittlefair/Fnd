#include "../Framework/TestSuite.hpp"
#include "ExampleTestClass.hpp"
#include "../Framework/ConsoleResultPrinter.hpp"

#include <iostream>

using namespace Fnd::Test;

int main()
{
	TestSuite test_suite( "Test Suite" );
	
	ResultPrinterPtr result_printer = std::make_shared<ConsoleResultPrinter>();

	test_suite.SetResultPrinter(result_printer);

	/*
		New TestClasses should be added here.
	*/
	test_suite.AddTestClass<ExampleTestClass>();
	
	test_suite.Run();
	
	TestSuiteResult result = test_suite.GetResult();
		
	return 0;
}
