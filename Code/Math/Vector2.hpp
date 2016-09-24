#pragma once

#include "Utility.hpp"

namespace Fnd
{
	
namespace Math
{

template <typename Number>
struct Vector2
{
	typedef Number NumberType;
	
	Number x;
	Number y;
	
	Vector2()
	{
	}
	
	Vector2(const Number& x_, const Number& y_):
		x(x_),
		y(y_)
	{
	}
	
	static Vector2 Zero()
	{
		return Vector2(0, 0);
	}

	const Number& operator[] (const unsigned int i) const
	{
		assert(i < NumElements);
		return ((Number*)this)[i];
	}

	Number& operator[] (const unsigned int i)
	{
		assert(i < NumElements);
		return ((Number*)this)[i];
	}

	static const unsigned int NumElements = 2;
};
	
typedef Vector2<float> Vector2f;
	
template <typename Number>
Vector2<Number> operator +(const Vector2<Number>& rhs)
{
	return Vector2<Number>(+rhs.x, +rhs.y);
}
	
template <typename Number>
Vector2<Number> operator -(const Vector2<Number>& rhs)
{
	return Vector2<Number>(-rhs.x, -rhs.y);
}
	
template <typename Number>
Vector2<Number> operator +(const Vector2<Number>& lhs, const Vector2<Number>& rhs)
{
	return Vector2<Number>(lhs.x + rhs.x, lhs.y + rhs.y);
}
	
template <typename Number>
Vector2<Number> operator -(const Vector2<Number>& lhs, const Vector2<Number>& rhs)
{
	return Vector2<Number>(lhs.x - rhs.x, lhs.y - rhs.y);
}
	
template <typename Number, typename Scalar>
Vector2<Number> operator *(const Vector2<Number>& lhs, const Scalar& rhs)
{
	return Vector2<Number>(lhs.x * rhs, lhs.y * rhs);
}

template <typename Number, typename Scalar>
Vector2<Number> operator *(const Scalar& lhs, const Vector2<Number>& rhs)
{
	return Vector2<Number>(lhs * rhs.x, lhs * rhs.y);
}

template <typename Number>
Vector2<Number> operator *(const Vector2<Number>& lhs, const Vector2<Number>& rhs)
{
	return Vector2<Number>(lhs.x * rhs.x, lhs.y * rhs.y);
}

template <typename Number, typename Scalar>
Vector2<Number> operator /(const Vector2<Number>& lhs, const Scalar& rhs)
{
	return Vector2<Number>(lhs.x / rhs, lhs.y / rhs);
}
	
template <typename Number>
Vector2<Number> operator /(const Vector2<Number>& lhs, const Vector2<Number>& rhs)
{
	return Vector2<Number>(lhs.x / rhs.x, lhs.y / rhs.y);
}
	
template <typename Number>
Vector2<Number> operator +=(Vector2<Number>& lhs, const Vector2<Number>& rhs)
{
	return lhs = Vector2<Number>(lhs.x + rhs.x, lhs.y + rhs.y);
}
	
template <typename Number>
Vector2<Number> operator -=(Vector2<Number>& lhs, const Vector2<Number>& rhs)
{
	return lhs = Vector2<Number>(lhs.x - rhs.x, lhs.y - rhs.y);
}
	
template <typename Number, typename Scalar>
Vector2<Number> operator *=(Vector2<Number>& lhs, const Scalar& rhs)
{
	return lhs = Vector2<Number>(lhs.x * rhs, lhs.y * rhs);
}
	
template <typename Number>
Vector2<Number> operator *=(Vector2<Number>& lhs, const Vector2<Number>& rhs)
{
	return lhs = Vector2<Number>(lhs.x * rhs.x, lhs.y * rhs.y);
}

template <typename Number, typename Scalar>
Vector2<Number> operator /=(Vector2<Number>& lhs, const Scalar& rhs)
{
	return lhs = Vector2<Number>(lhs.x / rhs, lhs.y / rhs);
}
	
template <typename Number>
Vector2<Number> operator /=(Vector2<Number>& lhs, const Vector2<Number>& rhs)
{
	return lhs = Vector2<Number>(lhs.x / rhs.x, lhs.y / rhs.y);
}
	
template <typename Number>
Number LengthSquared(const Vector2<Number>& vec)
{
	return (vec.x * vec.x) + (vec.y * vec.y);
}

template <typename Number>
Number Length(const Vector2<Number>& vec)
{
	return Utility::Sqrt(LengthSquared(vec));
}

template <typename Number>
Vector2<Number> Normalise(const Vector2<Number>& vec)
{
	return vec / Length(vec);
}
	
template <typename Number>
Number Dot(const Vector2<Number>& vec0, const Vector2<Number>& vec1)
{
	return (vec0.x * vec1.x) + (vec0.y * vec1.y);
}
	
}
	
}
