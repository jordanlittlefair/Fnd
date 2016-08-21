#include "SystemManagerTests.hpp"

#include "../../Code/SystemManager/SystemManager.hpp"

#include "MockSystemContainer.hpp"
#include "MockTaskManager.hpp"
#include "MockSystem.hpp"

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
	AddTestCase( "AddSystem_BeforeInitialise_Success", &SystemManagerTests::AddSystem_BeforeInitialise_Success, this );
	AddTestCase( "AddSystem_AfterInitialise_Fail", &SystemManagerTests::AddSystem_AfterInitialise_Fail, this );
	AddTestCase( "Initialise_Success", &SystemManagerTests::Initialise_Success, this );
	AddTestCase( "Initialise_AlreadyInitialised_Fail", &SystemManagerTests::Initialise_AlreadyInitialised_Fail, this );
	AddTestCase( "Start_BeforeInitialised_Fail", &SystemManagerTests::Start_BeforeInitialised_Fail, this );
	AddTestCase( "Start_AfterInitialised_Success", &SystemManagerTests::Start_AfterInitialised_Success, this );
	AddTestCase( "Start_AlreadyStarted_Fail", &SystemManagerTests::Start_AlreadyStarted_Fail, this );
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
	
	auto tm = std::make_shared<MockTaskManager>();
	auto sc = std::make_shared<MockSystemContainer>();
	
	sm.SetTaskManager(tm);
	sm.SetSystemContainer(sc);
	
	test_case.AssertEqual(false, sm.IsInitialised());
}

void SystemManagerTests::IsInitialised_AfterInitialise_True(TestCase& test_case)
{
	class SystemManager sm;
	
	auto tm = std::make_shared<MockTaskManager>();
	auto sc = std::make_shared<MockSystemContainer>();
	
	sm.SetTaskManager(tm);
	sm.SetSystemContainer(sc);
	
	sm.Initialise();
	
	test_case.AssertEqual(true, sm.IsInitialised());
}

void SystemManagerTests::IsAlive_BeforeStart_False(TestCase& test_case)
{
	class SystemManager sm;
	
	auto tm = std::make_shared<MockTaskManager>();
	auto sc = std::make_shared<MockSystemContainer>();
	
	sm.SetTaskManager(tm);
	sm.SetSystemContainer(sc);
	
	sm.Initialise();
	
	test_case.AssertEqual(false, sm.IsAlive());
}

void SystemManagerTests::IsAlive_AfterStart_True(TestCase& test_case)
{
	class SystemManager sm;
	
	auto tm = std::make_shared<MockTaskManager>();
	auto sc = std::make_shared<MockSystemContainer>();
	
	sm.SetTaskManager(tm);
	sm.SetSystemContainer(sc);
	
	sm.Initialise();
	
	sm.Start();
	
	test_case.AssertEqual(true, sm.IsAlive());
}

void SystemManagerTests::IsAlive_AfterKill_False(TestCase& test_case)
{
	class SystemManager sm;
	
	auto tm = std::make_shared<MockTaskManager>();
	auto sc = std::make_shared<MockSystemContainer>();
	
	sm.SetTaskManager(tm);
	sm.SetSystemContainer(sc);
	
	sm.Initialise();
	
	sm.Start();
	
	sm.Kill();
	
	test_case.AssertEqual(false, sm.IsAlive());
}

void SystemManagerTests::AddSystem_BeforeInitialise_Success(TestCase& test_case)
{
	class SystemManager sm;
	
	auto tm = std::make_shared<MockTaskManager>();
	auto sc = std::make_shared<MockSystemContainer>();
	
	sm.SetTaskManager(tm);
	sm.SetSystemContainer(sc);
	
	auto system = std::make_shared<MockSystem>(123);
	
	sm.AddSystem(system);
	
	test_case.AssertEqual(123, sc->GetOrderedSystems()[0]->GetId());
}

