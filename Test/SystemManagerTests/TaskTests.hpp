#pragma once

#include "../Framework/TestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{

class TaskTests:
	public TestClass
{
public:

	TaskTests();

private:

	void TestGetParentSystemId( TestCase& test_case );
	void TestRun( TestCase& test_case );
	void TestSuccessStates( TestCase& test_case );
	void TestErrorStatesAndException( TestCase& test_case );
	
	void TestWait_Complete( TestCase& test_case );
	void TestWait_Exception( TestCase& test_case );
};

}

}

}
