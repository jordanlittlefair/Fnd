#pragma once

namespace Fnd
{
namespace Core
{
namespace Platform
{

enum class OS
{
	Windows,
	Mac,

	Unknown = ~0
};

namespace OSStrings
{

const char Windows[]	= "Windows";
const char Mac[]		= "Mac";

const char Unknown[]	= "Unknown";

inline const char* Get( const OS os )
{
	switch ( os )
	{
	case OS::Windows:
		return Windows;
	case OS::Mac:
		return Mac;
	default:
		return Unknown;
	}
}

}

}
}
}