void SystemManagerTests::AddSystem_AfterInitialise_Fail(TestCase& test_case)
{
	class SystemManager sm;
	
	auto tm = std::make_shared<MockTaskManager>();
	auto sc = std::make_shared<MockSystemContainer>();
	
	sm.SetTaskManager(tm);
	sm.SetSystemContainer(sc);
	
	sm.Initialise();
	
	auto system = std::make_shared<MockSystem>(123);
	
	test_case.AssertException<std::exception>([&]()
	{
		sm.AddSystem(system);
	});
}

void SystemManagerTests::Initialise_Success(TestCase& test_case)
{
	class SystemManager sm;
	
	auto tm = std::make_shared<MockTaskManager>();
	auto sc = std::make_shared<MockSystemContainer>();
	
	sm.SetTaskManager(tm);
	sm.SetSystemContainer(sc);
	
	sm.Initialise();
	
	test_case.AssertEqual(true, sm.IsInitialised());
}

void SystemManagerTests::Initialise_AlreadyInitialised_Fail(TestCase& test_case)
{
	class SystemManager sm;
	
	auto tm = std::make_shared<MockTaskManager>();
	auto sc = std::make_shared<MockSystemContainer>();
	
	sm.SetTaskManager(tm);
	sm.SetSystemContainer(sc);
	
	sm.Initialise();
	
	test_case.AssertEqual(true, sm.IsInitialised());
	
	test_case.AssertException<std::exception>([&]()
	{
		sm.Initialise();
	});
	
	test_case.AssertEqual(true, sm.IsInitialised());
}

void SystemManagerTests::Start_BeforeInitialised_Fail(TestCase& test_case)
{
	class SystemManager sm;
	
	auto tm = std::make_shared<MockTaskManager>();
	auto sc = std::make_shared<MockSystemContainer>();
	
	sm.SetTaskManager(tm);
	sm.SetSystemContainer(sc);
	
	test_case.AssertException<std::exception>([&]()
	{
		sm.Start();
	});
}

void SystemManagerTests::Start_AfterInitialised_Success(TestCase& test_case)
{
	class SystemManager sm;
	
	auto tm = std::make_shared<MockTaskManager>();
	auto sc = std::make_shared<MockSystemContainer>();
	
	sm.SetTaskManager(tm);
	sm.SetSystemContainer(sc);
	
	sm.Initialise();
	
	sm.Start();
	
	test_case.AssertEqual(true, sm.IsAlive());
}

void SystemManagerTests::Start_AlreadyStarted_Fail(TestCase& test_case)
{
	class SystemManager sm;
	
	auto tm = std::make_shared<MockTaskManager>();
	auto sc = std::make_shared<MockSystemContainer>();
	
	sm.SetTaskManager(tm);
	sm.SetSystemContainer(sc);
	
	sm.Initialise();
	
	sm.Start();
	
	test_case.AssertException<std::exception>([&]()
	{
		sm.Start();
	});
}

void SystemManagerTests::Run_BeforeInitialises_Fail(TestCase& test_case)
{
	class SystemManager sm;
	
	auto tm = std::make_shared<MockTaskManager>();
	auto sc = std::make_shared<MockSystemContainer>();
	
	sm.SetTaskManager(tm);
	sm.SetSystemContainer(sc);
	
	test_case.AssertException<std::exception>([&]()
	{
		sm.Run();
	});
}

void SystemManagerTests::Run_BeforeStart_Fail(TestCase& test_case)
{
	class SystemManager sm;
	
	auto tm = std::make_shared<MockTaskManager>();
	auto sc = std::make_shared<MockSystemContainer>();
	
	sm.SetTaskManager(tm);
	sm.SetSystemContainer(sc);
	
	sm.Initialise();
	
	test_case.AssertException<std::exception>([&]()
	{
		sm.Run();
	});
}

