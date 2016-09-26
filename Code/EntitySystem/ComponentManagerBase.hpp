#pragma once

#include "ComponentContainerTemplate.hpp"
#include "Exceptions.hpp"

#include <memory>

namespace Fnd
{

namespace EntitySystem
{

class ComponentManagerBase
{
public:
	
	bool IsRegistered(const ComponentId componentId) const;
	
	void RegisterComponent(std::shared_ptr<ComponentContainer> component_container);
	
	Component& CreateComponent(const ComponentId component_id, const EntityId entity_id);
	
	bool HasComponent(const ComponentId component_id, const EntityId entity_id) const;
	
	Component& GetComponent(const ComponentId component_id, const EntityId entity_id);
	
	const Component& GetComponent(const ComponentId component_id, const EntityId entity_id) const;
	
	void DestroyComponent(const ComponentId component_id, const EntityId entity_id);
	
protected:
	
	ComponentManagerBase();
	
	ComponentContainer& GetComponentContainer(const ComponentId component_id);
	
	const ComponentContainer& GetComponentContainer(const ComponentId component_id) const;
	
private:
	
	std::map<ComponentId,std::shared_ptr<ComponentContainer>> _component_containers;
};

}

}