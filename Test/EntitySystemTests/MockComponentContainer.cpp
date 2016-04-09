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