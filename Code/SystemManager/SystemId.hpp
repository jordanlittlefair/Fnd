#pragma once

#include <type_traits>

namespace Fnd
{
	
namespace SystemManager
{

typedef unsigned int SystemId;

static_assert( sizeof(SystemId) == 4, "SystemId must be 32 bit" );
static_assert( std::is_unsigned<SystemId>::value, "SystemId must be unsigned" );

}
	
}