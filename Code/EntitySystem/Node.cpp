#include "Node.hpp"

using namespace Fnd::EntitySystem;

NodeId Node::GetNodeId() const
{
	return _node_id;
}

EntityId Node::GetEntityId() const
{
	return _entity_id;
}
	
Node::~Node()
{
}
	
Node::Node( const NodeId node_id, const EntityId entity_id ):
	_node_id(node_id),
	_entity_id(entity_id)
{
}
