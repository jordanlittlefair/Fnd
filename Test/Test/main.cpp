#include "../Framework/TestSuite.hpp"
#include "ExampleTestSuite.hpp"
#include "../Framework/XmlResultPrinter.hpp"

#include <iostream>

using namespace Fnd::Test;

int main()
{
	ExampleTestSuite test_suite;
	
	ResultPrinterPtr result_printer = std::make_shared<XmlResultPrinter>("TestResults/FndTestResults");

	test_suite.SetResultPrinter(result_printer);
	
	test_suite.Run();
	
	TestSuiteResult result = test_suite.GetResult();
		
	return 0;
}
