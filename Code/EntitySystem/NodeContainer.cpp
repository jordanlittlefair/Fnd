#include "NodeContainer.hpp"

using namespace Fnd::EntitySystem;


NodeContainer::NodeContainer(const NodeId node_id):
	_node_id(node_id)
{
}

NodeId NodeContainer::GetNodeId() const
{
	return _node_id;
}

const Node& NodeContainer::GetNode(const EntityId entity_id) const
{
	return OnGetNode(entity_id);
}

Node& NodeContainer::GetNode(const EntityId entity_id)
{
	return OnGetNode(entity_id);
}

NodeContainer::~NodeContainer()
{
}
