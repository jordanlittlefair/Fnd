#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{

class TaskTests:
	public UnitTestClass
{
public:

	TaskTests();

private:

	void TestGetParentSystemId( TestCase& test_case );
	void TestRun( TestCase& test_case );
	void TestSuccessStates( TestCase& test_case );
};

}

}

}