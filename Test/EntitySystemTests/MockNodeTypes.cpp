#include "MockNodeTypes.hpp"

using namespace Fnd::Test::EntitySystem;
using namespace Fnd::EntitySystem;

const NodeId MockNodeType1::Id = 1;
const NodeId MockNodeType2::Id = 2;

/* static */
auto MockNodeType1::GetComponents(const Fnd::EntitySystem::EntityId& entity_id, Fnd::EntitySystem::ComponentManager& component_manager) -> Components
{
	Components components =
	{
		component_manager.GetComponent<MockComponentType1>(entity_id)
	};
	
	return components;
}

/* static */
auto MockNodeType1::GetComponents(const Fnd::EntitySystem::EntityId& entity_id, const Fnd::EntitySystem::ComponentManager& component_manager) -> ComponentsConst
{
	ComponentsConst components =
	{
		component_manager.GetComponent<MockComponentType1>(entity_id)
	};
	
	return components;
}

/* static */
auto MockNodeType2::GetComponents(const Fnd::EntitySystem::EntityId& entity_id, Fnd::EntitySystem::ComponentManager& component_manager) -> Components
{
	Components components =
	{
		component_manager.GetComponent<MockComponentType1>(entity_id),
		component_manager.GetComponent<MockComponentType2>(entity_id)
	};
	
	return components;
}

/* static */
auto MockNodeType2::GetComponents(const Fnd::EntitySystem::EntityId& entity_id, const Fnd::EntitySystem::ComponentManager& component_manager) -> ComponentsConst
{
	ComponentsConst components =
	{
		component_manager.GetComponent<MockComponentType1>(entity_id),
		component_manager.GetComponent<MockComponentType2>(entity_id)
	};
	
	return components;
}
