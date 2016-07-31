#include "SystemGraphTests.hpp"

#include "MockOptimalPathFinder.hpp"
#include "MockSystemGraph.hpp"
#include "MockSystem.hpp"

#include "../../Code/SystemManager/Exceptions.hpp"

#include <algorithm>

using namespace Fnd::Test;
using namespace Fnd::Test::SystemManager;
using namespace Fnd::SystemManager;

namespace
{
	std::shared_ptr<SystemGraphNode> FindNode( const SystemId& id, const std::vector<std::shared_ptr<SystemGraphNode>>& nodes )
	{
		auto iter = std::find_if( nodes.begin(), nodes.end(), [&] ( const std::shared_ptr<SystemGraphNode>& node )
		{
			return node->GetId() == id;
		});
	
		if ( iter == nodes.end() )
		{
			return nullptr;
		}
		else
		{
			return *iter;
		}
	}
	
	bool ContainsId( const SystemId& id, const std::vector<SystemId>& ids )
	{
		auto iter = std::find( ids.begin(), ids.end(), id );
	
		return iter != ids.end();
	}
}

SystemGraphTests::SystemGraphTests():
UnitTestClass("SystemGraphTests")
{
	AddTestCase( "UpdateSystemNodes_Empty_Success", &SystemGraphTests::UpdateSystemNodes_Empty_Success, this );
	AddTestCase( "UpdateSystemNodes_DuplicateIds_Throw", &SystemGraphTests::UpdateSystemNodes_DuplicateIds_Throw, this );
	AddTestCase( "UpdateSystemNodes_SingleNode_Success", &SystemGraphTests::UpdateSystemNodes_SingleNode_Success, this );
	AddTestCase( "UpdateSystemNodes_NoDependencies_Success", &SystemGraphTests::UpdateSystemNodes_NoDependencies_Success, this );
	AddTestCase( "UpdateSystemNodes_SingleDependency_Success", &SystemGraphTests::UpdateSystemNodes_SingleDependency_Success, this );
	AddTestCase( "UpdateSystemNodes_MultipleDependencies_Success", &SystemGraphTests::UpdateSystemNodes_MultipleDependencies_Success, this );
	AddTestCase( "UpdateSystemNodes_SharedDependencies_Success", &SystemGraphTests::UpdateSystemNodes_SharedDependencies_Success, this );
	AddTestCase( "UpdateSystemNodes_CyclicDependencies_Throw", &SystemGraphTests::UpdateSystemNodes_CyclicDependencies_Throw, this );
	AddTestCase( "GetOptimalPath_Success", &SystemGraphTests::GetOptimalPath_Success, this );
}

void SystemGraphTests::UpdateSystemNodes_Empty_Success( TestCase& test_case )
{
	MockSystemGraph graph;
	
	test_case.Assert( graph.GetSystemNodes().empty() );
}

void SystemGraphTests::UpdateSystemNodes_DuplicateIds_Throw( TestCase& test_case )
{
	MockSystemGraph graph;
	
	std::vector<std::shared_ptr<ISystem>> systems;
	
	auto node0 = std::make_shared<MockSystem>(0);
	auto node1 = std::make_shared<MockSystem>(0);
	
	systems.push_back(node0);
	systems.push_back(node1);
	
	test_case.AssertException<InvalidSystemIdException>([&]()
	{
		graph.UpdateSystemNodes(systems);
	});
	
	test_case.Assert( graph.GetSystemNodes().empty() );
}

void SystemGraphTests::UpdateSystemNodes_SingleNode_Success( TestCase& test_case )
{
/*
	Graph:
		->0->
 */
	MockSystemGraph graph;
	
	std::vector<std::shared_ptr<ISystem>> systems;
	
	auto node0 = std::make_shared<MockSystem>(0);
	
	systems.push_back(node0);
	
	graph.UpdateSystemNodes(systems);
	
	test_case.Assert( graph.GetSystemNodes().size() == 1 );
	test_case.Assert( graph.GetSystemNodes()[0]->GetId() == 0 );
	test_case.Assert( graph.GetSystemNodes()[0]->GetPrev().empty() );
	test_case.Assert( graph.GetSystemNodes()[0]->GetNext().empty() );
}

