#include "MockComponent.hpp"

using namespace Fnd::Test::EntitySystem;
using namespace Fnd::EntitySystem;

MockComponent::MockComponent( const ComponentId component_id, const EntityId entity_id ):
	Component( component_id, entity_id )
{
}
