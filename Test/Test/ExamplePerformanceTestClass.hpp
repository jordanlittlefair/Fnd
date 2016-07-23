#pragma once

#include "../Framework/PerformanceTestClass.hpp"

namespace Fnd
{

namespace Test
{

class ExamplePerformanceTestClass:
	public PerformanceTestClass
{
public:
	
	ExamplePerformanceTestClass();
	
protected:
	
	void SetUp();
	
	void CleanUp();
	
private:
	
	void TestFunction1( Fnd::Test::TestCase& test_case );
	
	void TestFunction2( Fnd::Test::TestCase& test_case );
};

}

}
