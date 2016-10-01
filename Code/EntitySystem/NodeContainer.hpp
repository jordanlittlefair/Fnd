#pragma once

#include "Node.hpp"

namespace Fnd
{

namespace EntitySystem
{

class NodeContainer
{
public:

	NodeId GetNodeId() const;

	Node& CreateNode(const EntityId entity_id);
	bool HasNode(const EntityId entity_id) const;
	const Node& GetNode(const EntityId entity_id) const;
	Node& GetNode(const EntityId entity_id);
	void DestroyNode(const EntityId entity_id);
	
	virtual ~NodeContainer();

protected:

	NodeContainer(const NodeId node_id);

	virtual Node& OnCreateNode(const EntityId entity_id) = 0;
	virtual bool OnHasNode(const EntityId entity_id) const = 0;
	virtual const Node& OnGetNode(const EntityId entity_id) const = 0;
	virtual Node& OnGetNode(const EntityId entity_id) = 0;
	virtual void OnDestroyNode(const EntityId entity_id) = 0;

private:

	NodeContainer(const NodeContainer&); // = delete;
	NodeContainer& operator=(const NodeContainer&); // = delete;

private:

	const NodeId _node_id;
};

}

}
