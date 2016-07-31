#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{

class SystemGraphTests:
	public UnitTestClass
{
public:

	SystemGraphTests();

private:

	void UpdateSystemNodes_NotCyclic_Success(TestCase& test_case);
	void UpdateSystemNodes_Cyclic_Throw(TestCase& test_case);
	void UpdateSystemNodes_HasNodes(TestCase& test_case);
	
	void GetOptimalPath_Success(TestCase& test_case);
};

}

}

}
