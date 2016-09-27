#pragma once

#include "NodeContainer.hpp"

#include <map>
#include <memory>

namespace Fnd
{

namespace EntitySystem
{

class NodeManagerBase
{
public:
	
	bool IsRegistered(const NodeId node_id) const;
	
	void RegisterNode(std::shared_ptr<NodeContainer> node_container);
	
	Node& CreateNode(const NodeId node_id, const EntityId entity_id);
	
	bool HasNode(const NodeId node_id, const EntityId entity_id);
	
	const Node& GetNode(const NodeId node_id, const EntityId entity_id) const;
	
	Node& GetNode(const NodeId node_id, const EntityId entity_id);
	
	void DestroyNode(const NodeId node_id, const EntityId entity_id);
	
protected:
	
	NodeManagerBase();
	
	NodeContainer& GetNodeContainer(const NodeId node_id);
	
	const NodeContainer& GetNodeContainer(const NodeId node_id) const;
	
private:
	
	std::map<NodeId,std::shared_ptr<NodeContainer>> _node_containers;
};

}

}
