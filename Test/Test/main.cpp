#include "../Framework/TestSuite.hpp"
#include "../Framework/ResultPrinterCollection.hpp"
#include "../Framework/ConsoleResultPrinter.hpp"
#include "../Framework/XmlResultPrinter.hpp"

#include "../UtilityTests/UtilityTestSuite.hpp"
#include "../EntitySystemTests/EntitySystemTestSuite.hpp"
#include "../SystemManagerTests/SystemManagerTestSuite.hpp"
#include "../MathTests/MathTestSuite.hpp"
#include "../ModulesTests/ModulesTestSuite.hpp"


#include <cassert>

using namespace Fnd::Test;

int main()
{
	const std::string working_directory = "TestResults/";
	const std::string results_filename = working_directory + "FndTestResults";
	
	std::vector<TestSuitePtr> test_suites;
	
	std::shared_ptr<ResultPrinterCollection> result_printers = std::make_shared<ResultPrinterCollection>();
	
	result_printers->AddResultPrinter(std::make_shared<ConsoleResultPrinter>());
	result_printers->AddResultPrinter(std::make_shared<XmlResultPrinter>(results_filename));
	
	/*
		Add any TestSuites below
	*/
	
	test_suites.push_back( std::make_shared<Utility::UtilityTestSuite>() );
	test_suites.push_back( std::make_shared<EntitySystem::EntitySystemTestSuite>() );
	test_suites.push_back( std::make_shared<SystemManager::SystemManagerTestSuite>() );
	test_suites.push_back( std::make_shared<Math::MathTestSuite>() );
	test_suites.push_back( std::make_shared<Modules::ModulesTestSuite>() );
	
	for (auto& test_suite : test_suites)
	{
		test_suite->SetWorkingDirectory(working_directory);
		test_suite->SetResultPrinter(result_printers);
		
		test_suite->Run();
		
		//assert( test_suite->GetResult().GetSucceeded() );
	}
	
	return 0;
}
