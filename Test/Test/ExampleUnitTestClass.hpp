#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{

namespace Test
{

class ExampleUnitTestClass:
	public UnitTestClass
{
public:

	ExampleUnitTestClass();
	
protected:
	
	void SetUp();
	
	void CleanUp();

private:

	void TestFunction1( Fnd::Test::TestCase& test_case );
	
	void TestFunction2( Fnd::Test::TestCase& test_case );
};

}

}
