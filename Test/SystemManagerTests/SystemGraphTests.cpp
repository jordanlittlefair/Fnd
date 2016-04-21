#include "SystemGraphTests.hpp"

#include "MockSystemGraph.hpp"
#include "MockSystem.hpp"

#include "../../Code/SystemManager/Exceptions.hpp"

#include <algorithm>

using namespace Fnd::Test::SystemManager;
using namespace Fnd::SystemManager;

namespace
{
	std::shared_ptr<SystemGraphNode> FindNode( const ISystem::Id& id, const std::vector<std::shared_ptr<SystemGraphNode>>& nodes )
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
	
	bool ContainsId( const ISystem::Id& id, const std::vector<ISystem::Id>& ids )
	{
		auto iter = std::find( ids.begin(), ids.end(), id );
	
		return iter != ids.end();
	}
}

SystemGraphTests::SystemGraphTests():
TestClass("SystemGraphTests")
{
	AddTestCase( "TestUpdateSystemNodes_Empty", &SystemGraphTests::TestUpdateSystemNodes_Empty, this );
	AddTestCase( "TestUpdateSystemNodes_DuplicateIds", &SystemGraphTests::TestUpdateSystemNodes_DuplicateIds, this );
	AddTestCase( "TestUpdateSystemNodes_SingleNode", &SystemGraphTests::TestUpdateSystemNodes_SingleNode, this );
	AddTestCase( "TestUpdateSystemNodes_NoDependencies", &SystemGraphTests::TestUpdateSystemNodes_NoDependencies, this );
	AddTestCase( "TestUpdateSystemNodes_SingleDependency", &SystemGraphTests::TestUpdateSystemNodes_SingleDependency, this );
	AddTestCase( "TestUpdateSystemNodes_MultipleDependencies", &SystemGraphTests::TestUpdateSystemNodes_MultipleDependencies, this );
	AddTestCase( "TestUpdateSystemNodes_SharedDependencies", &SystemGraphTests::TestUpdateSystemNodes_SharedDependencies, this );
}

void SystemGraphTests::TestUpdateSystemNodes_Empty( TestCase& test_case )
{
	MockSystemGraph graph;
	
	test_case.Assert( graph.GetSystemNodes().empty() );
}

void SystemGraphTests::TestUpdateSystemNodes_DuplicateIds( TestCase& test_case )
{
	MockSystemGraph graph;
	
	std::vector<std::shared_ptr<ISystem>> systems;
	
	auto node0 = std::make_shared<MockSystem>("0");
	auto node1 = std::make_shared<MockSystem>("0");
	
	systems.push_back(node0);
	systems.push_back(node1);
	
	bool caught_exception = false;
	
	try
	{
		graph.UpdateSystemNodes(systems);
	}
	catch ( const InvalidSystemIdException& )
	{
		caught_exception = true;
	}
	
	test_case.Assert( caught_exception );
	test_case.Assert( graph.GetSystemNodes().empty() );
}

void SystemGraphTests::TestUpdateSystemNodes_SingleNode( TestCase& test_case )
{
/*
	Graph:
		->0->
 */
	MockSystemGraph graph;
	
	std::vector<std::shared_ptr<ISystem>> systems;
	
	auto node0 = std::make_shared<MockSystem>("0");
	
	systems.push_back(node0);
	
	graph.UpdateSystemNodes(systems);
	
	test_case.Assert( graph.GetSystemNodes().size() == 1 );
	test_case.Assert( graph.GetSystemNodes()[0]->GetId() == "0" );
	test_case.Assert( graph.GetSystemNodes()[0]->GetPrev().empty() );
	test_case.Assert( graph.GetSystemNodes()[0]->GetNext().empty() );
}

