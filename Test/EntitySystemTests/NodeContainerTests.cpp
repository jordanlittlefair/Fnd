#include "NodeContainerTests.hpp"

#include "MockNodeContainer.hpp"

using namespace Fnd::EntitySystem;
using namespace Fnd::Test::EntitySystem;

NodeContainerTests::NodeContainerTests():
	UnitTestClass("NodeContainerTests")
{
	AddTestCase("GetNodeId_Success", &NodeContainerTests::GetNodeId_Success, this);
	AddTestCase("GetNodeNonConst_Success", &NodeContainerTests::GetNodeNonConst_Success, this);
	AddTestCase("GetNodeConst_Success", &NodeContainerTests::GetNodeConst_Success, this);
}

void NodeContainerTests::GetNodeId_Success(Fnd::Test::TestCase& test_case)
{
	MockNodeContainer nc(123);
	
	test_case.Assert(nc.GetNodeId() == 123);
}

void NodeContainerTests::GetNodeNonConst_Success(Fnd::Test::TestCase& test_case)
{
	MockNodeContainer nc(123);
	
	MockNode node(123,999);
	
	nc.AddNode(node);
	
	test_case.Assert(nc.GetNode(999).GetEntityId() == 999);
}

void NodeContainerTests::GetNodeConst_Success(Fnd::Test::TestCase& test_case)
{
	MockNodeContainer nc(123);
	
	MockNode node(123,999);
	
	nc.AddNode(node);
	
	NodeContainer& ncc = nc;
	
	test_case.Assert(ncc.GetNode(999).GetEntityId() == 999);
}
