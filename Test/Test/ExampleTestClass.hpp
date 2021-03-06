#pragma once

#include "../Framework/TestClass.hpp"

namespace Fnd
{

namespace Test
{

class ExampleTestClass:
	public TestClass
{
public:

	ExampleTestClass();
	
protected:
	
	void SetUp();
	
	void CleanUp();

private:

	void TestFunction1( Fnd::Test::TestCase& test_case );
	
	void TestFunction2( Fnd::Test::TestCase& test_case );
	
	void TestFunction3( Fnd::Test::TestCase& test_case );
};

}

}