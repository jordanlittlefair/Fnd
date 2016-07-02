#include "OptimalPathFinderTests.hpp"

#include "../../Code/SystemManager/OptimalPathFinder.hpp"

using namespace Fnd::Test;
using namespace Fnd::Test::SystemManager;
using namespace Fnd::SystemManager;

namespace
{

bool ContainsId( const SystemId& id, const std::vector<SystemId>& ids )
{
	auto iter = std::find( ids.begin(), ids.end(), id );
	
	return iter != ids.end();
}

bool InOrder( const SystemId& before, const SystemId& after, const std::vector<SystemId>& ids )
{
	int before_index = std::numeric_limits<int>::max();
	int after_index = std::numeric_limits<int>::min();
	
	for ( unsigned int i = 0; i < ids.size(); ++i )
	{
		if ( ids[i] == before )
		{
			before_index = i;
		}
	
		if ( ids[i] == after )
		{
			after_index = i;
		}
	}
	
	return before_index < after_index;
}

}

OptimalPathFinderTests::OptimalPathFinderTests():
	TestClass("OptimalPathFinderTests")
{
	AddTestCase( "TestConstructor", &OptimalPathFinderTests::TestConstructor, this );
	AddTestCase( "TestClearSystemNodes", &OptimalPathFinderTests::TestClearSystemNodes, this );
	AddTestCase( "TestOptimalPath_Empty", &OptimalPathFinderTests::TestOptimalPath_Empty, this );
	AddTestCase( "TestOptimalPath_NoDependencies", &OptimalPathFinderTests::TestOptimalPath_NoDependencies, this );
	AddTestCase( "TestOptimalPath_DependencyChain", &OptimalPathFinderTests::TestOptimalPath_DependencyChain, this );
	AddTestCase( "TestOptimalPath_MultipleDependencies", &OptimalPathFinderTests::TestOptimalPath_MultipleDependencies, this );
	AddTestCase( "TestOptimalPath_SharedDependency", &OptimalPathFinderTests::TestOptimalPath_SharedDependency, this );
	AddTestCase( "TestOptimalPath_ForkAndJoin", &OptimalPathFinderTests::TestOptimalPath_ForkAndJoin, this );
}

void OptimalPathFinderTests::TestConstructor( TestCase& test_case )
{
	std::vector<std::shared_ptr<SystemGraphNode>> nodes;
	
	auto node0 = std::make_shared<SystemGraphNode>(0);
	
	nodes.push_back(node0);
	
	OptimalPathFinder opf(nodes);
	
	test_case.Assert( opf.GetOptimalPath().size() == 1 );
}

void OptimalPathFinderTests::TestClearSystemNodes( TestCase& test_case )
{
	OptimalPathFinder opf;
	
	std::vector<std::shared_ptr<SystemGraphNode>> nodes;
	
	auto node0 = std::make_shared<SystemGraphNode>(0);
	
	nodes.push_back(node0);
	
	opf.UpdateSystemGraphNodes(nodes);
	
	test_case.Assert( opf.GetOptimalPath().size() == 1 );
	
	opf.ClearSystemNodes();
	
	test_case.Assert( opf.GetOptimalPath().size() == 0 );
}

void OptimalPathFinderTests::TestOptimalPath_Empty( TestCase& test_case )
{
	OptimalPathFinder opf;
	
	std::vector<std::shared_ptr<SystemGraphNode>> nodes;
	
	opf.UpdateSystemGraphNodes(nodes);
	
	test_case.Assert( opf.GetOptimalPath().empty() );
}

void OptimalPathFinderTests::TestOptimalPath_NoDependencies( TestCase& test_case )
{
	OptimalPathFinder opf;
	
	std::vector<std::shared_ptr<SystemGraphNode>> nodes;
	
	auto node0 = std::make_shared<SystemGraphNode>(0);
	auto node1 = std::make_shared<SystemGraphNode>(1);
	auto node2 = std::make_shared<SystemGraphNode>(2);
	
	nodes.push_back(node0);
	nodes.push_back(node1);
	nodes.push_back(node2);
	
	opf.UpdateSystemGraphNodes(nodes);
	
	auto optimalPath = opf.GetOptimalPath();
	
	test_case.Assert( optimalPath.size() == 3 );
	test_case.Assert( ContainsId( 0, optimalPath ) );
	test_case.Assert( ContainsId( 1, optimalPath ) );
	test_case.Assert( ContainsId( 2, optimalPath ) );
}

void OptimalPathFinderTests::TestOptimalPath_DependencyChain( TestCase& test_case )
{
/*
	Graph:
		->2->1->0->
*/
	
	OptimalPathFinder opf;
	
	std::vector<std::shared_ptr<SystemGraphNode>> nodes;
	
	auto node0 = std::make_shared<SystemGraphNode>(0);
	auto node1 = std::make_shared<SystemGraphNode>(1);
	auto node2 = std::make_shared<SystemGraphNode>(2);
	
	// order: 2 -> 1 -> 0
	node2->AddNext(1);	node1->AddPrev(2);
	node1->AddNext(0);	node0->AddPrev(1);
	
	nodes.push_back(node0);
	nodes.push_back(node1);
	nodes.push_back(node2);
	
	opf.UpdateSystemGraphNodes(nodes);
	
	auto optimalPath = opf.GetOptimalPath();
	
	test_case.Assert( optimalPath.size() == 3 );
	test_case.Assert( ContainsId( 0, optimalPath ) );
	test_case.Assert( ContainsId( 1, optimalPath ) );
	test_case.Assert( ContainsId( 2, optimalPath ) );
	test_case.Assert( InOrder( 2, 1, optimalPath ) );
	test_case.Assert( InOrder( 1, 0, optimalPath ) );
}

