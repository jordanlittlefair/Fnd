#pragma once

#include "../../Code/EntitySystem/ComponentId.hpp"

#include <string>

namespace Fnd
{

namespace Test
{

namespace EntitySystem
{

struct MockComponentType
{
	static const Fnd::EntitySystem::ComponentId Id;

	struct Data
	{
		int some_int;
		std::string some_string;
	};
};

}

}

}
