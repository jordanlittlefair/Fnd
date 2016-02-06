#pragma once

#include <type_traits>

namespace Fnd
{
namespace Core
{
namespace Types
{

typedef void				Void;

typedef bool				Bool;

typedef unsigned char		IntU8;
typedef signed char			IntS8;

typedef unsigned short		IntU16;
typedef signed short		IntS16;

typedef unsigned int		IntU32;
typedef signed int			IntS32;

typedef unsigned long long	IntU64;
typedef signed long long	IntS64;

typedef float				Float32;
typedef double				Float64;

}
}
}

static_assert( std::is_void<Fnd::Core::Types::Void>::value,			"Void must be void!" );

static_assert( sizeof(Fnd::Core::Types::Bool) == 1,					"Bool must be 8 bits!" );

static_assert( sizeof(Fnd::Core::Types::IntU8) == 1,				"IntU8 must be 8 bits!" );
static_assert( std::is_unsigned<Fnd::Core::Types::IntU8>::value,	"IntU8 must be unsigned!" );

static_assert( sizeof(Fnd::Core::Types::IntS8) == 1,				"IntS8 must be 8 bits!" );
static_assert( std::is_signed<Fnd::Core::Types::IntS8>::value,		"IntS8 must be signed!" );

static_assert( sizeof(Fnd::Core::Types::IntU16) == 2,				"IntU16 must be 16 bits!" );
static_assert( std::is_unsigned<Fnd::Core::Types::IntU16>::value,	"IntU16 must be unsigned!" );
	
static_assert( sizeof(Fnd::Core::Types::IntS16) == 2,				"IntS16 must be 16 bits!" );
static_assert( std::is_signed<Fnd::Core::Types::IntS16>::value,		"IntS16 must be signed!" );

static_assert( sizeof(Fnd::Core::Types::IntU32) == 4,				"IntU32 must be 32 bits!" );
static_assert( std::is_unsigned<Fnd::Core::Types::IntU8>::value,	"IntU32 must be unsigned!" );

static_assert( sizeof(Fnd::Core::Types::IntS32) == 4,				"IntS32 must be 32 bits!" );
static_assert( std::is_signed<Fnd::Core::Types::IntS32>::value,		"IntS32 must be signed!" );

static_assert( sizeof(Fnd::Core::Types::IntU64) == 8,				"IntU64 must be 64 bits!" );
static_assert( std::is_unsigned<Fnd::Core::Types::IntU64>::value,	"IntU64 must be unsigned!" );

static_assert( sizeof(Fnd::Core::Types::IntS64) == 8,				"IntS64 must be 64 bits!" );
static_assert( std::is_signed<Fnd::Core::Types::IntS64>::value,		"IntS64 must be signed!" );