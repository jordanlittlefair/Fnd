#pragma once

#include "NodeId.hpp"
#include "EntityId.hpp"

namespace Fnd
{

namespace EntitySystem
{

class Node
{
public:

	NodeId GetNodeId() const;

	EntityId GetEntityId() const;
	
	virtual ~Node();

protected:
	
	Node( const NodeId node_id, const EntityId entity_id );

private:

	NodeId _node_id;
	EntityId _entity_id;
};

}

}
