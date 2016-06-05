#include "EntityManager.hpp"

#include <algorithm>
#include <cassert>

using namespace Fnd::EntitySystem;

EntityManager::EntityManager(EntityIdGeneratorPtr entity_id_generator):
	_entity_id_generator(entity_id_generator)
{
	assert(_entity_id_generator);
}

EntityId EntityManager::CreateEntity()
{
	EntityId entity_id = _entity_id_generator->GenerateId();

	_entities.push_back(entity_id);

	return entity_id;
}

bool EntityManager::HasEntity(const EntityId& entity_id) const
{
	auto iter = std::find( _entities.begin(), _entities.end(), entity_id );

	return iter != _entities.end();
}

void EntityManager::DestroyEntity(const EntityId& entity_id)
{
	if (HasEntity(entity_id))
	{
		_entities.erase(std::remove(_entities.begin(),_entities.end(), entity_id ), _entities.end());
	}
	else
	{
		throw InvalidEntityIdException();
	}
}
