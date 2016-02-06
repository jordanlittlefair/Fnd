#pragma once

namespace Fnd
{
namespace Core
{
namespace Platform
{

enum class Build
{
	Debug,
	Release,

	Unknown = ~0
};

namespace BuildStrings
{

const char Debug[]		= "Debug";
const char Release[]	= "Release";

const char Unknown[]	= "Unknown";

inline const char* Get( const Build build )
{
	switch ( build )
	{
	case Build::Debug:
		return Debug;
	case Build::Release:
		return Release;
	default:
		return Unknown;
	}
}

}

}
}
}
