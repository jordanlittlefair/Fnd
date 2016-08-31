#include "MockNode.hpp"

using namespace Fnd::Test::EntitySystem;
using namespace Fnd::EntitySystem;

MockNode::MockNode(const NodeId node_id, const EntityId entity_id):
	Node(node_id, entity_id)
{
}
