#pragma once

#include "Component.hpp"

namespace Fnd
{

namespace EntitySystem
{

class ComponentContainer
{
public:

	ComponentId GetComponentId() const;
	
	const Component& GetComponent( const EntityId entity_id ) const;
	Component& GetComponent( const EntityId entity_id );

	virtual ~ComponentContainer();

protected:

	ComponentContainer( const ComponentId component_id );

	virtual const Component& OnGetComponent( const EntityId entity_id ) const = 0;
	virtual Component& OnGetComponent( const EntityId entity_id ) = 0;

private:

	ComponentContainer( const ComponentContainer& ); // = delete;
	ComponentContainer& operator=( const ComponentContainer& ); // = delete;

private:

	const ComponentId _component_id;
};

}

}
