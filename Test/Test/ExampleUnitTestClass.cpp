#include "ExampleUnitTestClass.hpp"

using namespace Fnd::Test;

ExampleUnitTestClass::ExampleUnitTestClass():
	UnitTestClass("ExampleUnitTestClass")
{
	/*
		All test cases which should be called must be added in the constructor. The Run method will iterate
		over these and gather results.
	*/
	AddTestCase( "TestFunction1", &ExampleUnitTestClass::TestFunction1, this );
	AddTestCase( "TestFunction2", &ExampleUnitTestClass::TestFunction2, this );
}

void ExampleUnitTestClass::SetUp()
{
	/*
		Called before running each TestCase - should be used to initialise data used in every TestCase.
	*/
}

void ExampleUnitTestClass::CleanUp()
{
	/*
		Called after running each TestCase - should be used to clean up data used in each TestCase.
	*/
}

void ExampleUnitTestClass::TestFunction1( Fnd::Test::TestCase& test_case )
{
	test_case.AssertEqual(1, 1);
	test_case.AssertNotEqual(1, 2);
}

void ExampleUnitTestClass::TestFunction2( Fnd::Test::TestCase& test_case )
{
	test_case.AssertException<std::runtime_error>([]()
	{
		throw std::runtime_error("Expected exception!");
	} );
}
