#include "../Framework/TestSuite.hpp"

#include "../EntitySystemTests/EntitySystemTestSuite.hpp"

#include "../Framework/ConsoleResultPrinter.hpp"

#include <cassert>

using namespace Fnd::Test;

int main()
{
	std::vector<TestSuitePtr> test_suites;
	
	ResultPrinterPtr result_printer = std::make_shared<ConsoleResultPrinter>();

	/*
		Add any TestSuites below
	*/
	
	test_suites.push_back( std::make_shared<EntitySystemTests::EntitySystemTestSuite>() );
	
	
	
	for (auto& test_suite : test_suites)
	{
		test_suite->SetResultPrinter(result_printer);

		test_suite->Run();

		assert( test_suite->GetResult().GetSucceeded() );
	}

	return 0;
}
