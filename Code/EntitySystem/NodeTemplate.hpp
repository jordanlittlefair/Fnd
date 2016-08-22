#pragma once

#include "AssertNodeType.hpp"
#include "ComponentManager.hpp"
#include "Node.hpp"

#include <string>

namespace Fnd
{

namespace EntitySystem
{

template <typename NodeType>
class NodeTemplate:
	public Node
{
public:

	static_assert(AssertNodeType<NodeType>::IsValid,"NodeType must be valid");
	
	typedef typename NodeType::Components Components;
	typedef typename NodeType::ComponentsConst ComponentsConst;
	
	static std::string GetName()
	{
		return NodeType::Name;
	}

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
