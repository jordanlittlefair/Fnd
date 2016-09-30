#include "ComponentContainer.hpp"

using namespace Fnd::EntitySystem;

ComponentContainer::ComponentContainer( const ComponentId component_id ):
	_component_id(component_id)
{
}

ComponentId ComponentContainer::GetComponentId() const
{
	return _component_id;
}

Component& ComponentContainer::CreateComponent(const EntityId entity_id)
{
	return OnCreateComponent(entity_id);
}

bool ComponentContainer::HasComponent(const EntityId entity_id) const
{
	return OnHasComponent(entity_id);
}

const Component& ComponentContainer::GetComponent( const EntityId entity_id ) const
{
	return OnGetComponent( entity_id );
}

Component& ComponentContainer::GetComponent( const EntityId entity_id )
{
	return OnGetComponent( entity_id );
}

void ComponentContainer::DestroyComponent(const EntityId entity_id)
{
	OnDestroyComponent(entity_id);
}

ComponentContainer::~ComponentContainer()
{
}