#include "../Framework/TestSuite.hpp"
#include "ExampleTestSuite.hpp"
#include "../Framework/ResultPrinterCollection.hpp"
#include "../Framework/ConsoleResultPrinter.hpp"
#include "../Framework/XmlResultPrinter.hpp"

#include <iostream>

using namespace Fnd::Test;

int main()
{
	const std::string working_directory = "TestResults/";
	const std::string results_filename = working_directory + "FndTestResults";
		
	ExampleTestSuite test_suite;
	
	std::shared_ptr<ResultPrinterCollection> result_printers = std::make_shared<ResultPrinterCollection>();
	
	result_printers->AddResultPrinter(std::make_shared<ConsoleResultPrinter>());
	result_printers->AddResultPrinter(std::make_shared<XmlResultPrinter>(results_filename));

	test_suite.SetWorkingDirectory(working_directory);
	test_suite.SetResultPrinter(result_printers);
	
	test_suite.Run();
	
	TestSuiteResult result = test_suite.GetResult();
	
	return 0;
}
