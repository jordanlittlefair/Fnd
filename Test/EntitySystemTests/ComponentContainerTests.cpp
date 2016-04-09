#include "ComponentContainerTests.hpp"

#include "MockComponent.hpp"
#include "MockComponentContainer.hpp"

#include "../../Code/EntitySystem/ComponentContainer.hpp"

#include <map>

using namespace Fnd::Test::EntitySystem;
using namespace Fnd::EntitySystem;

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
