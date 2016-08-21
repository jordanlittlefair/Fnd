#include "../Framework/TestSuite.hpp"
#include "../Framework/ResultPrinterCollection.hpp"
#include "../Framework/ConsoleResultPrinter.hpp"
#include "../Framework/XmlResultPrinter.hpp"

#include "../UtilityTests/UtilityTestSuite.hpp"
#include "../SystemManagerTests/SystemManagerTestSuite.hpp"

#include <cassert>

using namespace Fnd::Test;

int main()
{
	std::vector<TestSuitePtr> test_suites;
	
	std::shared_ptr<ResultPrinterCollection> result_printers = std::make_shared<ResultPrinterCollection>();
	
	result_printers->AddResultPrinter(std::make_shared<ConsoleResultPrinter>());
	result_printers->AddResultPrinter(std::make_shared<XmlResultPrinter>("TestResults/FndTestResults"));
	
	/*
		Add any TestSuites below
	*/
	
	test_suites.push_back( std::make_shared<Utility::UtilityTestSuite>() );
	test_suites.push_back( std::make_shared<SystemManager::SystemManagerTestSuite>() );
	
	
	
	for (auto& test_suite : test_suites)
	{
		test_suite->SetResultPrinter(result_printers);
		
		test_suite->Run();
		
		assert( test_suite->GetResult().GetSucceeded() );
	}
	
	return 0;
}
