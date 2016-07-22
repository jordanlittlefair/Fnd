#pragma once

#include "../Framework/TestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{

class TaskManagerTests:
	public TestClass
{
public:
	
	TaskManagerTests();
	
private:
	
	void Constructor_IsInitialised_False(TestCase& test_case);
	void Initialise_DefaultProviderConsumer_AreSet(TestCase& test_case);
	void Initialise_CustomProvider_IsSet(TestCase& test_case);
	void Initialise_CustomConsumer_IsSet(TestCase& test_case);
	void Initialise_IsInitialised(TestCase& test_case);
	void Start_BeforeInitialised_NotAlive(TestCase& test_case);
	void Start_AfterInitialised_Alive(TestCase& test_case);
	void IsAlive_BeforeStart_False(TestCase& test_case);
	void IsAlive_AfterStart_True(TestCase& test_case);
	void IsAlive_AfterKill_False(TestCase& test_case);
	void Kill_BeforeInitialise_DoNothing(TestCase& test_case);
	void Kill_BeforeStart_DoNothing(TestCase& test_case);
	void Kill_AfterStart_Success(TestCase& test_case);
	void Kill_Twice_DoNothing(TestCase& test_case);
};

}

}

}
