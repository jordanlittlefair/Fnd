#include "../Framework/TestSuite.hpp"
#include "ExampleTestClass.hpp"

using namespace Fnd::Test;

int main()
{
	TestSuite test_suite( "Test Suite" );
	
	/*
		New TestClasses should be added here.
	*/
	test_suite.AddTestClass<ExampleTestClass>();
	
	test_suite.Run();
	
	TestSuiteResult result = test_suite.GetResult();
	
	return 0;
}
