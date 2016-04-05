#include "ExampleTestClass.hpp"

using namespace Fnd::Test;

ExampleTestClass::ExampleTestClass():
	TestClass("ExampleTestClass")
{
	/*
		All test cases which should be called must be added in the constructor. The Run method will iterate
		over these and gather results.
	*/
	AddTestCase( "TestFunction1", &ExampleTestClass::TestFunction1, this );
	AddTestCase( "TestFunction2", &ExampleTestClass::TestFunction2, this );
	AddTestCase( "TestFunction3", &ExampleTestClass::TestFunction3, this );
}

void ExampleTestClass::SetUp()
{
	/*
		Called before running each TestCase - should be used to initialise data used in every TestCase.
	*/
}

void ExampleTestClass::CleanUp()
{
	/*
		Called after running each TestCase - should be used to clean up data used in each TestCase.
	*/
}

void ExampleTestClass::TestFunction1( Fnd::Test::TestCase& test_case )
{
	/*
		Test cases should call the TestCase's Assert method to log any failures.
	*/
	test_case.Assert( 1 == 1 );
}

void ExampleTestClass::TestFunction2( Fnd::Test::TestCase& test_case )
{
	test_case.Assert( 2 == 2 );
}

void ExampleTestClass::TestFunction3( Fnd::Test::TestCase& test_case )
{
	test_case.Assert( 3 == 3 );
}