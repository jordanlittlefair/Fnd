#pragma once

#include "OS.hpp"
#include "Bit.hpp"
#include "Build.hpp"

/*
	Defines the current OS 32/64 bit and debug/release builds.
*/

/*
	OS definitions
*/

#ifdef _WIN32
	#define FND_PLATFORM_CURRENT_OS (Fnd::Core::Platform::OS::Windows)
#elif defined __APPLE__
	#define FND_PLATFORM_CURRENT_OS (Fnd::Core::Platform::OS::Mac)
#endif

#ifndef FND_PLATFORM_CURRENT_OS
	#define FND_PLATFORM_CURRENT_OS (Fnd::Core::Platform::OS::Unknown)
#endif

/*
	Bit definitions
*/

#ifdef _WIN32
	#ifdef _WIN32
		#define FND_PLATFORM_CURRENT_BIT (Fnd::Core::Platform::Bit::B32)
	#elif defined _WIN64
		#define FND_PLATFORM_CURRENT_BIT (Fnd::Core::Platform::Bit::B64)
	#endif
#elif defined __APPLE__
	#define FND_PLATFORM_CURRENT_BIT (Fnd::Core::Platform::Bit::B64)
#endif

#ifndef FND_PLATFORM_CURRENT_BIT
#define FND_PLATFORM_CURRENT_BIT (Fnd::Core::Platform::Bit::Unknown)
#endif

/*
	Build definitions
*/

#ifdef _DEBUG
#define FND_PLATFORM_CURRENT_BUILD (Fnd::Core::Platform::Build::Debug)
#else
#define FND_PLATFORM_CURRENT_BUILD (Fnd::Core::Platform::Build::Release)
#endif


#ifndef FND_PLATFORM_CURRENT_BUILD
#define FND_PLATFORM_CURRENT_BUILD (Fnd::Core::Platform::Build::Unknown)
#endif
