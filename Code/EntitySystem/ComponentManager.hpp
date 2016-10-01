#pragma once

#include "ComponentContainerTemplate.hpp"
#include "ComponentManagerBase.hpp"
#include "Exceptions.hpp"

#include <memory>

namespace Fnd
{

namespace EntitySystem
{

class ComponentManager:
	public ComponentManagerBase
{
public:

	ComponentManager();

	template <typename ComponentType>
	bool IsRegistered() const
	{
		return ComponentManagerBase::IsRegistered(ComponentType::Id);
	}

	template <typename ComponentType>
	void RegisterComponent()
	{
		ComponentManagerBase::RegisterComponent(std::make_shared<ComponentContainerTemplate<ComponentType>>());
	}

	template <typename ComponentType>
	ComponentTemplate<ComponentType>& CreateComponent( const EntityId entity_id )
	{
		return GetComponentContainer<ComponentType>().CreateComponent( entity_id );
	}

	template <typename ComponentType>
	ComponentTemplate<ComponentType>& CreateComponent( const EntityId entity_id, const typename ComponentType::Data& component_data )
	{
		return GetComponentContainer<ComponentType>().CreateComponent( entity_id, component_data );
	}

	template <typename ComponentType>
	bool HasComponent( const EntityId entity_id )
	{
		return GetComponentContainer<ComponentType>().HasComponent( entity_id );
	}

	template <typename ComponentType>
	ComponentTemplate<ComponentType>& GetComponent( const EntityId entity_id )
	{
		return GetComponentContainer<ComponentType>().GetComponent( entity_id );
	}

	template <typename ComponentType>
	const ComponentTemplate<ComponentType>&	GetComponent( const EntityId entity_id ) const
	{
		return GetComponentContainer<ComponentType>().GetComponent( entity_id );
	}

	template <typename ComponentType>
	void DestroyComponent( const EntityId entity_id )
	{
		GetComponentContainer<ComponentType>().DestroyComponent( entity_id );
	}

private:

	template <typename ComponentType>
	ComponentContainerTemplate<ComponentType>& GetComponentContainer()
	{
		return (ComponentContainerTemplate<ComponentType>&)ComponentManagerBase::GetComponentContainer(ComponentType::Id);
	}

	template <typename ComponentType>
	const ComponentContainerTemplate<ComponentType>& GetComponentContainer() const
	{
		return (ComponentContainerTemplate<ComponentType>&)ComponentManagerBase::GetComponentContainer(ComponentType::Id);
	}
};

}

}