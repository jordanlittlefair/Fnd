#include "SystemManagerTests.hpp"

#include "../../Code/SystemManager/SystemManager.hpp"

using namespace Fnd::Test;
using namespace Fnd::Test::SystemManager;
using namespace Fnd::SystemManager;


SystemManagerTests::SystemManagerTests():
UnitTestClass("SystemManagerTests")
{
	AddTestCase( "IsInitialised_BeforeInitialise_False", &SystemManagerTests::IsInitialised_BeforeInitialise_False, this );
	AddTestCase( "IsInitialised_AfterInitialise_True", &SystemManagerTests::IsInitialised_AfterInitialise_True, this );
	AddTestCase( "IsAlive_BeforeStart_False", &SystemManagerTests::IsAlive_BeforeStart_False, this );
	AddTestCase( "IsAlive_AfterStart_True", &SystemManagerTests::IsAlive_AfterStart_True, this );
	AddTestCase( "IsAlive_AfterKill_False", &SystemManagerTests::IsAlive_AfterKill_False, this );
	AddTestCase( "AddSystem_BeforeInitialise_Fail", &SystemManagerTests::AddSystem_BeforeInitialise_Fail, this );
	AddTestCase( "AddSystem_AfterInitialise_Success", &SystemManagerTests::AddSystem_AfterInitialise_Success, this );
	AddTestCase( "Initialise_Success", &SystemManagerTests::Initialise_Success, this );
	AddTestCase( "Initialise_AlreadyInitialised_Ignored", &SystemManagerTests::Initialise_AlreadyInitialised_Ignored, this );
	AddTestCase( "Start_BeforeInitialised_Fail", &SystemManagerTests::Start_BeforeInitialised_Fail, this );
	AddTestCase( "Start_AfterInitialised_Success", &SystemManagerTests::Start_AfterInitialised_Success, this );
	AddTestCase( "Start_AlreadyStarted", &SystemManagerTests::Start_AlreadyStarted, this );
	AddTestCase( "Run_BeforeInitialises_Fail", &SystemManagerTests::Run_BeforeInitialises_Fail, this );
	AddTestCase( "Run_BeforeStart_Fail", &SystemManagerTests::Run_BeforeStart_Fail, this );
	AddTestCase( "Run_AfterStart_Success", &SystemManagerTests::Run_AfterStart_Success, this );
	AddTestCase( "Run_AfterKill_Fail", &SystemManagerTests::Run_AfterKill_Fail, this );
	AddTestCase( "Run_OneSystem_Success", &SystemManagerTests::Run_OneSystem_Success, this );
	AddTestCase( "Run_TwoSystems_Success", &SystemManagerTests::Run_TwoSystems_Success, this );
	AddTestCase( "Kill_BeforeStart_Fail", &SystemManagerTests::Kill_BeforeStart_Fail, this );
	AddTestCase( "Kill_AfterStart_Success", &SystemManagerTests::Kill_AfterStart_Success, this );
	AddTestCase( "Kill_AlreadyKilled_Fail", &SystemManagerTests::Kill_AlreadyKilled_Fail, this );
}

void SystemManagerTests::IsInitialised_BeforeInitialise_False(TestCase& test_case)
{
	class SystemManager sm;
}

void SystemManagerTests::IsInitialised_AfterInitialise_True(TestCase& test_case)
{
	
}

void SystemManagerTests::IsAlive_BeforeStart_False(TestCase& test_case)
{
	
}

void SystemManagerTests::IsAlive_AfterStart_True(TestCase& test_case)
{
	
}

void SystemManagerTests::IsAlive_AfterKill_False(TestCase& test_case)
{
	
}

void SystemManagerTests::AddSystem_BeforeInitialise_Fail(TestCase& test_case)
{
	
}

void SystemManagerTests::AddSystem_AfterInitialise_Success(TestCase& test_case)
{
	
}

void SystemManagerTests::Initialise_Success(TestCase& test_case)
{
	
}

void SystemManagerTests::Initialise_AlreadyInitialised_Ignored(TestCase& test_case)
{
	
}

void SystemManagerTests::Start_BeforeInitialised_Fail(TestCase& test_case)
{
	
}

void SystemManagerTests::Start_AfterInitialised_Success(TestCase& test_case)
{
	
}

void SystemManagerTests::Start_AlreadyStarted(TestCase& test_case)
{
	
}

void SystemManagerTests::Run_BeforeInitialises_Fail(TestCase& test_case)
{
	
}

void SystemManagerTests::Run_BeforeStart_Fail(TestCase& test_case)
{
	
}

void SystemManagerTests::Run_AfterStart_Success(TestCase& test_case)
{
	
}

void SystemManagerTests::Run_AfterKill_Fail(TestCase& test_case)
{
	
}

void SystemManagerTests::Run_OneSystem_Success(TestCase& test_case)
{
	
}

void SystemManagerTests::Run_TwoSystems_Success(TestCase& test_case)
{
	
}

void SystemManagerTests::Kill_BeforeStart_Fail(TestCase& test_case)
{
	
}

void SystemManagerTests::Kill_AfterStart_Success(TestCase& test_case)
{
	
}

void SystemManagerTests::Kill_AlreadyKilled_Fail(TestCase& test_case)
{
	
}
