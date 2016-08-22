#pragma once

#include "../../Code/EntitySystem/IEntityIdGenerator.hpp"

namespace Fnd
{

namespace Test
{

namespace EntitySystem
{

class MockEntityIdGenerator:
	public Fnd::EntitySystem::IEntityIdGenerator
{
public:

	MockEntityIdGenerator();

	Fnd::EntitySystem::EntityId GenerateId();

	void SetNextId(const Fnd::EntitySystem::EntityId& next_id);

private:

	Fnd::EntitySystem::EntityId _next_id;
};

}

}

}