void SystemGraphTests::UpdateSystemNodes_NoDependencies_Success( TestCase& test_case )
{
/*
	Graph:
		->0->
 
		->1->
*/
	MockSystemGraph graph;
	
	std::vector<std::shared_ptr<ISystem>> systems;
	
	auto node0 = std::make_shared<MockSystem>(0);
	auto node1 = std::make_shared<MockSystem>(1);
	
	systems.push_back(node0);
	systems.push_back(node1);
	
	graph.UpdateSystemNodes(systems);
	
	test_case.Assert( graph.GetSystemNodes().size() == 2 );

	auto node0_out = FindNode( 0, graph.GetSystemNodes() );
	test_case.Assert( node0_out != nullptr );
	test_case.Assert( node0_out->GetId() == 0 );
	test_case.Assert( node0_out->GetPrev().empty() );
	test_case.Assert( node0_out->GetNext().empty() );

	auto node1_out = FindNode( 1, graph.GetSystemNodes() );
	test_case.Assert( node1_out != nullptr );
	test_case.Assert( node1_out->GetId() == 1 );
	test_case.Assert( node1_out->GetPrev().empty() );
	test_case.Assert( node1_out->GetNext().empty() );
}

void SystemGraphTests::UpdateSystemNodes_SingleDependency_Success( TestCase& test_case )
{
/*
	Graph:
		->0->1->
*/
	
	MockSystemGraph graph;
	
	std::vector<std::shared_ptr<ISystem>> systems;
	
	auto node0 = std::make_shared<MockSystem>(0);
	auto node1 = std::make_shared<MockSystem>(1);
	node1->AddDependency(0);
	
	systems.push_back(node0);
	systems.push_back(node1);
	
	graph.UpdateSystemNodes(systems);
	
	test_case.Assert( graph.GetSystemNodes().size() == 2 );
	
	auto node0_out = FindNode( 0, graph.GetSystemNodes() );
	test_case.Assert( node0_out != nullptr );
	test_case.Assert( node0_out->GetId() == 0 );
	test_case.Assert( node0_out->GetPrev().empty() );
	test_case.Assert( node0_out->GetNext().size() == 1 );
	test_case.Assert( ContainsId( 1, node0_out->GetNext() ) );
	
	auto node1_out = FindNode( 1, graph.GetSystemNodes() );
	test_case.Assert( node1_out != nullptr );
	test_case.Assert( node1_out->GetId() == 1 );
	test_case.Assert( node1_out->GetPrev().size() == 1 );
	test_case.Assert( ContainsId( 0, node1_out->GetPrev() ) );
	test_case.Assert( node1_out->GetNext().empty() );
}

void SystemGraphTests::UpdateSystemNodes_MultipleDependencies_Success( TestCase& test_case )
{
/*
	Graph:
		->0->
		->1->2->
 */
	
	MockSystemGraph graph;
	
	std::vector<std::shared_ptr<ISystem>> systems;
	
	auto node0 = std::make_shared<MockSystem>(0);
	auto node1 = std::make_shared<MockSystem>(1);
	auto node2 = std::make_shared<MockSystem>(2);
	node2->AddDependency(0);
	node2->AddDependency(1);
	
	systems.push_back(node0);
	systems.push_back(node1);
	systems.push_back(node2);
	
	graph.UpdateSystemNodes(systems);
	
	test_case.Assert( graph.GetSystemNodes().size() == 3 );
	
	auto node0_out = FindNode( 0, graph.GetSystemNodes() );
	test_case.Assert( node0_out != nullptr );
	test_case.Assert( node0_out->GetId() == 0 );
	test_case.Assert( node0_out->GetPrev().empty() );
	test_case.Assert( node0_out->GetNext().size() == 1 );
	test_case.Assert( ContainsId( 2, node0_out->GetNext() ) );
	
	auto node1_out = FindNode( 1, graph.GetSystemNodes() );
	test_case.Assert( node1_out != nullptr );
	test_case.Assert( node1_out->GetId() == 1 );
	test_case.Assert( node1_out->GetPrev().empty() );
	test_case.Assert( node1_out->GetNext().size() == 1 );
	test_case.Assert( ContainsId( 2, node1_out->GetNext() ) );
	
	auto node2_out = FindNode( 2, graph.GetSystemNodes() );
	test_case.Assert( node2_out != nullptr );
	test_case.Assert( node2_out->GetId() == 2 );
	test_case.Assert( node2_out->GetPrev().size() == 2 );
	test_case.Assert( ContainsId( 0, node2_out->GetPrev() ) );
	test_case.Assert( ContainsId( 1, node2_out->GetPrev() ) );
	test_case.Assert( node2_out->GetNext().empty() );
}

