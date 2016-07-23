#include "../Framework/TestSuite.hpp"
#include "ExampleTestSuite.hpp"
#include "../Framework/ResultPrinterCollection.hpp"
#include "../Framework/ConsoleResultPrinter.hpp"
#include "../Framework/XmlResultPrinter.hpp"

#include <iostream>

using namespace Fnd::Test;

int main()
{
	ExampleTestSuite test_suite;
	
	std::shared_ptr<ResultPrinterCollection> result_printers = std::make_shared<ResultPrinterCollection>();
	
	result_printers->AddResultPrinter(std::make_shared<ConsoleResultPrinter>());
	result_printers->AddResultPrinter(std::make_shared<XmlResultPrinter>("TestResults/FndTestResults"));

	test_suite.SetResultPrinter(result_printers);
	
	test_suite.Run();
	
	TestSuiteResult result = test_suite.GetResult();
		
	return 0;
}
