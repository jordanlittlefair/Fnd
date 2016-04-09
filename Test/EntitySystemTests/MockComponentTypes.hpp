#pragma once

#include "../../Code/EntitySystem/ComponentId.hpp"

#include <string>

namespace Fnd
{

namespace Test
{

namespace EntitySystem
{

struct MockComponentType1
{
	static const Fnd::EntitySystem::ComponentId Id;

	struct Data
	{
		int some_int;
		std::string some_string;
	};
};

struct MockComponentType2
{
	static const Fnd::EntitySystem::ComponentId Id;

	struct Data
	{
		std::string some_string;
		int some_int;
	};
};

}

}

}
