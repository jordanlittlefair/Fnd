#pragma once

#include "../Core/Exception.hpp"

#include "ComponentId.hpp"
#include "EntityId.hpp"
#include "NodeId.hpp"

namespace Fnd
{

namespace EntitySystem
{

class Exception:
	public Fnd::Core::Exception
{
protected:
	
	Exception( const std::string& what );
};

class InvalidComponentIdException:
	public Fnd::EntitySystem::Exception
{
public:
	
	InvalidComponentIdException();
	
	InvalidComponentIdException(const ComponentId invalid_component_id);
};

class InvalidEntityIdException:
	public Fnd::EntitySystem::Exception
{
public:
	
	InvalidEntityIdException();
	
	InvalidEntityIdException(const EntityId invalid_entity_id);
};
	
class InvalidNodeIdException:
	public Fnd::EntitySystem::Exception
{
public:
	
	InvalidNodeIdException();
	
	InvalidNodeIdException(const NodeId invalid_node_id);
};

}

}