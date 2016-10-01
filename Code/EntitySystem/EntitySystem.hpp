#pragma once

#include "ComponentManager.hpp"
#include "EntityManager.hpp"
#include "IEntitySystem.hpp"
#include "IEntityIdGenerator.hpp"
#include "NodeManager.hpp"

namespace Fnd
{
	
namespace EntitySystem
{

class EntitySystem:
	public IEntitySystem
{
public:
	
	EntitySystem(EntityIdGeneratorPtr entity_id_generator);
	
	class IEntityManager& GetEntityManager();
	
	const class IEntityManager& GetEntityManager() const;
	
	class IComponentManager& GetComponentManager();
	
	const class IComponentManager& GetComponentManager() const;
	
	class INodeManager& GetNodeManager();
	
	const class INodeManager& GetNodeManager() const;
	
private:
	
	EntityIdGeneratorPtr _entity_id_generator;
	
	EntityManager _entity_manager;
	ComponentManager _component_manager;
	NodeManager _node_manager;
};
	
}
	
}
