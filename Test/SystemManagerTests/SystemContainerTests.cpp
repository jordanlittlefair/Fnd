#include "SystemContainerTests.hpp"

#include "MockCyclicGraphChecker.hpp"
#include "MockSystem.hpp"
#include "MockSystemGraph.hpp"
#include "MockTaskProvider.hpp"

#include "../../Code/SystemManager/Exceptions.hpp"
#include "../../Code/SystemManager/SystemContainer.hpp"

#include <algorithm>

using namespace Fnd::Test;
using namespace Fnd::Test::SystemManager;
using namespace Fnd::SystemManager;

SystemContainerTests::SystemContainerTests():
	UnitTestClass("SystemContainerTests")
{
	AddTestCase( "SetTaskProvider_SetsOnSystemAddedBefore", &SystemContainerTests::SetTaskProvider_SetsOnSystemAddedBefore, this );
	AddTestCase( "SetTaskProvider_SetsOnSystemAddedAfter", &SystemContainerTests::SetTaskProvider_SetsOnSystemAddedAfter, this );
	
	AddTestCase( "AddSystem_BeforeInitialise_Success", &SystemContainerTests::AddSystem_BeforeInitialise_Success, this );
	AddTestCase( "AddSystem_DuplicateId_Throw", &SystemContainerTests::AddSystem_DuplicateId_Throw, this );
	AddTestCase( "AddSystem_AfterInitialise_Fail", &SystemContainerTests::AddSystem_AfterInitialise_Fail, this );
	
	AddTestCase( "IsInitialised_BeforeInitialise_False", &SystemContainerTests::IsInitialised_BeforeInitialise_False, this );
	AddTestCase( "IsInitialised_AfterInitialise_True", &SystemContainerTests::IsInitialised_AfterInitialise_True, this );
	
	AddTestCase( "Initialise_SystemsInitialised_Success", &SystemContainerTests::Initialise_SystemsInitialised_Success, this );
	AddTestCase( "Initialise_SystemFailsToInitialise_Throw", &SystemContainerTests::Initialise_SystemFailsToInitialise_Throw, this );
	
	AddTestCase( "GetOrderedSystems_Success", &SystemContainerTests::GetOrderedSystems_Success, this );
}

void SystemContainerTests::SetTaskProvider_SetsOnSystemAddedBefore(TestCase& test_case)
{
	SystemContainer sc;
	SystemGraphPtr sg = std::make_shared<MockSystemGraph>();
	TaskProviderPtr tp = std::make_shared<MockTaskProvider>();
	CyclicGraphCheckerPtr cgc = std::make_shared<MockCyclicGraphChecker>();
	
	sc.SetSystemGraph(sg);
	
	auto system = std::make_shared<MockSystem>(123);
	
	sc.AddSystem(system);
	
	test_case.Assert(!system->HasTaskProvider());
	
	sc.SetTaskProvider(tp);
	
	test_case.Assert(system->HasTaskProvider());
}

void SystemContainerTests::SetTaskProvider_SetsOnSystemAddedAfter(TestCase& test_case)
{
	SystemContainer sc;
	SystemGraphPtr sg = std::make_shared<MockSystemGraph>();
	TaskProviderPtr tp = std::make_shared<MockTaskProvider>();
	CyclicGraphCheckerPtr cgc = std::make_shared<MockCyclicGraphChecker>();
	
	sc.SetSystemGraph(sg);
	
	auto system = std::make_shared<MockSystem>(123);
	
	sc.SetTaskProvider(tp);
	
	test_case.Assert(!system->HasTaskProvider());
	
	sc.AddSystem(system);
	
	test_case.Assert(system->HasTaskProvider());
}

void SystemContainerTests::AddSystem_BeforeInitialise_Success(TestCase& test_case)
{
	SystemContainer sc;
	SystemGraphPtr sg = std::make_shared<MockSystemGraph>();
	TaskProviderPtr tp = std::make_shared<MockTaskProvider>();
	CyclicGraphCheckerPtr cgc = std::make_shared<MockCyclicGraphChecker>();
	
	sc.SetSystemGraph(sg);
	
	auto system = std::make_shared<MockSystem>(123);
	
	sc.AddSystem(system);
	
	auto systems = sc.GetOrderedSystems();

	test_case.Assert(std::find_if(systems.begin(), systems.end(), [&](SystemPtr system_iter)
	{
		return system_iter->GetId() == system->GetId();
	}) != systems.end());
}

void SystemContainerTests::AddSystem_DuplicateId_Throw(TestCase& test_case)
{
	SystemContainer sc;
	SystemGraphPtr sg = std::make_shared<MockSystemGraph>();
	TaskProviderPtr tp = std::make_shared<MockTaskProvider>();
	CyclicGraphCheckerPtr cgc = std::make_shared<MockCyclicGraphChecker>();
	
	sc.SetSystemGraph(sg);
	
	auto system0 = std::make_shared<MockSystem>(123);
	auto system1 = std::make_shared<MockSystem>(123);
	
	sc.AddSystem(system0);
	
	test_case.AssertException<InvalidSystemIdException>([&]()
	{
		sc.AddSystem(system1);
	});
}

