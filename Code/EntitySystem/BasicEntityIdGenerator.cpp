#include "BasicEntityIdGenerator.hpp"

using namespace Fnd::EntitySystem;

BasicEntityIdGenerator::BasicEntityIdGenerator():
	_last_id(0)
{
}

EntityId BasicEntityIdGenerator::GenerateId()
{
	return ++_last_id;
}
