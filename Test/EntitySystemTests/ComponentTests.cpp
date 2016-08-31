#include "ComponentTests.hpp"
#include "MockComponent.hpp"

using namespace Fnd::Test::EntitySystem;
using namespace Fnd::EntitySystem;

ComponentTests::ComponentTests():
	UnitTestClass("ComponentTests")
{
	AddTestCase( "CheckIds", &ComponentTests::CheckIds, this );
}

void ComponentTests::CheckIds( Fnd::Test::TestCase& test_case )
{
	const ComponentId component_id = 456;
	const EntityId entity_id = 123;

	std::shared_ptr<Component> component = std::make_shared<MockComponent>( component_id, entity_id );

	test_case.Assert( component->GetComponentId() == component_id );
	test_case.Assert( component->GetEntityId() == entity_id );
}
