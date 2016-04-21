#include "CyclicGraphCheckerTests.hpp"

#include "../../Code/SystemManager/CyclicGraphChecker.hpp"

using namespace Fnd::Test::SystemManager;
using namespace Fnd::SystemManager;

CyclicGraphCheckerTests::CyclicGraphCheckerTests():
	TestClass("CyclicGraphCheckerTests")
{
	AddTestCase( "TestConstructor", &CyclicGraphCheckerTests::TestConstructor, this );
	AddTestCase( "TestClearSystemNodes", &CyclicGraphCheckerTests::TestClearSystemNodes, this );
	AddTestCase( "TestIsCyclic_Empty", &CyclicGraphCheckerTests::TestIsCyclic_Empty, this );
	AddTestCase( "TestIsCyclic_SingleNode", &CyclicGraphCheckerTests::TestIsCyclic_SingleNode, this );
	AddTestCase( "TestIsCyclic_MultipleUnlinked", &CyclicGraphCheckerTests::TestIsCyclic_MultipleUnlinked, this );
	AddTestCase( "TestIsCyclic_Chain", &CyclicGraphCheckerTests::TestIsCyclic_Chain, this );
	AddTestCase( "TestIsCyclic_MultipleDependencies", &CyclicGraphCheckerTests::TestIsCyclic_MultipleDependencies, this );
	AddTestCase( "TestIsCyclic_SharedDependency", &CyclicGraphCheckerTests::TestIsCyclic_SharedDependency, this );
	AddTestCase( "TestIsCyclic_SingleCycle", &CyclicGraphCheckerTests::TestIsCyclic_SingleCycle, this );
	AddTestCase( "TestIsCyclic_MultipleCycles", &CyclicGraphCheckerTests::TestIsCyclic_MultipleCycles, this );
	AddTestCase( "TestIsCyclic_ForkAndJoin", &CyclicGraphCheckerTests::TestIsCyclic_ForkAndJoin, this );
}

void CyclicGraphCheckerTests::TestConstructor( TestCase& test_case )
{
/*
	Graph:
		->0->1->
		  <-/
*/
	std::vector<std::shared_ptr<SystemGraphNode>> nodes;
	
	auto node0 = std::make_shared<SystemGraphNode>("0");
	auto node1 = std::make_shared<SystemGraphNode>("1");
	
	node0->AddNext("1");	node1->AddPrev("0");
	node1->AddNext("0");	node0->AddPrev("1");
	
	nodes.push_back(node0);
	nodes.push_back(node1);
	
	CyclicGraphChecker cgc(nodes);
	
	test_case.Assert( cgc.IsCyclic() );
}

void CyclicGraphCheckerTests::TestClearSystemNodes( TestCase& test_case )
{
/*
	Graph:
		->0->1->
		  <-/
*/
	CyclicGraphChecker cgc;
	
	std::vector<std::shared_ptr<SystemGraphNode>> nodes;
	
	auto node0 = std::make_shared<SystemGraphNode>("0");
	auto node1 = std::make_shared<SystemGraphNode>("1");
	
	node0->AddNext("1");	node1->AddPrev("0");
	node1->AddNext("0");	node0->AddPrev("1");
	
	nodes.push_back(node0);
	nodes.push_back(node1);
	
	cgc.UpdateSystemGraphNodes(nodes);
	
	test_case.Assert( cgc.IsCyclic() );
	
	cgc.ClearSystemNodes();
	
	test_case.Assert( !cgc.IsCyclic() );
}

void CyclicGraphCheckerTests::TestIsCyclic_Empty( TestCase& test_case )
{
	CyclicGraphChecker cgc;
	
	test_case.Assert( !cgc.IsCyclic() );
}

void CyclicGraphCheckerTests::TestIsCyclic_SingleNode( TestCase& test_case )
{
/*
	Graph:
		->0->
*/
	CyclicGraphChecker cgc;
	
	std::vector<std::shared_ptr<SystemGraphNode>> nodes;
	
	auto node0 = std::make_shared<SystemGraphNode>("0");
	
	nodes.push_back(node0);
	
	cgc.UpdateSystemGraphNodes(nodes);
	
	test_case.Assert( !cgc.IsCyclic() );
}

void CyclicGraphCheckerTests::TestIsCyclic_MultipleUnlinked( TestCase& test_case )
{
/*
	Graph:
		->0->
		
		->1->
*/
	CyclicGraphChecker cgc;
	
	std::vector<std::shared_ptr<SystemGraphNode>> nodes;
	
	auto node0 = std::make_shared<SystemGraphNode>("0");
	auto node1 = std::make_shared<SystemGraphNode>("1");
	
	nodes.push_back(node0);
	nodes.push_back(node1);
	
	cgc.UpdateSystemGraphNodes(nodes);
	
	test_case.Assert( !cgc.IsCyclic() );
}

void CyclicGraphCheckerTests::TestIsCyclic_Chain( TestCase& test_case )
{
/*
	Graph:
		->0->1->2->
*/
	CyclicGraphChecker cgc;
	
	std::vector<std::shared_ptr<SystemGraphNode>> nodes;
	
	auto node0 = std::make_shared<SystemGraphNode>("0");
	auto node1 = std::make_shared<SystemGraphNode>("1");
	auto node2 = std::make_shared<SystemGraphNode>("2");
	
	node0->AddNext("1");	node1->AddPrev("0");
	node1->AddNext("2");	node2->AddPrev("1");
	
	nodes.push_back(node0);
	nodes.push_back(node1);
	nodes.push_back(node2);
	
	cgc.UpdateSystemGraphNodes(nodes);
	
	test_case.Assert( !cgc.IsCyclic() );
}

