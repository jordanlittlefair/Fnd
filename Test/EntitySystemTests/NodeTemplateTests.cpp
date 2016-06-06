#include "NodeTemplateTests.hpp"

#include "../../Code/EntitySystem/NodeTemplate.hpp"

#include "MockNodeTypes.hpp"

using namespace Fnd::EntitySystem;
using namespace Fnd::Test::EntitySystem;

NodeTemplateTests::NodeTemplateTests():
	TestClass("NodeTemplateTests")
{
	AddTestCase( "GetNodeId_Success", &NodeTemplateTests::GetNodeId_Success, this );
	AddTestCase( "GetEntityId_Success", &NodeTemplateTests::GetEntityId_Success, this );
}

void NodeTemplateTests::GetNodeId_Success( Fnd::Test::TestCase& test_case )
{
	NodeTemplate<MockNodeType1> node(123);
	
	test_case.Assert(node.GetNodeId() == MockNodeType1::Id);
}

void NodeTemplateTests::GetEntityId_Success( Fnd::Test::TestCase& test_case )
{
	NodeTemplate<MockNodeType1> node(123);
	
	test_case.Assert(node.GetEntityId() == 123);
}
