#include "NodeManagerBase.hpp"

#include "Exceptions.hpp"

#include <cassert>

using namespace Fnd::EntitySystem;

NodeManagerBase::NodeManagerBase()
{
	
}

bool NodeManagerBase::IsRegistered(const NodeId node_id) const
{
	return _node_containers.find(node_id) != _node_containers.end();
}

void NodeManagerBase::RegisterNode(std::shared_ptr<NodeContainer> node_container)
{
	assert(node_container);
	
	if (!IsRegistered(node_container->GetNodeId()))
	{
		_node_containers[node_container->GetNodeId()] = node_container;
	}
	else
	{
		throw InvalidNodeIdException(node_container->GetNodeId());
	}
}

Node& NodeManagerBase::CreateNode(const NodeId node_id, const EntityId entity_id)
{
	return GetNodeContainer(node_id).CreateNode(entity_id);
}

bool NodeManagerBase::HasNode(const NodeId node_id, const EntityId entity_id) const
{
	return GetNodeContainer(node_id).HasNode(entity_id);
}

const Node& NodeManagerBase::GetNode(const NodeId node_id, const EntityId entity_id) const
{
	return GetNodeContainer(node_id).GetNode(entity_id);
}

Node& NodeManagerBase::GetNode(const NodeId node_id, const EntityId entity_id)
{
	return GetNodeContainer(node_id).GetNode(entity_id);
}

void NodeManagerBase::DestroyNode(const NodeId node_id, const EntityId entity_id)
{
	GetNodeContainer(node_id).DestroyNode(entity_id);
}

NodeContainer& NodeManagerBase::GetNodeContainer(const NodeId node_id)
{
	const auto iter = _node_containers.find(node_id);
	
	if (iter != _node_containers.end())
	{
		return *((iter->second).get());
	}
	else
	{
		throw InvalidNodeIdException(node_id);
	}
}

const NodeContainer& NodeManagerBase::GetNodeContainer(const NodeId node_id) const
{
	const auto iter = _node_containers.find(node_id);
	
	if (iter != _node_containers.end())
	{
		return *((iter->second).get());
	}
	else
	{
		throw InvalidNodeIdException(node_id);
	}
}
