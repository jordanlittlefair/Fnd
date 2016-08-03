#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{

class SystemManagerTests:
	public UnitTestClass
{
public:
	
	SystemManagerTests();
	
private:
	
	void IsInitialised_BeforeInitialise_False(TestCase& test_case);
	void IsInitialised_AfterInitialise_True(TestCase& test_case);
	
	void IsAlive_BeforeStart_False(TestCase& test_case);
	void IsAlive_AfterStart_True(TestCase& test_case);
	void IsAlive_AfterKill_False(TestCase& test_case);
	
	void AddSystem_BeforeInitialise_Fail(TestCase& test_case);
	void AddSystem_AfterInitialise_Success(TestCase& test_case);
	
	void Initialise_Success(TestCase& test_case);
	void Initialise_AlreadyInitialised_Ignored(TestCase& test_case);
	
	void Start_BeforeInitialised_Fail(TestCase& test_case);
	void Start_AfterInitialised_Success(TestCase& test_case);
	void Start_AlreadyStarted(TestCase& test_case);
	
	void Run_BeforeInitialises_Fail(TestCase& test_case);
	void Run_BeforeStart_Fail(TestCase& test_case);
	void Run_AfterStart_Success(TestCase& test_case);
	void Run_AfterKill_Fail(TestCase& test_case);
	void Run_OneSystem_Success(TestCase& test_case);
	void Run_TwoSystems_Success(TestCase& test_case);
	
	void Kill_BeforeStart_Fail(TestCase& test_case);
	void Kill_AfterStart_Success(TestCase& test_case);
	void Kill_AlreadyKilled_Fail(TestCase& test_case);
};

}

}

}
