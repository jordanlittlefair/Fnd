#include "EntitySystem.hpp"

using namespace Fnd::EntitySystem;

EntitySystem::EntitySystem(EntityIdGeneratorPtr entity_id_generator):
	_entity_id_generator(entity_id_generator),
	_entity_manager(entity_id_generator),
	_component_manager(),
	_node_manager()
{
}

class IEntityManager& EntitySystem::GetEntityManager()
{
	return _entity_manager;
}

const class IEntityManager& EntitySystem::GetEntityManager() const
{
	return _entity_manager;
}

class IComponentManager& EntitySystem::GetComponentManager()
{
	return _component_manager;
}

const class IComponentManager& EntitySystem::GetComponentManager() const
{
	return _component_manager;
}

class INodeManager& EntitySystem::GetNodeManager()
{
	return _node_manager;
}

const class INodeManager& EntitySystem::GetNodeManager() const
{
	return _node_manager;
}
