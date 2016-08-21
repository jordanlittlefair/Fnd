#pragma once

#include "ComponentId.hpp"

namespace Fnd
{

namespace EntitySystem
{

template <typename ComponentType>
class AssertComponentType
{
public:

	// Ideally there'd be some SFINAE to make sure the Id and Data exist (for a nice error message)
	// but Visual Studio 2012 doesn't seem to like that...

	static_assert(sizeof(ComponentType), "ComponentType must define an Id");

	static_assert(sizeof(ComponentType::Id), "ComponentType must define an Id");
	static_assert(sizeof(ComponentType::Name), "ComponentType must define a Name");

	static const bool IsValid = true;
};

}

}
