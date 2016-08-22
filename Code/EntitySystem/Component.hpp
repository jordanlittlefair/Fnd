#pragma once

#include "ComponentId.hpp"
#include "EntityId.hpp"

namespace Fnd
{

namespace EntitySystem
{

class Component
{
public:

	ComponentId GetComponentId() const;

	EntityId GetEntityId() const;
	
	virtual ~Component();

protected:
	
	Component( const ComponentId component_id, const EntityId entity_id );

private:

	ComponentId _component_id;
	EntityId _entity_id;
};

}

}
