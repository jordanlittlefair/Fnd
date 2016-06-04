#pragma once

#include "ComponentContainerTemplate.hpp"
#include "Exceptions.hpp"

#include <memory>

namespace Fnd
{

namespace EntitySystem
{

class ComponentManager
{
public:

	ComponentManager();

	template <typename ComponentType>
	bool IsRegistered() const
	{
		const auto iter = _component_containers.find( ComponentType::Id );

		return iter != _component_containers.end();
	}

	template <typename ComponentType>
	void RegisterComponent()
	{
		if ( !IsRegistered<ComponentType>() )
		{
			_component_containers[ComponentType::Id] = std::make_shared<ComponentContainerTemplate<ComponentType>>();
		}
		else
		{
			throw InvalidComponentIdException();
		}
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
		const auto iter = _component_containers.find( ComponentType::Id );

		if ( iter != _component_containers.end() )
		{
			return *(ComponentContainerTemplate<ComponentType>*)((iter->second).get());
		}
		else
		{
			throw InvalidComponentIdException();
		}
	}

	template <typename ComponentType>
	const ComponentContainerTemplate<ComponentType>& GetComponentContainer() const
	{
		const auto iter = _component_containers.find( ComponentType::Id );
		
		if ( iter != _component_containers.end() )
		{
			return *(ComponentContainerTemplate<ComponentType>*)((iter->second).get());
		}
		else
		{
			throw InvalidComponentIdException();
		}
	}

	std::map<ComponentId,std::shared_ptr<ComponentContainer>> _component_containers;
};

}

}