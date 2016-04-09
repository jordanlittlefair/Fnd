#include "ComponentContainerTests.hpp"

#include "../../Code/EntitySystem/ComponentContainer.hpp"

#include <map>

using namespace Fnd::Test::EntitySystem;
using namespace Fnd::EntitySystem;

namespace
{

class MockComponent:
	public Component
{
public:

	MockComponent( const ComponentId component_id, const EntityId entity_id ):
		Component( component_id, entity_id )
	{
	}
};

class MockComponentContainer:
	public ComponentContainer
{
public:

	MockComponentContainer( const ComponentId component_id ):
		ComponentContainer( component_id )
	{
	}

	void AddComponent( const MockComponent& component )
	{
		_map[component.GetEntityId()] = std::make_shared<MockComponent>( component );
	}

protected:

	const Component& OnGetComponent( const EntityId entity_id ) const
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

	Component& OnGetComponent( const EntityId entity_id )
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

private:

	std::map<EntityId,std::shared_ptr<MockComponent>> _map;
};

}

ComponentContainerTests::ComponentContainerTests():
	TestClass("ComponentTests")
{
	AddTestCase( "CheckIds", &ComponentContainerTests::CheckComponentId, this );
	
	AddTestCase( "CheckGetComponent", &ComponentContainerTests::CheckGetComponent, this );
}

void ComponentContainerTests::CheckComponentId( Fnd::Test::TestCase& test_case )
{
	const ComponentId component_id = 123;

	MockComponentContainer container( component_id );

	test_case.Assert( component_id == container.GetComponentId() );
}

void ComponentContainerTests::CheckGetComponent( Fnd::Test::TestCase& test_case )
{
	const ComponentId component_id = 123;
	
	MockComponentContainer container( component_id );

	MockComponent component_1( component_id, 1 );
	MockComponent component_2( component_id, 2 );

	container.AddComponent( component_1 );
	container.AddComponent( component_2 );

	test_case.Assert( container.GetComponent( 1 ).GetEntityId() == 1 );
	test_case.Assert( container.GetComponent( 2 ).GetEntityId() == 2 );
}
