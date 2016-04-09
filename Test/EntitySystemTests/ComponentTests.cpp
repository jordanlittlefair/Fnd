#include "ComponentTests.hpp"

#include "../../Code/EntitySystem/Component.hpp"

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

}

ComponentTests::ComponentTests():
	TestClass("ComponentTests")
{
	AddTestCase( "CheckComponentId", &ComponentTests::CheckComponentId, this );
	AddTestCase( "CheckEntityId", &ComponentTests::CheckEntityId, this );
}

void ComponentTests::CheckComponentId( Fnd::Test::TestCase& test_case )
{
	std::shared_ptr<Component> component = std::make_shared<MockComponent>( 123, 456 );

	test_case.Assert( component->GetComponentId() == 123 );
}

void ComponentTests::CheckEntityId( Fnd::Test::TestCase& test_case )
{
	std::shared_ptr<Component> component = std::make_shared<MockComponent>( 123, 456 );

	test_case.Assert( component->GetEntityId() == 456 );
}
