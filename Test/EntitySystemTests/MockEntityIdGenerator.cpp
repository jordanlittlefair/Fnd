#include "MockEntityIdGenerator.hpp"

using namespace Fnd::EntitySystem;
using namespace Fnd::Test::EntitySystem;

MockEntityIdGenerator::MockEntityIdGenerator():
	_next_id(0)
{
}

Fnd::EntitySystem::EntityId MockEntityIdGenerator::GenerateId()
{
	return _next_id;
}

void MockEntityIdGenerator::SetNextId(const Fnd::EntitySystem::EntityId& next_id)
{
	_next_id = next_id;
}
