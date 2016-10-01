#pragma once

namespace Fnd
{

namespace Math
{

namespace Constants
{

template <typename Number>
static Number Pi()
{
	return (Number)3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170;
}

template <typename Number>
static Number Tau()
{
	return (Number)6.2831853071795864769252867665590057683943387987502116419498891846156328125724179972560696506842341;
}

template <typename Number>
static Number e()
{
	return (Number)2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664;
}

template <typename Number>
static Number Zero()
{
	return (Number)0;
}

template <typename Number>
static Number One()
{
	return (Number)1;
}

}

}

}
