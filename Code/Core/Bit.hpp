#pragma once

namespace Fnd
{
namespace Core
{
namespace Platform
{

enum class Bit
{
	B32,
	B64,

	Unknown = ~0
};

namespace BitStrings
{

const char B32[]		= "32 bit";
const char B64[]		= "64 bit";

const char Unknown[]	= "Unknown";

inline const char* Get( const Bit bit )
{
	switch ( bit )
	{
	case Bit::B32:
		return B32;
	case Bit::B64:
		return B64;
	default:
		return Unknown;
	}
}

}

}
}
}
