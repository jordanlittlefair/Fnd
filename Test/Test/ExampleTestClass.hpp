#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{

namespace Test
{

class ExampleTestClass:
	public UnitTestClass
{
public:

	ExampleTestClass();
	
protected:
	
	void SetUp();
	
	void CleanUp();

private:

	void TestFunction1( Fnd::Test::TestCase& test_case );
	
	void TestFunction2( Fnd::Test::TestCase& test_case );
};

}

}
