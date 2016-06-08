#pragma once

#include "ComponentManager.hpp"
#include "Node.hpp"

namespace Fnd
{

namespace EntitySystem
{

template <typename NodeType>
class NodeTemplate:
	public Node
{
public:

	static_assert( sizeof(typename NodeType::Components), "NodeType must define a Components struct" );
	static_assert( sizeof(typename NodeType::ComponentsConst), "NodeType must define a ComponentsConst struct" );
	static_assert( sizeof(typename NodeType::Components) == sizeof(typename NodeType::ComponentsConst), "Components must be the same size as ComponentsConst" );
	
	typedef typename NodeType::Components Components;
	typedef typename NodeType::ComponentsConst ComponentsConst;

	NodeTemplate ( const EntityId entity_id ):
		Node( NodeType::Id, entity_id )
	{
	}
	
	Components GetComponents(Fnd::EntitySystem::ComponentManager& component_manager) const
	{
		return NodeType::GetComponents(GetEntityId(), component_manager);
	}
	
	ComponentsConst GetComponents(const Fnd::EntitySystem::ComponentManager& component_manager) const
	{
		return NodeType::GetComponents(GetEntityId(), component_manager);
	}
};

}

}
