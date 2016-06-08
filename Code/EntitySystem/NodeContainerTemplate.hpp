#pragma once

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
			throw InvalidEntityIdException();
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
			throw InvalidEntityIdException();
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
			throw InvalidEntityIdException();
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
			throw InvalidEntityIdException();
		}
	}
	
protected:
	
	const Node& OnGetNode(const EntityId entity_id) const
	{
		return GetNode(entity_id);
	}
	
	Node& OnGetNode(const EntityId entity_id)
	{
		return GetNode(entity_id);
	}

private:

	std::map<EntityId,NodeTemplate<NodeType>> _node_map;
};

}

}
