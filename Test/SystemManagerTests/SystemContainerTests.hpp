#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{

class SystemContainerTests:
	public UnitTestClass
{
public:

	SystemContainerTests();

private:

	void SetTaskProvider_SetsOnSystemAddedBefore(TestCase& test_case);
	void SetTaskProvider_SetsOnSystemAddedAfter(TestCase& test_case);
	void AddSystem_Success(TestCase& test_case);
	void AddSystem_DuplicateId_Throw(TestCase& test_case);
	void GetOrderedSystems_Success(TestCase& test_case);
};

}

}

}
