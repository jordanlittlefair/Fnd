#include "ComponentManagerBase.hpp"

#include "Exceptions.hpp"

#include <cassert>

using namespace Fnd::EntitySystem;

ComponentManagerBase::ComponentManagerBase()
{
}

bool ComponentManagerBase::IsRegistered(const ComponentId component_id) const
{
	const auto iter = _component_containers.find(component_id);
	
	return iter != _component_containers.end();
}

void ComponentManagerBase::RegisterComponent(std::shared_ptr<ComponentContainer> component_container)
{
	assert(component_container);
	
	if (!IsRegistered(component_container->GetComponentId()))
	{
		_component_containers[component_container->GetComponentId()] = component_container;
	}
	else
	{
		throw InvalidComponentIdException(component_container->GetComponentId());
	}
}

Component& ComponentManagerBase::CreateComponent(const ComponentId component_id, const EntityId entity_id)
{
	return GetComponentContainer(component_id).CreateComponent(entity_id);
}

bool ComponentManagerBase::HasComponent(const ComponentId component_id, const EntityId entity_id) const
{
	return GetComponentContainer(component_id).HasComponent(entity_id);
}

Component& ComponentManagerBase::GetComponent(const ComponentId component_id, const EntityId entity_id)
{
	return GetComponentContainer(component_id).GetComponent(entity_id);
}

const Component& ComponentManagerBase::GetComponent(const ComponentId component_id, const EntityId entity_id) const
{
	return GetComponentContainer(component_id).GetComponent(entity_id);
}

void ComponentManagerBase::DestroyComponent(const ComponentId component_id, const EntityId entity_id)
{
	GetComponentContainer(component_id).DestroyComponent(entity_id);
}

ComponentContainer& ComponentManagerBase::GetComponentContainer(const ComponentId component_id)
{
	const auto iter = _component_containers.find(component_id);
	
	if (iter != _component_containers.end())
	{
		return *((iter->second).get());
	}
	else
	{
		throw InvalidComponentIdException(component_id);
	}
}

const ComponentContainer& ComponentManagerBase::GetComponentContainer(const ComponentId component_id) const
{
	const auto iter = _component_containers.find(component_id);
	
	if (iter != _component_containers.end())
	{
		return *((iter->second).get());
	}
	else
	{
		throw InvalidComponentIdException(component_id);
	}
}
