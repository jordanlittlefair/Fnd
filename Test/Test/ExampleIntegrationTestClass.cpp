#include "ExampleIntegrationTestClass.hpp"

using namespace Fnd::Test;

ExampleIntegrationTestClass::ExampleIntegrationTestClass():
	IntegrationTestClass("ExampleIntegrationTestClass")
{
	/*
		All test cases which should be called must be added in the constructor. The Run method will iterate
		over these and gather results.
	 */
	AddTestCase( "TestFunction1", &ExampleIntegrationTestClass::TestFunction1, this );
	AddTestCase( "TestFunction2", &ExampleIntegrationTestClass::TestFunction2, this );
}

void ExampleIntegrationTestClass::SetUp()
{
	/*
		Called before running each TestCase - should be used to initialise data used in every TestCase.
	 */
}

void ExampleIntegrationTestClass::CleanUp()
{
	/*
		Called after running each TestCase - should be used to clean up data used in each TestCase.
	 */
}

void ExampleIntegrationTestClass::TestFunction1( Fnd::Test::TestCase& test_case )
{
	test_case.Assert( 1 == 1 );
}

void ExampleIntegrationTestClass::TestFunction2( Fnd::Test::TestCase& test_case )
{
	test_case.AssertException<std::runtime_error>([]()
	{
		throw std::runtime_error("Expected exception!");
	} );
}
