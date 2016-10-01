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
	
	Component& CreateComponent(const EntityId entity_id);
	bool HasComponent(const EntityId entity_id) const;
	const Component& GetComponent( const EntityId entity_id ) const;
	Component& GetComponent( const EntityId entity_id );
	void DestroyComponent(const EntityId entity_id);

	virtual ~ComponentContainer();

protected:

	ComponentContainer( const ComponentId component_id );

	virtual Component& OnCreateComponent(const EntityId entity_id) = 0;
	virtual bool OnHasComponent(const EntityId entity_id) const = 0;
	virtual const Component& OnGetComponent( const EntityId entity_id ) const = 0;
	virtual Component& OnGetComponent( const EntityId entity_id ) = 0;
	virtual void OnDestroyComponent(const EntityId entity_id) = 0;

private:

	ComponentContainer( const ComponentContainer& ); // = delete;
	ComponentContainer& operator=( const ComponentContainer& ); // = delete;

private:

	const ComponentId _component_id;
};

}

}
