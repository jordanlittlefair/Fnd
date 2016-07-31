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

	void UpdateSystemNodes_Empty_Success(TestCase& test_case);
	void UpdateSystemNodes_DuplicateIds_Throw(TestCase& test_case);
	void UpdateSystemNodes_SingleNode_Success(TestCase& test_case);
	void UpdateSystemNodes_NoDependencies_Success(TestCase& test_case);
	void UpdateSystemNodes_SingleDependency_Success(TestCase& test_case);
	void UpdateSystemNodes_MultipleDependencies_Success(TestCase& test_case);
	void UpdateSystemNodes_SharedDependencies_Success(TestCase& test_case);
	void UpdateSystemNodes_Chain_Success(TestCase& test_case);
	void UpdateSystemNodes_CyclicDependencies_Throw(TestCase& test_case);
	
	void GetOptimalPath_Success(TestCase& test_case);
};

}

}

}
