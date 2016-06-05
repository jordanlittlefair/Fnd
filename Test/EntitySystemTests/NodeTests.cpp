#include "NodeTests.hpp"

#include "MockNode.hpp"

using namespace Fnd::EntitySystem;
using namespace Fnd::Test::EntitySystem;

NodeTests::NodeTests():
	TestClass("NodeTests")
{
	AddTestCase( "GetNodeId_Success", &NodeTests::GetNodeId_Success, this );
	AddTestCase( "GetEntityId_Success", &NodeTests::GetEntityId_Success, this );
}

void NodeTests::GetNodeId_Success( Fnd::Test::TestCase& test_case )
{
	std::shared_ptr<Node> node = std::make_shared<MockNode>( 123, 456 );

	test_case.Assert( node->GetNodeId() == 123 );
}

void NodeTests::GetEntityId_Success( Fnd::Test::TestCase& test_case )
{
	std::shared_ptr<Node> node = std::make_shared<MockNode>( 123, 456 );

	test_case.Assert( node->GetEntityId() == 456 );
}
