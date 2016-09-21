#pragma once

#include "Constants.hpp"

#include <cmath>

namespace Fnd
{

namespace Math
{

namespace Utility
{

template <typename Number>
Number Sqrt(const Number& num)
{
	return sqrt(num);
}
	
template <typename Number>
Number ToRadians(const Number& degrees)
{
	return degrees * (Constants::Tau<Number>() / 360);
}
	
template <typename Number>
Number ToDegrees(const Number& radians)
{
	return radians * (360 / Constants::Tau<Number>());
}

template <typename Number>
Number Abs(const Number& num)
{
	return num < 0 ? -num : num;
}
	
template <typename Number>
Number Min(const Number& num0, const Number& num1)
{
	return num0 < num1 ? num0 : num1;
}
	
template <typename Number>
Number Max(const Number& num0, const Number& num1)
{
	return num0 > num1 ? num0 : num1;
}
	
template <typename Number>
Number Clamp(const Number& num, const Number& min, const Number& max)
{
	return Min(max, Max(min, num));
}

template <typename Value, typename Parameter>
Value Lerp(const Value& valueAtZero, const Value& valueAtOne, const Parameter& s)
{
	return valueAtZero + ((valueAtOne - valueAtZero) * s);
}
	
}

}

}
