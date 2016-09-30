#pragma once

#include "AssertNodeType.hpp"
#include "NodeContainer.hpp"
#include "NodeTemplate.hpp"
#include "Exceptions.hpp"

#include <map>
#include <utility>

namespace Fnd
{

namespace EntitySystem
{

template <typename NodeTypeT>
class NodeContainerTemplate:
	public NodeContainer
{
public:

	static_assert(AssertNodeType<NodeTypeT>::IsValid,"NodeType must be valid");

	typedef NodeTypeT NodeType;

	NodeContainerTemplate():
		NodeContainer(NodeType::Id)
	{
	}

	NodeTemplate<NodeType>& CreateNode(const EntityId entity_id)
	{
		auto iter = _node_map.find(entity_id);

		if (iter == _node_map.end())
		{
			auto inserted = _node_map.insert(std::pair<EntityId,NodeTemplate<NodeType>>(entity_id, NodeTemplate<NodeType>(entity_id)));
		
			return inserted.first->second;
		}
		else
		{
			throw InvalidEntityIdException(entity_id);
		}
	}

	bool HasNode(const EntityId entity_id) const
	{
		const auto iter = _node_map.find(entity_id);

		return iter != _node_map.end();
	}

	const NodeTemplate<NodeType>& GetNode(const EntityId entity_id) const
	{
		const auto iter = _node_map.find(entity_id);

		if (iter != _node_map.end())
		{
			return iter->second;
		}
		else
		{
			throw InvalidEntityIdException(entity_id);
		}
	}
	
	NodeTemplate<NodeType>& GetNode(const EntityId entity_id)
	{
		const auto iter = _node_map.find(entity_id);
	
		if (iter != _node_map.end())
		{
			return iter->second;
		}
		else
		{
			throw InvalidEntityIdException(entity_id);
		}
	}
	
	template <typename Lambda> // void Lambda(const NodeTemplate<NodeType>& node)
	void ForEachNode(Lambda lambda) const
	{
		for (const auto& node : _node_map)
		{
			lambda(node.second);
		}
	}
	
	template <typename Lambda> // void Lambda(NodeTemplate<NodeType>& node)
	void ForEachNode(Lambda lambda)
	{
		for (auto& node : _node_map)
		{
			lambda(node.second);
		}
	}

	void DestroyNode(const EntityId entity_id)
	{
		const auto iter = _node_map.find( entity_id );

		if ( iter != _node_map.end() )
		{
			_node_map.erase( iter );
		}
		else
		{
			throw InvalidEntityIdException(entity_id);
		}
	}
	
protected:
	
	Node& OnCreateNode(const EntityId entity_id)
	{
		return OnCreateNode(entity_id);
	}
	
	bool OnHasNode(const EntityId entity_id) const
	{
		return HasNode(entity_id);
	}
	
	const Node& OnGetNode(const EntityId entity_id) const
	{
		return GetNode(entity_id);
	}
	
	Node& OnGetNode(const EntityId entity_id)
	{
		return GetNode(entity_id);
	}
	
	void OnDestroyNode(const EntityId entity_id)
	{
		return DestroyNode(entity_id);
	}

private:

	std::map<EntityId,NodeTemplate<NodeType>> _node_map;
};

}

}
