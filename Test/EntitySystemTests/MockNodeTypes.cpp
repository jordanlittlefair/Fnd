#include "MockNodeTypes.hpp"

#include "../../Code/EntitySystem/StaticIdNameMappers.hpp"

using namespace Fnd::Test::EntitySystem;
using namespace Fnd::EntitySystem;


const std::string MockNodeType1::Name = "One";
const std::string MockNodeType2::Name = "Two";

const NodeId MockNodeType1::Id = StaticIdNameMappers::Instance().GetNodeIdNameMapper().GenerateId(MockNodeType1::Name);
const NodeId MockNodeType2::Id = StaticIdNameMappers::Instance().GetNodeIdNameMapper().GenerateId(MockNodeType2::Name);

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
