#include "MockComponentContainer.hpp"

using namespace Fnd::Test::EntitySystem;
using namespace Fnd::EntitySystem;

MockComponentContainer::MockComponentContainer( const ComponentId component_id ):
	ComponentContainer( component_id )
{
}

void MockComponentContainer::AddComponent( const MockComponent& component )
{
	_map[component.GetEntityId()] = std::make_shared<MockComponent>( component );
}

Fnd::EntitySystem::Component& MockComponentContainer::OnCreateComponent(const Fnd::EntitySystem::EntityId entity_id)
{
	return *(_map[entity_id] = std::make_shared<MockComponent>(GetComponentId(),entity_id));
}

bool MockComponentContainer::OnHasComponent(const Fnd::EntitySystem::EntityId entity_id) const
{
	return _map.find(entity_id) != _map.end();
}

const Component& MockComponentContainer::OnGetComponent( const EntityId entity_id ) const
{
	auto iter = _map.find( entity_id );

	if ( iter != _map.end() )
	{
		return *(iter->second);
	}
	else
	{
		throw std::runtime_error( "Component doesn't exist!" );
	}
}

Component& MockComponentContainer::OnGetComponent( const EntityId entity_id )
{
	auto iter = _map.find( entity_id );

	if ( iter != _map.end() )
	{
		return *(iter->second);
	}
	else
	{
		throw std::runtime_error( "Component doesn't exist!" );
	}
}


void MockComponentContainer::OnDestroyComponent(const Fnd::EntitySystem::EntityId entity_id)
{
	
}