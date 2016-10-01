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

Node& NodeContainer::CreateNode(const EntityId entity_id)
{
	return OnCreateNode(entity_id);
}

bool NodeContainer::HasNode(const EntityId entity_id) const
{
	return OnHasNode(entity_id);
}

const Node& NodeContainer::GetNode(const EntityId entity_id) const
{
	return OnGetNode(entity_id);
}

Node& NodeContainer::GetNode(const EntityId entity_id)
{
	return OnGetNode(entity_id);
}

void NodeContainer::DestroyNode(const EntityId entity_id)
{
	OnDestroyNode(entity_id);
}

NodeContainer::~NodeContainer()
{
}
