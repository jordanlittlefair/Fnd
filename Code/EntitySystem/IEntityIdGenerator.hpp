#pragma once

#include "EntityId.hpp"

#include <memory>

namespace Fnd
{

namespace EntitySystem
{

class IEntityIdGenerator
{
public:

	virtual EntityId GenerateId() = 0;

	virtual ~IEntityIdGenerator() {}
};

typedef std::shared_ptr<IEntityIdGenerator> EntityIdGeneratorPtr;

}

}