void SystemContainerTests::AddSystem_AfterInitialise_Fail(TestCase& test_case)
{
	SystemContainer sc;
	SystemGraphPtr sg = std::make_shared<MockSystemGraph>();
	TaskProviderPtr tp = std::make_shared<MockTaskProvider>();
	CyclicGraphCheckerPtr cgc = std::make_shared<MockCyclicGraphChecker>();
	
	sc.SetSystemGraph(sg);
	
	auto system = std::make_shared<MockSystem>(123);
	
	sc.Initialise();
	
	test_case.AssertException<InvalidOperationException>([&]()
	{
		sc.AddSystem(system);
	});
}

void SystemContainerTests::GetOrderedSystems_Success(TestCase& test_case)
{
	SystemContainer sc;
	SystemGraphPtr sg = std::make_shared<MockSystemGraph>();
	TaskProviderPtr tp = std::make_shared<MockTaskProvider>();
	CyclicGraphCheckerPtr cgc = std::make_shared<MockCyclicGraphChecker>();
	
	sc.SetSystemGraph(sg);
	
	auto system0 = std::make_shared<MockSystem>(123);
	auto system1 = std::make_shared<MockSystem>(456);
	
	sc.AddSystem(system0);
	sc.AddSystem(system1);
	
	auto systems = sc.GetOrderedSystems();
	
	test_case.Assert(std::find_if(systems.begin(), systems.end(), [&](SystemPtr system_iter)
	{
		return system_iter->GetId() == system0->GetId();
	}) != systems.end());
	
	test_case.Assert(std::find_if(systems.begin(), systems.end(), [&](SystemPtr system_iter)
	{
		return system_iter->GetId() == system1->GetId();
	}) != systems.end());
}

void SystemContainerTests::IsInitialised_BeforeInitialise_False(TestCase& test_case)
{
	SystemContainer sc;
	SystemGraphPtr sg = std::make_shared<MockSystemGraph>();
	TaskProviderPtr tp = std::make_shared<MockTaskProvider>();
	CyclicGraphCheckerPtr cgc = std::make_shared<MockCyclicGraphChecker>();
	
	sc.SetSystemGraph(sg);

	test_case.Assert(!sc.IsInitialised());
}

void SystemContainerTests::IsInitialised_AfterInitialise_True(TestCase& test_case)
{
	SystemContainer sc;
	SystemGraphPtr sg = std::make_shared<MockSystemGraph>();
	TaskProviderPtr tp = std::make_shared<MockTaskProvider>();
	CyclicGraphCheckerPtr cgc = std::make_shared<MockCyclicGraphChecker>();
	
	sc.SetSystemGraph(sg);
	
	sc.Initialise();
	
	test_case.Assert(sc.IsInitialised());
}

void SystemContainerTests::Initialise_SystemsInitialised_Success(TestCase& test_case)
{
	SystemContainer sc;
	SystemGraphPtr sg = std::make_shared<MockSystemGraph>();
	TaskProviderPtr tp = std::make_shared<MockTaskProvider>();
	CyclicGraphCheckerPtr cgc = std::make_shared<MockCyclicGraphChecker>();
	
	sc.SetSystemGraph(sg);
	
	SystemPtr system0 = std::make_shared<MockSystem>(123);
	SystemPtr system1 = std::make_shared<MockSystem>(456);
	
	sc.AddSystem(system0);
	sc.AddSystem(system1);
	
	test_case.Assert(!system0->IsInitialised());
	test_case.Assert(!system1->IsInitialised());
	
	sc.Initialise();
	
	test_case.Assert(sc.IsInitialised());
	test_case.Assert(system0->IsInitialised());
	test_case.Assert(system1->IsInitialised());
}

void SystemContainerTests::Initialise_SystemFailsToInitialise_Throw(TestCase& test_case)
{
	class TestSystem:
		public MockSystem
	{
	public:
		TestSystem(const SystemId id):
			MockSystem(id)
		{
		}
	protected:
		void OnInitialise()
		{
			throw std::runtime_error("Failed to initialise System");
		}
	};
	
	SystemContainer sc;
	SystemGraphPtr sg = std::make_shared<MockSystemGraph>();
	TaskProviderPtr tp = std::make_shared<MockTaskProvider>();
	CyclicGraphCheckerPtr cgc = std::make_shared<MockCyclicGraphChecker>();
	
	sc.SetSystemGraph(sg);
	
	SystemPtr system = std::make_shared<TestSystem>(123);
	
	sc.AddSystem(system);
	
	test_case.Assert(!system->IsInitialised());
	
	test_case.AssertException<std::exception>([&]()
	{
		sc.Initialise();
	});
	
	test_case.Assert(!sc.IsInitialised());
	test_case.Assert(!system->IsInitialised());
}

