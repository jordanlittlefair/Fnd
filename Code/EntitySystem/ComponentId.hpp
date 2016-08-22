#pragma once

#include <type_traits>

namespace Fnd
{
	
namespace EntitySystem
{

typedef unsigned int ComponentId;

static_assert( sizeof(ComponentId) == 4, "ComponentId must be 32 bit" );
static_assert( std::is_unsigned<ComponentId>::value, "ComponentId must be unsigned" );

}

}
