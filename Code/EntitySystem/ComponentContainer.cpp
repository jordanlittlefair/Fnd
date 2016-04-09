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

const Component& ComponentContainer::GetComponent( const EntityId entity_id ) const
{
	return OnGetComponent( entity_id );
}

Component& ComponentContainer::GetComponent( const EntityId entity_id )
{
	return OnGetComponent( entity_id );
}

ComponentContainer::~ComponentContainer()
{
}