void CyclicGraphCheckerTests::TestIsCyclic_MultipleDependencies( TestCase& test_case )
{
/*
	Graph:
		->0->
		->1->2->
*/
	CyclicGraphChecker cgc;
	
	std::vector<std::shared_ptr<SystemGraphNode>> nodes;
	
	auto node0 = std::make_shared<SystemGraphNode>("0");
	auto node1 = std::make_shared<SystemGraphNode>("1");
	auto node2 = std::make_shared<SystemGraphNode>("2");
	
	node0->AddNext("2");	node2->AddPrev("0");
	node1->AddNext("2");	node2->AddPrev("1");
	
	nodes.push_back(node0);
	nodes.push_back(node1);
	nodes.push_back(node2);
	
	cgc.UpdateSystemGraphNodes(nodes);
	
	test_case.Assert( !cgc.IsCyclic() );
}

void CyclicGraphCheckerTests::TestIsCyclic_SharedDependency( TestCase& test_case )
{
/*
	Graph:
		->0->1->
		   ->2->
*/
	CyclicGraphChecker cgc;
	
	std::vector<std::shared_ptr<SystemGraphNode>> nodes;
	
	auto node0 = std::make_shared<SystemGraphNode>("0");
	auto node1 = std::make_shared<SystemGraphNode>("1");
	auto node2 = std::make_shared<SystemGraphNode>("2");
	
	node0->AddNext("1");	node1->AddPrev("0");
	node0->AddNext("2");	node2->AddPrev("0");
	
	nodes.push_back(node0);
	nodes.push_back(node1);
	nodes.push_back(node2);
	
	cgc.UpdateSystemGraphNodes(nodes);
	
	test_case.Assert( !cgc.IsCyclic() );
}

void CyclicGraphCheckerTests::TestIsCyclic_SingleCycle( TestCase& test_case )
{
/*
	Graph:
		->0->1->2->
		   <----/
*/
	CyclicGraphChecker cgc;
	
	std::vector<std::shared_ptr<SystemGraphNode>> nodes;
	
	auto node0 = std::make_shared<SystemGraphNode>("0");
	auto node1 = std::make_shared<SystemGraphNode>("1");
	auto node2 = std::make_shared<SystemGraphNode>("2");
	
	node0->AddNext("1");	node1->AddPrev("0");
	node1->AddNext("2");	node2->AddPrev("1");
	node2->AddNext("0");	node0->AddPrev("2");
	
	nodes.push_back(node0);
	nodes.push_back(node1);
	nodes.push_back(node2);
	
	cgc.UpdateSystemGraphNodes(nodes);
	
	test_case.Assert( cgc.IsCyclic() );
}

void CyclicGraphCheckerTests::TestIsCyclic_MultipleCycles( TestCase& test_case )
{
/*
	Graph:
		->0->1->
		   <-/
 
		->2->3->4->
		   <----/
*/
	CyclicGraphChecker cgc;
	
	std::vector<std::shared_ptr<SystemGraphNode>> nodes;
	
	auto node0 = std::make_shared<SystemGraphNode>("0");
	auto node1 = std::make_shared<SystemGraphNode>("1");
	
	auto node2 = std::make_shared<SystemGraphNode>("2");
	auto node3 = std::make_shared<SystemGraphNode>("3");
	auto node4 = std::make_shared<SystemGraphNode>("4");
	
	node0->AddNext("1");	node1->AddPrev("0");
	node1->AddNext("0");	node0->AddPrev("1");
	
	node2->AddNext("3");	node3->AddPrev("2");
	node3->AddNext("4");	node4->AddPrev("3");
	node4->AddNext("2");	node2->AddPrev("4");
	
	nodes.push_back(node0);
	nodes.push_back(node1);
	nodes.push_back(node2);
	nodes.push_back(node3);
	nodes.push_back(node4);
	
	cgc.UpdateSystemGraphNodes(nodes);
	
	test_case.Assert( cgc.IsCyclic() );
}

void CyclicGraphCheckerTests::TestIsCyclic_ForkAndJoin( TestCase& test_case )
{
	/*
	 Graph:
		->0->1->2->5->
		   \      /
		   ->3->4->
	 */
	CyclicGraphChecker cgc;
	
	std::vector<std::shared_ptr<SystemGraphNode>> nodes;
	
	auto node0 = std::make_shared<SystemGraphNode>("0");
	auto node1 = std::make_shared<SystemGraphNode>("1");
	auto node2 = std::make_shared<SystemGraphNode>("2");
	auto node3 = std::make_shared<SystemGraphNode>("3");
	auto node4 = std::make_shared<SystemGraphNode>("4");
	auto node5 = std::make_shared<SystemGraphNode>("5");
	
	node0->AddNext("1");	node1->AddPrev("0");
	node0->AddNext("3");	node3->AddPrev("0");
	
	node1->AddNext("2");	node2->AddPrev("1");
	
	node2->AddNext("5");	node5->AddPrev("2");
	
	node3->AddNext("4");	node4->AddPrev("3");
	
	node4->AddNext("5");	node5->AddPrev("4");
	
	nodes.push_back(node0);
	nodes.push_back(node1);
	nodes.push_back(node2);
	nodes.push_back(node3);
	nodes.push_back(node4);
	nodes.push_back(node5);
	
	cgc.UpdateSystemGraphNodes(nodes);
	
	test_case.Assert( !cgc.IsCyclic() );
}
