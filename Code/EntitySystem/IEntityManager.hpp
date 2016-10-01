#pragma once

#include "EntityId.hpp"

#include <memory>
#include <vector>

namespace Fnd
{

namespace EntitySystem
{

class IEntityManager
{
public:
	
	virtual EntityId CreateEntity() = 0;
	
	virtual bool HasEntity(const EntityId& entity_id) const = 0;
	
	virtual void DestroyEntity(const EntityId& entity_id) = 0;
	
	virtual ~IEntityManager() {}
};
	
typedef std::shared_ptr<IEntityManager> EntityManagerPtr;

}

}
