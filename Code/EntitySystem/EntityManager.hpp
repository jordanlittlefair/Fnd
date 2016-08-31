#pragma once

#include "EntityId.hpp"
#include "Exceptions.hpp"
#include "IEntityIdGenerator.hpp"

#include <vector>

namespace Fnd
{

namespace EntitySystem
{

class EntityManager
{
public:

	EntityManager(EntityIdGeneratorPtr entity_id_generator);

	EntityId CreateEntity();

	bool HasEntity(const EntityId& entity_id) const;

	void DestroyEntity(const EntityId& entity_id);
	
private:

	EntityIdGeneratorPtr _entity_id_generator;

	std::vector<EntityId> _entities;
};

}

}
