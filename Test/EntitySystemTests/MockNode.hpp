#pragma once

#include "../../Code/EntitySystem/Node.hpp"

namespace Fnd
{

namespace Test
{

namespace EntitySystem
{

class MockNode:
	public Fnd::EntitySystem::Node
{
public:

	MockNode(const Fnd::EntitySystem::NodeId node_id, const Fnd::EntitySystem::EntityId entity_id);
};

}

}

}
