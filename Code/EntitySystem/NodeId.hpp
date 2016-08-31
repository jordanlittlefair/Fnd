#pragma once

#include <type_traits>

namespace Fnd
{

namespace EntitySystem
{

typedef unsigned int NodeId;

static_assert( sizeof(NodeId) == 4, "NodeId must be 32 bit" );
static_assert( std::is_unsigned<NodeId>::value, "NodeId must be unsigned" );

}

}