void SystemGraphTests::TestUpdateSystemNodes_NoDependencies( TestCase& test_case )
{
/*
	Graph:
		->0->
 
		->1->
*/
	MockSystemGraph graph;
	
	std::vector<std::shared_ptr<ISystem>> systems;
	
	auto node0 = std::make_shared<MockSystem>("0");
	auto node1 = std::make_shared<MockSystem>("1");
	
	systems.push_back(node0);
	systems.push_back(node1);
	
	graph.UpdateSystemNodes(systems);
	
	test_case.Assert( graph.GetSystemNodes().size() == 2 );

	auto node0_out = FindNode( "0", graph.GetSystemNodes() );
	test_case.Assert( node0_out != nullptr );
	test_case.Assert( node0_out->GetId() == "0" );
	test_case.Assert( node0_out->GetPrev().empty() );
	test_case.Assert( node0_out->GetNext().empty() );

	auto node1_out = FindNode( "1", graph.GetSystemNodes() );
	test_case.Assert( node1_out != nullptr );
	test_case.Assert( node1_out->GetId() == "1" );
	test_case.Assert( node1_out->GetPrev().empty() );
	test_case.Assert( node1_out->GetNext().empty() );
}

void SystemGraphTests::TestUpdateSystemNodes_SingleDependency( TestCase& test_case )
{
/*
	Graph:
		->0->1->
*/
	
	MockSystemGraph graph;
	
	std::vector<std::shared_ptr<ISystem>> systems;
	
	auto node0 = std::make_shared<MockSystem>("0");
	auto node1 = std::make_shared<MockSystem>("1");
	node1->AddDependency("0");
	
	systems.push_back(node0);
	systems.push_back(node1);
	
	graph.UpdateSystemNodes(systems);
	
	test_case.Assert( graph.GetSystemNodes().size() == 2 );
	
	auto node0_out = FindNode( "0", graph.GetSystemNodes() );
	test_case.Assert( node0_out != nullptr );
	test_case.Assert( node0_out->GetId() == "0" );
	test_case.Assert( node0_out->GetPrev().empty() );
	test_case.Assert( node0_out->GetNext().size() == 1 );
	test_case.Assert( ContainsId( "1", node0_out->GetNext() ) );
	
	auto node1_out = FindNode( "1", graph.GetSystemNodes() );
	test_case.Assert( node1_out != nullptr );
	test_case.Assert( node1_out->GetId() == "1" );
	test_case.Assert( node1_out->GetPrev().size() == 1 );
	test_case.Assert( ContainsId( "0", node1_out->GetPrev() ) );
	test_case.Assert( node1_out->GetNext().empty() );
}

void SystemGraphTests::TestUpdateSystemNodes_MultipleDependencies( TestCase& test_case )
{
/*
	Graph:
		->0->
		->1->2->
 */
	
	MockSystemGraph graph;
	
	std::vector<std::shared_ptr<ISystem>> systems;
	
	auto node0 = std::make_shared<MockSystem>("0");
	auto node1 = std::make_shared<MockSystem>("1");
	auto node2 = std::make_shared<MockSystem>("2");
	node2->AddDependency("0");
	node2->AddDependency("1");
	
	systems.push_back(node0);
	systems.push_back(node1);
	systems.push_back(node2);
	
	graph.UpdateSystemNodes(systems);
	
	test_case.Assert( graph.GetSystemNodes().size() == 3 );
	
	auto node0_out = FindNode( "0", graph.GetSystemNodes() );
	test_case.Assert( node0_out != nullptr );
	test_case.Assert( node0_out->GetId() == "0" );
	test_case.Assert( node0_out->GetPrev().empty() );
	test_case.Assert( node0_out->GetNext().size() == 1 );
	test_case.Assert( ContainsId( "2", node0_out->GetNext() ) );
	
	auto node1_out = FindNode( "1", graph.GetSystemNodes() );
	test_case.Assert( node1_out != nullptr );
	test_case.Assert( node1_out->GetId() == "1" );
	test_case.Assert( node1_out->GetPrev().empty() );
	test_case.Assert( node1_out->GetNext().size() == 1 );
	test_case.Assert( ContainsId( "2", node1_out->GetNext() ) );
	
	auto node2_out = FindNode( "2", graph.GetSystemNodes() );
	test_case.Assert( node2_out != nullptr );
	test_case.Assert( node2_out->GetId() == "2" );
	test_case.Assert( node2_out->GetPrev().size() == 2 );
	test_case.Assert( ContainsId( "0", node2_out->GetPrev() ) );
	test_case.Assert( ContainsId( "1", node2_out->GetPrev() ) );
	test_case.Assert( node2_out->GetNext().empty() );
}

