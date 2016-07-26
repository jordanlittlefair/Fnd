#pragma once

#include "AssertComponentType.hpp"
#include "ComponentContainer.hpp"
#include "ComponentTemplate.hpp"
#include "Exceptions.hpp"

#include <map>
#include <utility>

namespace Fnd
{

namespace EntitySystem
{

template <typename ComponentTypeT>
class ComponentContainerTemplate:
	public ComponentContainer
{
public:

	static_assert(AssertComponentType<ComponentTypeT>::IsValid, "ComponentType must be valid");

	typedef ComponentTypeT ComponentType;

	ComponentContainerTemplate():
		ComponentContainer(ComponentType::Id)
	{
	}

	ComponentTemplate<ComponentType>& CreateComponent( const EntityId entity_id )
	{
		auto iter = _component_map.find( entity_id );
		
		if ( iter == _component_map.end() )
		{
			auto inserted = _component_map.insert( std::pair<EntityId,ComponentTemplate<ComponentType>>( entity_id, ComponentTemplate<ComponentType>( entity_id ) ) );
			
			return inserted.first->second;
		}
		else
		{
			throw InvalidEntityIdException(entity_id);
		}
	}

	ComponentTemplate<ComponentType>& CreateComponent( const EntityId entity_id, const typename ComponentType::Data& component_data )
	{
		auto iter = _component_map.find( entity_id );
		
		if ( iter == _component_map.end() )
		{
			auto inserted = _component_map.insert( std::make_pair( entity_id, ComponentTemplate<ComponentType>( entity_id, component_data ) ) );
			
			return inserted.first->second;
		}
		else
		{
			throw InvalidEntityIdException(entity_id);
		}
	}

	bool HasComponent( const EntityId entity_id ) const
	{
		const auto iter = _component_map.find( entity_id );

		return iter != _component_map.end();
	}

	const ComponentTemplate<ComponentType>& GetComponent( const EntityId entity_id ) const
	{
		const auto iter = _component_map.find( entity_id );

		if ( iter != _component_map.end() )
		{
			return iter->second;
		}
		else
		{
			throw InvalidEntityIdException(entity_id);
		}
	}

	ComponentTemplate<ComponentType>& GetComponent( const EntityId entity_id )
	{
		const auto iter = _component_map.find( entity_id );

		if ( iter != _component_map.end() )
		{
			return iter->second;
		}
		else
		{
			throw InvalidEntityIdException(entity_id);
		}
	}

	void DestroyComponent( const EntityId entity_id )
	{
		const auto iter = _component_map.find( entity_id );

		if ( iter != _component_map.end() )
		{
			_component_map.erase( iter );
		}
		else
		{
			throw InvalidEntityIdException(entity_id);
		}
	}

protected:

	const Component& OnGetComponent( const EntityId entity_id ) const
	{
		return GetComponent( entity_id );
	}
	
	Component& OnGetComponent( const EntityId entity_id )
	{
		return GetComponent( entity_id );
	}

private:

	std::map<EntityId,ComponentTemplate<ComponentType>> _component_map;
};

}

}
