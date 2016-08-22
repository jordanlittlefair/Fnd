#include "Component.hpp"

using namespace Fnd::EntitySystem;

Component::Component( const ComponentId component_id, const EntityId entity_id ):
	_component_id(component_id),
	_entity_id(entity_id)
{
}

ComponentId Component::GetComponentId() const
{
	return _component_id;
}

EntityId Component::GetEntityId() const
{
	return _entity_id;
}

Component::~Component()
{
}
