#pragma once

#include "NodeId.hpp"

namespace Fnd
{

namespace EntitySystem
{

template <typename NodeType>
class AssertNodeType
{
public:

	// Ideally there'd be some SFINAE to make sure the Id and Data exist (for a nice error message)
	// but Visual Studio 2012 doesn't seem to like that...
	
	static_assert(sizeof(NodeType::Id), "NodeType must define an Id");
	static_assert(sizeof(NodeType::Name), "NodeType must define a Name");

	static_assert( sizeof(typename NodeType::Components), "NodeType must define a Components struct" );

	static_assert( sizeof(typename NodeType::ComponentsConst), "NodeType must define a ComponentsConst struct" );

	static_assert( sizeof(typename NodeType::Components) == sizeof(typename NodeType::ComponentsConst), "Components must be the same size as ComponentsConst" );

	static const bool IsValid = true;
};

}

}