void SystemGraphTests::UpdateSystemNodes_SharedDependencies_Success( TestCase& test_case )
{
/*
	Graph:
		->0->1->
		   ->2->
 */
	
	MockSystemGraph graph;
	
	std::vector<std::shared_ptr<ISystem>> systems;
	
	auto node0 = std::make_shared<MockSystem>(0);
	auto node1 = std::make_shared<MockSystem>(1);
	auto node2 = std::make_shared<MockSystem>(2);
	node1->AddDependency(0);
	node2->AddDependency(0);
	
	systems.push_back(node0);
	systems.push_back(node1);
	systems.push_back(node2);
	
	graph.UpdateSystemNodes(systems);
	
	test_case.Assert( graph.GetSystemNodes().size() == 3 );
	
	auto node0_out = FindNode( 0, graph.GetSystemNodes() );
	test_case.Assert( node0_out != nullptr );
	test_case.Assert( node0_out->GetId() == 0 );
	test_case.Assert( node0_out->GetPrev().empty() );
	test_case.Assert( node0_out->GetNext().size() == 2 );
	test_case.Assert( ContainsId( 1, node0_out->GetNext() ) );
	test_case.Assert( ContainsId( 2, node0_out->GetNext() ) );
	
	auto node1_out = FindNode( 1, graph.GetSystemNodes() );
	test_case.Assert( node1_out != nullptr );
	test_case.Assert( node1_out->GetId() == 1 );
	test_case.Assert( node1_out->GetPrev().size() == 1 );
	test_case.Assert( ContainsId( 0, node1_out->GetPrev() ) );
	test_case.Assert( node1_out->GetNext().empty() );
	
	auto node2_out = FindNode( 2, graph.GetSystemNodes() );
	test_case.Assert( node2_out != nullptr );
	test_case.Assert( node2_out->GetId() == 2 );
	test_case.Assert( node2_out->GetPrev().size() == 1 );
	test_case.Assert( ContainsId( 0, node2_out->GetPrev() ) );
	test_case.Assert( node2_out->GetNext().empty() );
}

void SystemGraphTests::UpdateSystemNodes_Chain_Success( TestCase& test_case )
{
/*
	Graph:
		->0->1->2->
 */
	
	MockSystemGraph graph;
	
	std::vector<std::shared_ptr<ISystem>> systems;
	
	auto node0 = std::make_shared<MockSystem>(0);
	auto node1 = std::make_shared<MockSystem>(1);
	auto node2 = std::make_shared<MockSystem>(2);
	node1->AddDependency(0);
	node2->AddDependency(1);
	
	systems.push_back(node0);
	systems.push_back(node1);
	systems.push_back(node2);
	
	graph.UpdateSystemNodes(systems);
	
	test_case.Assert( graph.GetSystemNodes().size() == 3 );
	
	auto node0_out = FindNode( 0, graph.GetSystemNodes() );
	test_case.Assert( node0_out != nullptr );
	test_case.Assert( node0_out->GetId() == 0 );
	test_case.Assert( node0_out->GetPrev().empty() );
	test_case.Assert( node0_out->GetNext().size() == 1 );
	test_case.Assert( ContainsId( 1, node0_out->GetNext() ) );
	
	auto node1_out = FindNode( 1, graph.GetSystemNodes() );
	test_case.Assert( node1_out != nullptr );
	test_case.Assert( node1_out->GetId() == 1 );
	test_case.Assert( node1_out->GetPrev().size() == 1 );
	test_case.Assert( ContainsId( 0, node1_out->GetPrev() ) );
	test_case.Assert( node1_out->GetNext().size() == 1 );
	test_case.Assert( ContainsId( 2, node1_out->GetNext() ) );
	
	auto node2_out = FindNode( 2, graph.GetSystemNodes() );
	test_case.Assert( node2_out != nullptr );
	test_case.Assert( node2_out->GetId() == 2 );
	test_case.Assert( node2_out->GetPrev().size() == 1 );
	test_case.Assert( ContainsId( 1, node2_out->GetPrev() ) );
	test_case.Assert( node2_out->GetNext().empty() );
}

void SystemGraphTests::UpdateSystemNodes_CyclicDependencies_Throw( TestCase& test_case )
{
	/*
	Graph:
		->0->1->
		  <--/
	 */
	
	MockSystemGraph graph;
	
	std::vector<std::shared_ptr<ISystem>> systems;
	
	auto node0 = std::make_shared<MockSystem>(0);
	auto node1 = std::make_shared<MockSystem>(1);
	node0->AddDependency(1);
	node1->AddDependency(0);
	
	systems.push_back(node0);
	systems.push_back(node1);
	
	test_case.AssertException<InvalidSystemDependenciesException>([&]()
	{
		graph.UpdateSystemNodes(systems);
	});
	
	test_case.Assert( graph.GetSystemNodes().empty() );
}

void SystemGraphTests::GetOptimalPath_Success(TestCase &test_case)
{
	SystemGraph system_graph;
	
	OptimalPathFinderPtr opf = std::make_shared<MockOptimalPathFinder>();
	
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
