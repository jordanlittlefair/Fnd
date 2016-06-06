#pragma once

#include "MockComponentTypes.hpp"

#include "../../Code/EntitySystem/NodeId.hpp"

#include <string>

namespace Fnd
{

namespace Test
{

namespace EntitySystem
{

struct MockNodeType1
{
	static const Fnd::EntitySystem::NodeId Id;

	struct Components
	{
		MockComponentType1& component1;
	};
};

struct MockNodeType2
{
	static const Fnd::EntitySystem::NodeId Id;
	
	struct Components
	{
		MockComponentType1& component1;
		MockComponentType2& component2;
	};
};

}

}

}
