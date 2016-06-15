#pragma once

#include "NodeContainerTemplate.hpp"
#include "Exceptions.hpp"


namespace Fnd
{

namespace EntitySystem
{

class NodeManager
{
public:
	
	NodeManager();
	
	template <typename NodeType>
	bool IsRegistered() const
	{
		const auto iter = _node_containers.find(NodeType::Id);
	
		return iter != _node_containers.end();
	}
	
	template <typename NodeType>
	void RegisterNode()
	{
		if ( !IsRegistered<NodeType>() )
		{
			_node_containers[NodeType::Id] = std::make_shared<NodeContainerTemplate<NodeType>>();
		}
		else
		{
			throw InvalidNodeIdException(NodeType::Id);
		}
	}
	
	template <typename NodeType>
	NodeTemplate<NodeType>& CreateNode(const EntityId entity_id)
	{
		return GetNodeContainer<NodeType>().CreateNode(entity_id);
	}
	
	template <typename NodeType>
	bool HasNode(const EntityId entity_id)
	{
		return GetNodeContainer<NodeType>().HasNode(entity_id);
	}
	
	template <typename NodeType>
	const NodeTemplate<NodeType>& GetNode(const EntityId entity_id) const
	{
		return GetNodeContainer<NodeType>().GetNode(entity_id);
	}
	
	template <typename NodeType>
	NodeTemplate<NodeType>& GetNode(const EntityId entity_id)
	{
		return GetNodeContainer<NodeType>().GetNode(entity_id);
	}
	
	template <typename NodeType,typename Lambda> // void Lambda(const NodeTemplate<NodeType>& node)
	void ForEachNode(Lambda lambda) const
	{
		GetNodeContainer<NodeType>().ForEachNode(lambda);
	}
	
	template <typename NodeType,typename Lambda> // void Lambda(NodeTemplate<NodeType>& node)
	void ForEachNode(Lambda lambda)
	{
		GetNodeContainer<NodeType>().ForEachNode(lambda);
	}
	
	template <typename NodeType>
	void DestroyNode(const EntityId entity_id)
	{
		GetNodeContainer<NodeType>().DestroyNode(entity_id);
	}
	
private:
	
	template <typename NodeType>
	NodeContainerTemplate<NodeType>& GetNodeContainer()
	{
		const auto iter = _node_containers.find(NodeType::Id);
	
		if (iter != _node_containers.end())
		{
			return *(NodeContainerTemplate<NodeType>*)((iter->second).get());
		}
		else
		{
			throw InvalidNodeIdException(NodeType::Id);
		}
	}
	
	template <typename NodeType>
	const NodeContainerTemplate<NodeType>& GetNodeContainer() const
	{
		const auto iter = _node_containers.find(NodeType::Id);
	
		if ( iter != _node_containers.end() )
		{
			return *(NodeContainerTemplate<NodeType>*)((iter->second).get());
		}
		else
		{
			throw InvalidNodeIdException(NodeType::Id);
		}
	}
	
private:
	
	std::map<NodeId,std::shared_ptr<NodeContainer>> _node_containers;
};

}

}
