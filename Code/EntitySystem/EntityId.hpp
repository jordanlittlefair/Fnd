#pragma once

#include <type_traits>

namespace Fnd
{

namespace EntitySystem
{

typedef unsigned int EntityId;

static_assert( sizeof(EntityId) == 4, "EntityId must be 32 bit" );
static_assert( std::is_unsigned<EntityId>::value, "EntityId must be unsigned" );

}

}
