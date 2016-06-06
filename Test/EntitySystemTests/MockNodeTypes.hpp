#pragma once

#include "MockComponentTypes.hpp"

#include "../../Code/EntitySystem/ComponentManager.hpp"
#include "../../Code/EntitySystem/ComponentTemplate.hpp"
#include "../../Code/EntitySystem/NodeId.hpp"

#include <string>

namespace Fnd
{

namespace Test
{

namespace EntitySystem
{

struct MockNodeType1
{
	static const Fnd::EntitySystem::NodeId Id;

	struct Components
	{
		Fnd::EntitySystem::ComponentTemplate<MockComponentType1>& component1;
	};
	
	struct ComponentsConst
	{
		const Fnd::EntitySystem::ComponentTemplate<MockComponentType1>& component1;
	};
	
	static Components GetComponents(const Fnd::EntitySystem::EntityId& entity_id, Fnd::EntitySystem::ComponentManager& component_manager);
	
	static ComponentsConst GetComponents(const Fnd::EntitySystem::EntityId& entity_id, const Fnd::EntitySystem::ComponentManager& component_manager);
};

struct MockNodeType2
{
	static const Fnd::EntitySystem::NodeId Id;
	
	struct Components
	{
		Fnd::EntitySystem::ComponentTemplate<MockComponentType1>& component1;
		Fnd::EntitySystem::ComponentTemplate<MockComponentType2>& component2;
	};
	
	struct ComponentsConst
	{
		const Fnd::EntitySystem::ComponentTemplate<MockComponentType1>& component1;
		const Fnd::EntitySystem::ComponentTemplate<MockComponentType2>& component2;
	};
	
	static Components GetComponents(const Fnd::EntitySystem::EntityId& entity_id, Fnd::EntitySystem::ComponentManager& component_manager);
	
	static ComponentsConst GetComponents(const Fnd::EntitySystem::EntityId& entity_id, const Fnd::EntitySystem::ComponentManager& component_manager);
};

}

}

}
