#include "../Framework/TestSuite.hpp"
#include "ExampleTestSuite.hpp"
#include "../Framework/ConsoleResultPrinter.hpp"

#include <iostream>

using namespace Fnd::Test;

int main()
{
	ExampleTestSuite test_suite;
	
	ResultPrinterPtr result_printer = std::make_shared<ConsoleResultPrinter>();

	test_suite.SetResultPrinter(result_printer);
	
	test_suite.Run();
	
	TestSuiteResult result = test_suite.GetResult();
		
	return 0;
}
