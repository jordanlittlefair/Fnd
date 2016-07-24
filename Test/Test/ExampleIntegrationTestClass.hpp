#pragma once

#include "../Framework/IntegrationTestClass.hpp"

namespace Fnd
{

namespace Test
{

class ExampleIntegrationTestClass:
	public IntegrationTestClass
{
public:
	
	ExampleIntegrationTestClass();
	
protected:
	
	void SetUp();
	
	void CleanUp();
	
private:
	
	void TestFunction1( Fnd::Test::TestCase& test_case );
	
	void TestFunction2( Fnd::Test::TestCase& test_case );
};

}

}
