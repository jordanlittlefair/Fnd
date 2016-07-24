#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{
	
class LambdaTaskTests:
	public UnitTestClass
{
public:
	
	LambdaTaskTests();
	
private:
	
	void TestGetParentSystemId( TestCase& test_case );
	void TestOnRunLambda( TestCase& test_case );
	void TestSuccessStates( TestCase& test_case );
};
	
}

}

}
