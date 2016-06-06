#pragma once

#include "MockComponentTypes.hpp"

#include "../../Code/EntitySystem/ComponentTemplate.hpp"
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
		Fnd::EntitySystem::ComponentTemplate<MockComponentType1>& component1;
	};
};

struct MockNodeType2
{
	static const Fnd::EntitySystem::NodeId Id;
	
	struct Components
	{
		Fnd::EntitySystem::ComponentTemplate<MockComponentType1>& component1;
		Fnd::EntitySystem::ComponentTemplate<MockComponentType2>& component2;
	};
};

}

}

}
