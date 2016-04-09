#pragma once

#include "Component.hpp"

namespace Fnd
{

namespace EntitySystem
{

template <typename ComponentType>
class ComponentTemplate:
	public Component
{
public:
	
	static_assert( sizeof(typename ComponentType::Data), "ComponentType must define a Data struct" );
	
	typedef typename ComponentType::Data ComponentData;

	ComponentTemplate( const EntityId entity_id ):
		Component( ComponentType::Id, entity_id )
	{
	}

	ComponentTemplate( const EntityId entity_id, const ComponentData& component_data ):
		Component( ComponentType::Id, entity_id ),
		_data(component_data)
	{	
	}

	ComponentData& GetData()
	{
		return _data;
	}

	const ComponentData& GetData() const
	{
		return _data;
	}

	ComponentData& operator*()
	{
		return _data;
	}

	const ComponentData& operator*() const
	{
		return _data;
	}

	ComponentData* operator->()
	{
		return &_data;
	}

	const ComponentData* operator->() const
	{
		return &_data;
	}
	
private:

	ComponentData _data;
};

}

}
