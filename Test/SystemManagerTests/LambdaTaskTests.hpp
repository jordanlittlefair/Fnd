#pragma once

#include "../Framework/TestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{
	
class LambdaTaskTests:
	public TestClass
{
public:
	
	LambdaTaskTests();
	
private:
	
	void TestGetParentSystemId( TestCase& test_case );
	void TestOnRunLambda( TestCase& test_case );
	void TestSuccessStates( TestCase& test_case );
	void TestErrorStatesAndException( TestCase& test_case );
};
	
}

}

}
