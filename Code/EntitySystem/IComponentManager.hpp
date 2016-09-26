#pragma once

#include "Component.hpp"
#include "ComponentContainer.hpp"
#include "ComponentId.hpp"
#include "EntityId.hpp"

#include <memory>

namespace Fnd
{

namespace EntitySystem
{

class IComponentManager
{
public:
	
	virtual bool IsRegistered(const ComponentId componentId) const = 0;
	
	virtual void RegisterComponent(std::shared_ptr<ComponentContainer> component_container) = 0;
	
	virtual Component& CreateComponent(const ComponentId component_id, const EntityId entity_id) = 0;
	
	virtual bool HasComponent(const ComponentId component_id, const EntityId entity_id) const = 0;
	
	virtual Component& GetComponent(const ComponentId component_id, const EntityId entity_id) = 0;
	
	virtual const Component& GetComponent(const ComponentId component_id, const EntityId entity_id) const = 0;
	
	virtual void DestroyComponent(const ComponentId component_id, const EntityId entity_id) = 0;
	
	virtual ~IComponentManager() {}
};

}

}
