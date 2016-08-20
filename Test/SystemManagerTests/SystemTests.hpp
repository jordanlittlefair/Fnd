#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{

class SystemTests:
public UnitTestClass
{
public:

	SystemTests();

private:

	void GetId_Success(TestCase& test_case);
	void GetName_Success(TestCase& test_case);
	void AddDependency_Success(TestCase& test_case);
	void AddDependency_DuplicateId_Fail(TestCase& test_case);
	
	void IsInitialised_BeforeInitialise_False(TestCase& test_case);
	void IsInitialised_AfterInitialise_True(TestCase& test_case);
	
	void Initialise_Success(TestCase& test_case);
	void Initialise_ForceFail_Throw(TestCase& test_case);
	void Initialise_AlreadyInitialised_Fail(TestCase& test_case);
	
	void Run_NoTasks_Succeess(TestCase& test_case);
	void Run_OneTaskSynchronous_Success(TestCase& test_case);
	void Run_TwoTasksSynchronous_Success(TestCase& test_case);
	void Run_FiftyTasksSynchronous_Success(TestCase& test_case);
	void Run_OneTaskAsynchronous_Success(TestCase& test_case);
	void Run_TwoTasksAsynchronous_Success(TestCase& test_case);
	void Run_FiftyTasksAsynchronous_Success(TestCase& test_case);
};

}

}

}
