#pragma once

#include "EntityId.hpp"
#include "NodeContainer.hpp"
#include "NodeId.hpp"

#include <memory>

namespace Fnd
{

namespace EntitySystem
{

class INodeManager
{
public:
	
	virtual bool IsRegistered(const NodeId node_id) const = 0;
	
	virtual void RegisterNode(std::shared_ptr<NodeContainer> node_container) = 0;
	
	virtual Node& CreateNode(const NodeId node_id, const EntityId entity_id) = 0;
	
	virtual bool HasNode(const NodeId node_id, const EntityId entity_id) const = 0;
	
	virtual const Node& GetNode(const NodeId node_id, const EntityId entity_id) const = 0;
	
	virtual Node& GetNode(const NodeId node_id, const EntityId entity_id) = 0;
	
	virtual void DestroyNode(const NodeId node_id, const EntityId entity_id) = 0;
	
	virtual ~INodeManager() {}
};

}

}
