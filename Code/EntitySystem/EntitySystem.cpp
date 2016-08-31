#include "EntitySystem.hpp"

using namespace Fnd::EntitySystem;

EntitySystem::EntitySystem(EntityIdGeneratorPtr entity_id_generator):
	_entity_id_generator(entity_id_generator),
	_entity_manager(entity_id_generator),
	_component_manager(),
	_node_manager()
{
}

class EntityManager& EntitySystem::EntityManager()
{
	return _entity_manager;
}

const class EntityManager& EntitySystem::EntityManager() const
{
	return _entity_manager;
}

class ComponentManager& EntitySystem::ComponentManager()
{
	return _component_manager;
}

const class ComponentManager& EntitySystem::ComponentManager() const
{
	return _component_manager;
}

class NodeManager& EntitySystem::NodeManager()
{
	return _node_manager;
}

const class NodeManager& EntitySystem::NodeManager() const
{
	return _node_manager;
}
