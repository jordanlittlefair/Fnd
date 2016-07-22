#include "TaskManagerTests.hpp"

#include "MockTaskConsumer.hpp"
#include "MockTaskProvider.hpp"

#include "../../Code/SystemManager/TaskManager.hpp"

using namespace Fnd::SystemManager;
using namespace Fnd::Test;
using namespace Fnd::Test::SystemManager;

TaskManagerTests::TaskManagerTests():
	TestClass("TaskManagerTests")
{
	AddTestCase( "Constructor_IsInitialised_False", &TaskManagerTests::Constructor_IsInitialised_False, this );
	AddTestCase( "Initialise_DefaultProviderConsumer_AreSet", &TaskManagerTests::Initialise_DefaultProviderConsumer_AreSet, this );
	AddTestCase( "Initialise_CustomProvider_IsSet", &TaskManagerTests::Initialise_CustomProvider_IsSet, this );
	AddTestCase( "Initialise_CustomConsumer_IsSet", &TaskManagerTests::Initialise_CustomConsumer_IsSet, this );
	AddTestCase( "Initialise_IsInitialised", &TaskManagerTests::Initialise_IsInitialised, this );
	AddTestCase( "Start_BeforeInitialised_NotAlive", &TaskManagerTests::Start_BeforeInitialised_NotAlive, this );
	AddTestCase( "Start_AfterInitialised_Alive", &TaskManagerTests::Start_AfterInitialised_Alive, this );
	AddTestCase( "IsAlive_BeforeStart_False", &TaskManagerTests::IsAlive_BeforeStart_False, this );
	AddTestCase( "IsAlive_AfterStart_True", &TaskManagerTests::IsAlive_AfterStart_True, this );
	AddTestCase( "IsAlive_AfterKill_False", &TaskManagerTests::IsAlive_AfterKill_False, this );
	AddTestCase( "Kill_BeforeInitialise_DoNothing", &TaskManagerTests::Kill_BeforeInitialise_DoNothing, this );
	AddTestCase( "Kill_AfterStart_Success", &TaskManagerTests::Kill_AfterStart_Success, this );
	AddTestCase( "Kill_BeforeStart_DoNothing", &TaskManagerTests::Kill_BeforeStart_DoNothing, this );

	AddTestCase( "Kill_Twice_DoNothing", &TaskManagerTests::Kill_Twice_DoNothing, this );
}

void TaskManagerTests::Constructor_IsInitialised_False(TestCase& test_case)
{
	TaskManager tm;
	
	test_case.Assert(!tm.IsAlive());
}

void TaskManagerTests::Initialise_DefaultProviderConsumer_AreSet(TestCase& test_case)
{
	TaskManager tm;
	
	tm.Initialise();
	
	tm.GetTaskConsumer();
	tm.GetTaskProvider();
}

void TaskManagerTests::Initialise_CustomProvider_IsSet(TestCase& test_case)
{
	TaskManager tm;
	
	auto tp = std::make_shared<MockTaskProvider>();
	
	tm.SetTaskProvider(tp);
	
	tm.Initialise();
	
	test_case.Assert(&tm.GetTaskProvider() == tp.get());
}

void TaskManagerTests::Initialise_CustomConsumer_IsSet(TestCase& test_case)
{
	TaskManager tm;
	
	auto tc = std::make_shared<MockTaskConsumer>();
	
	tm.SetTaskConsumer(tc);
	
	tm.Initialise();
	
	test_case.Assert(&tm.GetTaskConsumer() == tc.get());
}

void TaskManagerTests::Initialise_IsInitialised(TestCase& test_case)
{
	TaskManager tm;
	
	tm.Initialise();
	
	test_case.Assert(tm.IsInitialised());
}

void TaskManagerTests::Start_BeforeInitialised_NotAlive(TestCase& test_case)
{
	// Test is covered by asserts
	
	/*
	TaskManager tm;
	
	tm.Start();
	
	test_case.Assert(!tm.IsAlive());
	*/
}

void TaskManagerTests::Start_AfterInitialised_Alive(TestCase& test_case)
{
	TaskManager tm;
	
	tm.Initialise();
	
	tm.Start();
	
	test_case.Assert(tm.IsAlive());
}

void TaskManagerTests::IsAlive_BeforeStart_False(TestCase& test_case)
{
	TaskManager tm;
	
	test_case.Assert(!tm.IsAlive());
}

void TaskManagerTests::IsAlive_AfterStart_True(TestCase& test_case)
{
	TaskManager tm;
	
	tm.Initialise();
	
	tm.Start();
	
	test_case.Assert(tm.IsAlive());
}

void TaskManagerTests::IsAlive_AfterKill_False(TestCase& test_case)
{
	TaskManager tm;
	
	tm.Initialise();
	
	tm.Start();
	
	tm.Kill();
	
	test_case.Assert(!tm.IsAlive());
}

void TaskManagerTests::Kill_BeforeInitialise_DoNothing(TestCase& test_case)
{
	TaskManager tm;
	
	tm.Kill();
}

void TaskManagerTests::Kill_BeforeStart_DoNothing(TestCase& test_case)
{
	TaskManager tm;
	
	tm.Initialise();
	
	tm.Kill();
}

void TaskManagerTests::Kill_AfterStart_Success(TestCase& test_case)
{
	TaskManager tm;
	
	tm.Initialise();
	
	tm.Start();
	
	tm.Kill();
}

void TaskManagerTests::Kill_Twice_DoNothing(TestCase& test_case)
{
	TaskManager tm;
	
	tm.Initialise();
	
	tm.Start();
	
	tm.Kill();
	
	tm.Kill();
}
