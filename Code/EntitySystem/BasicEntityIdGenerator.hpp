#pragma once

#include "IEntityIdGenerator.hpp"

namespace Fnd
{

namespace EntitySystem
{

class BasicEntityIdGenerator:
	public IEntityIdGenerator
{
public:

	BasicEntityIdGenerator();

	EntityId GenerateId();

private:

	EntityId _last_id;
};

}

}