void SystemGraphTests::TestUpdateSystemNodes_SharedDependencies( TestCase& test_case )
{
/*
	Graph:
		->0->1->
		   ->2->
 */
	
	MockSystemGraph graph;
	
	std::vector<std::shared_ptr<ISystem>> systems;
	
	auto node0 = std::make_shared<MockSystem>("0");
	auto node1 = std::make_shared<MockSystem>("1");
	auto node2 = std::make_shared<MockSystem>("2");
	node1->AddDependency("0");
	node2->AddDependency("0");
	
	systems.push_back(node0);
	systems.push_back(node1);
	systems.push_back(node2);
	
	graph.UpdateSystemNodes(systems);
	
	test_case.Assert( graph.GetSystemNodes().size() == 3 );
	
	auto node0_out = FindNode( "0", graph.GetSystemNodes() );
	test_case.Assert( node0_out != nullptr );
	test_case.Assert( node0_out->GetId() == "0" );
	test_case.Assert( node0_out->GetPrev().empty() );
	test_case.Assert( node0_out->GetNext().size() == 2 );
	test_case.Assert( ContainsId( "1", node0_out->GetNext() ) );
	test_case.Assert( ContainsId( "2", node0_out->GetNext() ) );
	
	auto node1_out = FindNode( "1", graph.GetSystemNodes() );
	test_case.Assert( node1_out != nullptr );
	test_case.Assert( node1_out->GetId() == "1" );
	test_case.Assert( node1_out->GetPrev().size() == 1 );
	test_case.Assert( ContainsId( "0", node1_out->GetPrev() ) );
	test_case.Assert( node1_out->GetNext().empty() );
	
	auto node2_out = FindNode( "2", graph.GetSystemNodes() );
	test_case.Assert( node2_out != nullptr );
	test_case.Assert( node2_out->GetId() == "2" );
	test_case.Assert( node2_out->GetPrev().size() == 1 );
	test_case.Assert( ContainsId( "0", node2_out->GetPrev() ) );
	test_case.Assert( node2_out->GetNext().empty() );
}

void SystemGraphTests::TestUpdateSystemNodes_Chain( TestCase& test_case )
{
/*
	Graph:
		->0->1->2->
 */
	
	MockSystemGraph graph;
	
	std::vector<std::shared_ptr<ISystem>> systems;
	
	auto node0 = std::make_shared<MockSystem>("0");
	auto node1 = std::make_shared<MockSystem>("1");
	auto node2 = std::make_shared<MockSystem>("2");
	node1->AddDependency("0");
	node2->AddDependency("1");
	
	systems.push_back(node0);
	systems.push_back(node1);
	systems.push_back(node2);
	
	graph.UpdateSystemNodes(systems);
	
	test_case.Assert( graph.GetSystemNodes().size() == 3 );
	
	auto node0_out = FindNode( "0", graph.GetSystemNodes() );
	test_case.Assert( node0_out != nullptr );
	test_case.Assert( node0_out->GetId() == "0" );
	test_case.Assert( node0_out->GetPrev().empty() );
	test_case.Assert( node0_out->GetNext().size() == 1 );
	test_case.Assert( ContainsId( "1", node0_out->GetNext() ) );
	
	auto node1_out = FindNode( "1", graph.GetSystemNodes() );
	test_case.Assert( node1_out != nullptr );
	test_case.Assert( node1_out->GetId() == "1" );
	test_case.Assert( node1_out->GetPrev().size() == 1 );
	test_case.Assert( ContainsId( "0", node1_out->GetPrev() ) );
	test_case.Assert( node1_out->GetNext().size() == 1 );
	test_case.Assert( ContainsId( "2", node1_out->GetNext() ) );
	
	auto node2_out = FindNode( "2", graph.GetSystemNodes() );
	test_case.Assert( node2_out != nullptr );
	test_case.Assert( node2_out->GetId() == "2" );
	test_case.Assert( node2_out->GetPrev().size() == 1 );
	test_case.Assert( ContainsId( "1", node2_out->GetPrev() ) );
	test_case.Assert( node2_out->GetNext().empty() );
}
