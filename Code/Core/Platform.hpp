#pragma once

#include "OS.hpp"
#include "Bit.hpp"
#include "Build.hpp"

#include "PlatformDefinitions.hpp"

namespace Fnd
{
namespace Core
{
namespace Platform
{

namespace Current
{

const Fnd::Core::Platform::OS		OS		= FND_PLATFORM_CURRENT_OS;
const Fnd::Core::Platform::Bit		Bit		= FND_PLATFORM_CURRENT_BIT;
const Fnd::Core::Platform::Build	Build	= FND_PLATFORM_CURRENT_BUILD;

const char*	OSString	= OSStrings::Get(Current::OS);
const char*	BitString	= BitStrings::Get(Current::Bit);
const char*	BuildString	= BuildStrings::Get(Current::Build);

};

}
}
}

static_assert( Fnd::Core::Platform::Current::OS != Fnd::Core::Platform::OS::Unknown,		"Platform::OS cannot be Unknown!" );
static_assert( Fnd::Core::Platform::Current::Bit != Fnd::Core::Platform::Bit::Unknown,		"Platform::Bit cannot be Unknown!" );
static_assert( Fnd::Core::Platform::Current::Build != Fnd::Core::Platform::Build::Unknown,	"Platform::Build cannot be Unknown!" );

