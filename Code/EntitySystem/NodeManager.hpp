#pragma once

#include "NodeContainerTemplate.hpp"
#include "NodeManagerBase.hpp"
#include "Exceptions.hpp"


namespace Fnd
{

namespace EntitySystem
{

class NodeManager:
	public NodeManagerBase
{
public:
	
	NodeManager();
	
	template <typename NodeType>
	bool IsRegistered() const
	{
		return NodeManagerBase::IsRegistered(NodeType::Id);
	}
	
	template <typename NodeType>
	void RegisterNode()
	{
		NodeManagerBase::RegisterNode(std::make_shared<NodeContainerTemplate<NodeType>>());
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
		return (NodeContainerTemplate<NodeType>&)NodeManagerBase::GetNodeContainer(NodeType::Id);
	}
	
	template <typename NodeType>
	const NodeContainerTemplate<NodeType>& GetNodeContainer() const
	{
		return (const NodeContainerTemplate<NodeType>&)NodeManagerBase::GetNodeContainer(NodeType::Id);	}
};

}

}
