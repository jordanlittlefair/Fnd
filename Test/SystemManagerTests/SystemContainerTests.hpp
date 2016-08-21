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
	
	void AddSystem_BeforeInitialise_Success(TestCase& test_case);
	void AddSystem_DuplicateId_Throw(TestCase& test_case);
	void AddSystem_AfterInitialise_Fail(TestCase& test_case);
	
	void IsInitialised_BeforeInitialise_False(TestCase& test_case);
	void IsInitialised_AfterInitialise_True(TestCase& test_case);
	
	void Initialise_SystemsInitialised_Success(TestCase& test_case);
	void Initialise_SystemFailsToInitialise_Throw(TestCase& test_case);
	
	void GetOrderedSystems_Success(TestCase& test_case);
};

}

}

}
