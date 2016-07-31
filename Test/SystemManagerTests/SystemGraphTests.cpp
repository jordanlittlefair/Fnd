#include "SystemGraphTests.hpp"

#include "MockCyclicGraphChecker.hpp"
#include "MockOptimalPathFinder.hpp"
#include "MockSystemGraph.hpp"
#include "MockSystem.hpp"

#include "../../Code/SystemManager/Exceptions.hpp"

using namespace Fnd::Test;
using namespace Fnd::Test::SystemManager;
using namespace Fnd::SystemManager;


SystemGraphTests::SystemGraphTests():
UnitTestClass("SystemGraphTests")
{
	AddTestCase( "UpdateSystemNodes_NotCyclic_Success", &SystemGraphTests::UpdateSystemNodes_NotCyclic_Success, this );
	AddTestCase( "UpdateSystemNodes_Cyclic_Throw", &SystemGraphTests::UpdateSystemNodes_Cyclic_Throw, this );
	AddTestCase( "UpdateSystemNodes_HasNodes", &SystemGraphTests::UpdateSystemNodes_HasNodes, this );
	AddTestCase( "GetOptimalPath_Success", &SystemGraphTests::GetOptimalPath_Success, this );
}

void SystemGraphTests::UpdateSystemNodes_NotCyclic_Success(TestCase& test_case)
{
	SystemGraph system_graph;
	
	CyclicGraphCheckerPtr cgc = std::make_shared<MockCyclicGraphChecker>();
	
	OptimalPathFinderPtr opf = std::make_shared<MockOptimalPathFinder>();
	
	system_graph.SetCyclicGraphChecker(cgc);
	system_graph.SetOptimalPathFinder(opf);
	
	std::vector<std::shared_ptr<ISystem>> systems;
	
	auto node0 = std::make_shared<MockSystem>(123);
	auto node1 = std::make_shared<MockSystem>(456);
	
	systems.push_back(node0);
	systems.push_back(node1);
	
	system_graph.UpdateSystemNodes(systems);
}

void SystemGraphTests::UpdateSystemNodes_Cyclic_Throw(TestCase& test_case)
{
	SystemGraph system_graph;
	
	auto cgc = std::make_shared<MockCyclicGraphChecker>();
	cgc->SetIsCyclicResult(true); // Mock the cyclic check
	
	OptimalPathFinderPtr opf = std::make_shared<MockOptimalPathFinder>();
	
	system_graph.SetCyclicGraphChecker(cgc);
	system_graph.SetOptimalPathFinder(opf);
	
	std::vector<std::shared_ptr<ISystem>> systems;
	
	auto node0 = std::make_shared<MockSystem>(123);
	auto node1 = std::make_shared<MockSystem>(456);
	
	systems.push_back(node0);
	systems.push_back(node1);
	
	test_case.AssertException<InvalidSystemDependenciesException>([&]()
	{
		system_graph.UpdateSystemNodes(systems);
	});
}

void SystemGraphTests::UpdateSystemNodes_HasNodes(TestCase& test_case)
{
	MockSystemGraph system_graph;
	
	CyclicGraphCheckerPtr cgc = std::make_shared<MockCyclicGraphChecker>();
	
	OptimalPathFinderPtr opf = std::make_shared<MockOptimalPathFinder>();
	
	system_graph.SetCyclicGraphChecker(cgc);
	system_graph.SetOptimalPathFinder(opf);
	
	std::vector<std::shared_ptr<ISystem>> systems;
	
	auto node0 = std::make_shared<MockSystem>(123);
	auto node1 = std::make_shared<MockSystem>(456);
	
	systems.push_back(node0);
	systems.push_back(node1);
	
	system_graph.UpdateSystemNodes(systems);
	
	test_case.Assert(system_graph.GetSystemNodes()[0]->GetId() == 123);
	test_case.Assert(system_graph.GetSystemNodes()[1]->GetId() == 456);
}

void SystemGraphTests::GetOptimalPath_Success(TestCase &test_case)
{
	SystemGraph system_graph;
	
	CyclicGraphCheckerPtr cgc = std::make_shared<MockCyclicGraphChecker>();
	
	OptimalPathFinderPtr opf = std::make_shared<MockOptimalPathFinder>();
	
	system_graph.SetCyclicGraphChecker(cgc);
	system_graph.SetOptimalPathFinder(opf);
	
	std::vector<std::shared_ptr<ISystem>> systems;
	
	auto node0 = std::make_shared<MockSystem>(123);
	auto node1 = std::make_shared<MockSystem>(456);
	
	systems.push_back(node0);
	systems.push_back(node1);
	
	system_graph.UpdateSystemNodes(systems);
	
	auto optimal_path = system_graph.GetOptimalPath();
	
	test_case.Assert(optimal_path[0] == 123);
	test_case.Assert(optimal_path[1] == 456);
}
