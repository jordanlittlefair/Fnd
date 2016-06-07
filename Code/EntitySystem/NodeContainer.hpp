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

	const Node& GetNode(const EntityId entity_id) const;
	Node& GetNode(const EntityId entity_id);

	virtual ~NodeContainer();

protected:

	NodeContainer(const NodeId node_id);

	virtual const Node& OnGetNode(const EntityId entity_id) const = 0;
	virtual Node& OnGetNode(const EntityId entity_id) = 0;

private:

	NodeContainer(const NodeContainer&); // = delete;
	NodeContainer& operator=(const NodeContainer&); // = delete;

private:

	const NodeId _node_id;
};

}

}