void OptimalPathFinderTests::TestOptimalPath_MultipleDependencies( TestCase& test_case )
{
/*
	Graph:
		->0->
		->1->2->
*/
	OptimalPathFinder opf;
	
	std::vector<std::shared_ptr<SystemGraphNode>> nodes;
	
	auto node0 = std::make_shared<SystemGraphNode>(0);
	auto node1 = std::make_shared<SystemGraphNode>(1);
	auto node2 = std::make_shared<SystemGraphNode>(2);
	
	node0->AddNext(2);	node2->AddPrev(0);
	node1->AddNext(2);	node2->AddPrev(1);
	
	nodes.push_back(node2);
	nodes.push_back(node1);
	nodes.push_back(node0);

	opf.UpdateSystemGraphNodes(nodes);
	
	auto optimalPath = opf.GetOptimalPath();
	
	test_case.Assert( optimalPath.size() == 3 );
	test_case.Assert( ContainsId( 0, optimalPath ) );
	test_case.Assert( ContainsId( 1, optimalPath ) );
	test_case.Assert( ContainsId( 2, optimalPath ) );
	test_case.Assert( InOrder( 0, 2, optimalPath ) );
	test_case.Assert( InOrder( 1, 2, optimalPath ) );
}

void OptimalPathFinderTests::TestOptimalPath_SharedDependency( TestCase& test_case )
{
/*
	Graph:
		->0->1->
		   ->2->
*/
	OptimalPathFinder opf;
	
	std::vector<std::shared_ptr<SystemGraphNode>> nodes;
	
	auto node0 = std::make_shared<SystemGraphNode>(0);
	auto node1 = std::make_shared<SystemGraphNode>(1);
	auto node2 = std::make_shared<SystemGraphNode>(2);
	
	node0->AddNext(1);	node1->AddPrev(0);
	node0->AddNext(2);	node2->AddPrev(0);
	
	nodes.push_back(node2);
	nodes.push_back(node1);
	nodes.push_back(node0);
	
	opf.UpdateSystemGraphNodes(nodes);
	
	auto optimalPath = opf.GetOptimalPath();
	
	test_case.Assert( optimalPath.size() == 3 );
	test_case.Assert( ContainsId( 0, optimalPath ) );
	test_case.Assert( ContainsId( 1, optimalPath ) );
	test_case.Assert( ContainsId( 2, optimalPath ) );
	test_case.Assert( InOrder( 0, 2, optimalPath ) );
	test_case.Assert( InOrder( 0, 2, optimalPath ) );
}

void OptimalPathFinderTests::TestOptimalPath_ForkAndJoin( TestCase& test_case )
{
/*
	Graph:
		->0->1->2->3->
		   \      /
		   ->4->5->
*/
	OptimalPathFinder opf;
	
	std::vector<std::shared_ptr<SystemGraphNode>> nodes;
	
	auto node0 = std::make_shared<SystemGraphNode>(0);
	auto node1 = std::make_shared<SystemGraphNode>(1);
	auto node2 = std::make_shared<SystemGraphNode>(2);
	auto node3 = std::make_shared<SystemGraphNode>(3);
	auto node4 = std::make_shared<SystemGraphNode>(4);
	auto node5 = std::make_shared<SystemGraphNode>(5);
	
	node0->AddNext(1);	node1->AddPrev(0);
	node0->AddNext(4);	node4->AddPrev(0);
	
	node1->AddNext(2);	node2->AddPrev(1);
	
	node2->AddNext(3);	node3->AddPrev(2);
	
	node4->AddNext(5);	node5->AddPrev(4);
	
	node5->AddNext(3);	node3->AddPrev(5);
	
	nodes.push_back(node0);
	nodes.push_back(node1);
	nodes.push_back(node2);
	nodes.push_back(node3);
	nodes.push_back(node4);
	nodes.push_back(node5);
	
	opf.UpdateSystemGraphNodes(nodes);
	
	auto optimalPath = opf.GetOptimalPath();
	
	test_case.Assert( optimalPath.size() == 6 );
	test_case.Assert( ContainsId( 0, optimalPath ) );
	test_case.Assert( ContainsId( 1, optimalPath ) );
	test_case.Assert( ContainsId( 2, optimalPath ) );
	test_case.Assert( ContainsId( 3, optimalPath ) );
	test_case.Assert( ContainsId( 4, optimalPath ) );
	test_case.Assert( ContainsId( 5, optimalPath ) );
	test_case.Assert( InOrder( 0, 1, optimalPath ) );
	test_case.Assert( InOrder( 0, 4, optimalPath ) );
	test_case.Assert( InOrder( 1, 2, optimalPath ) );
	test_case.Assert( InOrder( 2, 3, optimalPath ) );
	test_case.Assert( InOrder( 4, 5, optimalPath ) );
	test_case.Assert( InOrder( 5, 3, optimalPath ) );

}