void SystemManagerTests::Run_AfterStart_Success(TestCase& test_case)
{
	class SystemManager sm;
	
	auto tm = std::make_shared<MockTaskManager>();
	auto sc = std::make_shared<MockSystemContainer>();
	
	sm.SetTaskManager(tm);
	sm.SetSystemContainer(sc);
	
	sm.Initialise();
	
	sm.Start();
	
	sm.Run();
}

void SystemManagerTests::Run_AfterKill_Fail(TestCase& test_case)
{
	class SystemManager sm;
	
	auto tm = std::make_shared<MockTaskManager>();
	auto sc = std::make_shared<MockSystemContainer>();
	
	sm.SetTaskManager(tm);
	sm.SetSystemContainer(sc);
	
	sm.Initialise();
	
	sm.Start();
	
	sm.Kill();
	
	test_case.AssertException<std::exception>([&]()
	{
		sm.Run();
	});
}

class TestSystem:
	public MockSystem
{
public:
	TestSystem(const SystemId id):
		MockSystem(id),
		_run_count(0)
	{
	}
	
	int GetRunCount() const
	{
		return _run_count;
	}
protected:
	void OnRun()
	{
		++_run_count;
	}
private:
	
	int _run_count;
};


void SystemManagerTests::Run_OneSystem_Success(TestCase& test_case)
{
	class SystemManager sm;
	
	auto tm = std::make_shared<MockTaskManager>();
	auto sc = std::make_shared<MockSystemContainer>();
	
	sm.SetTaskManager(tm);
	sm.SetSystemContainer(sc);
	
	auto system = std::make_shared<TestSystem>(123);
	
	sm.AddSystem(system);
	
	sm.Initialise();
	
	sm.Start();
	
	sm.Run();
	
	test_case.AssertEqual(1, system->GetRunCount());
}

void SystemManagerTests::Run_TwoSystems_Success(TestCase& test_case)
{
	class SystemManager sm;
	
	auto tm = std::make_shared<MockTaskManager>();
	auto sc = std::make_shared<MockSystemContainer>();
	
	sm.SetTaskManager(tm);
	sm.SetSystemContainer(sc);
	
	auto system0 = std::make_shared<TestSystem>(123);
	auto system1 = std::make_shared<TestSystem>(456);
	
	sm.AddSystem(system0);
	sm.AddSystem(system1);
	
	sm.Initialise();
	
	sm.Start();
	
	sm.Run();
	
	test_case.AssertEqual(1, system0->GetRunCount());
	test_case.AssertEqual(1, system1->GetRunCount());
}

void SystemManagerTests::Kill_BeforeStart_Fail(TestCase& test_case)
{
	class SystemManager sm;
	
	auto tm = std::make_shared<MockTaskManager>();
	auto sc = std::make_shared<MockSystemContainer>();
	
	sm.SetTaskManager(tm);
	sm.SetSystemContainer(sc);
	
	sm.Initialise();
	
	test_case.AssertException<std::exception>([&]()
	{
		sm.Kill();
	});
}

void SystemManagerTests::Kill_AfterStart_Success(TestCase& test_case)
{
	class SystemManager sm;
	
	auto tm = std::make_shared<MockTaskManager>();
	auto sc = std::make_shared<MockSystemContainer>();
	
	sm.SetTaskManager(tm);
	sm.SetSystemContainer(sc);
	
	sm.Initialise();
	
	sm.Start();
	
	sm.Kill();
}

void SystemManagerTests::Kill_AlreadyKilled_Fail(TestCase& test_case)
{
	class SystemManager sm;
	
	auto tm = std::make_shared<MockTaskManager>();
	auto sc = std::make_shared<MockSystemContainer>();
	
	sm.SetTaskManager(tm);
	sm.SetSystemContainer(sc);
	
	sm.Initialise();
	
	sm.Start();
	
	sm.Kill();
	
	test_case.AssertException<std::exception>([&]()
	{
		sm.Kill();
	});
}
