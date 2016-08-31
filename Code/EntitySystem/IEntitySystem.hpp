#pragma once

#include "EntityManager.hpp"
#include "ComponentManager.hpp"
#include "NodeManager.hpp"

namespace Fnd
{
namespace EntitySystem
{

class IEntitySystem
{
public:

	virtual class EntityManager& EntityManager() = 0;
	virtual const class EntityManager& EntityManager() const = 0;

	virtual class ComponentManager& ComponentManager() = 0;
	virtual const class ComponentManager& ComponentManager() const = 0;

	virtual class NodeManager& NodeManager() = 0;
	virtual const class NodeManager& NodeManager() const = 0;
};

}
	
}
