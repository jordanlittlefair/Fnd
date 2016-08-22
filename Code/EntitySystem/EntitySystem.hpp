#pragma once

#include "IEntitySystem.hpp"

namespace Fnd
{
	
namespace EntitySystem
{

class EntitySystem:
	public IEntitySystem
{
public:
	
	EntitySystem(EntityIdGeneratorPtr entity_id_generator);
	
	class EntityManager& EntityManager();
	
	const class EntityManager& EntityManager() const;
	
	class ComponentManager& ComponentManager();
	
	const class ComponentManager& ComponentManager() const;
	
	class NodeManager& NodeManager();
	
	const class NodeManager& NodeManager() const;
	
private:
	
	EntityIdGeneratorPtr _entity_id_generator;
	
	class EntityManager _entity_manager;
	class ComponentManager _component_manager;
	class NodeManager _node_manager;
};
	
}
	
}
