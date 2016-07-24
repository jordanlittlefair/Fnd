#include "ExamplePerformanceTestClass.hpp"

using namespace Fnd::Test;

ExamplePerformanceTestClass::ExamplePerformanceTestClass():
	PerformanceTestClass("ExamplePerformanceTestClass")
{
	/*
		All test cases which should be called must be added in the constructor. The Run method will iterate
		over these and gather results.
	 */
	AddTestCase( "TestFunction1", &ExamplePerformanceTestClass::TestFunction1, this );
	AddTestCase( "TestFunction2", &ExamplePerformanceTestClass::TestFunction2, this );
}

void ExamplePerformanceTestClass::SetUp()
{
	/*
		Called before running each TestCase - should be used to initialise data used in every TestCase.
	 */
}

void ExamplePerformanceTestClass::CleanUp()
{
	/*
		Called after running each TestCase - should be used to clean up data used in each TestCase.
	 */
}

void ExamplePerformanceTestClass::TestFunction1( Fnd::Test::TestCase& test_case )
{
	test_case.Assert( 1 == 1 );
}

void ExamplePerformanceTestClass::TestFunction2( Fnd::Test::TestCase& test_case )
{
	test_case.AssertException<std::runtime_error>([]()
	{
		throw std::runtime_error("Expected exception!");
	} );
}
