#pragma once

#include "../../Code/EntitySystem/Component.hpp"

namespace Fnd
{

namespace Test
{

namespace EntitySystem
{

class MockComponent:
	public Fnd::EntitySystem::Component
{
public:

	MockComponent( const Fnd::EntitySystem::ComponentId component_id, const Fnd::EntitySystem::EntityId entity_id );
};

}

}

}
