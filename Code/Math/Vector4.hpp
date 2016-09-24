#pragma once

#include "Utility.hpp"

#include <cassert>

namespace Fnd
{

namespace Math
{

template <typename Number>
struct Vector4
{
	typedef Number NumberType;
	
	Number x;
	Number y;
	Number z;
	Number w;
	
	Vector4()
	{
	}
	
	Vector4(const Number& x_, const Number& y_, const Number& z_, const Number& w_):
		x(x_),
		y(y_),
		z(z_),
		w(w_)
	{
	}
	
	static Vector4 Zero()
	{
		return Vector4(0, 0, 0, 0);
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

	static const unsigned int NumElements = 4;
};

typedef Vector4<float> Vector4f;

template <typename Number>
Vector4<Number> operator +(const Vector4<Number>& rhs)
{
	return Vector4<Number>(+rhs.x, +rhs.y, +rhs.z);
}

template <typename Number>
Vector4<Number> operator -(const Vector4<Number>& rhs)
{
	return Vector4<Number>(-rhs.x, -rhs.y, -rhs.z, -rhs.w);
}

template <typename Number>
Vector4<Number> operator +(const Vector4<Number>& lhs, const Vector4<Number>& rhs)
{
	return Vector4<Number>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
}

template <typename Number>
Vector4<Number> operator -(const Vector4<Number>& lhs, const Vector4<Number>& rhs)
{
	return Vector4<Number>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
}

template <typename Number, typename Scalar>
Vector4<Number> operator *(const Vector4<Number>& lhs, const Scalar& rhs)
{
	return Vector4<Number>(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs);
}

template <typename Number, typename Scalar>
Vector4<Number> operator *(const Scalar& lhs, const Vector4<Number>& rhs)
{
	return Vector4<Number>(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w);
}

template <typename Number>
Vector4<Number> operator *(const Vector4<Number>& lhs, const Vector4<Number>& rhs)
{
	return Vector4<Number>(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w);
}

template <typename Number, typename Scalar>
Vector4<Number> operator /(const Vector4<Number>& lhs, const Scalar& rhs)
{
	return Vector4<Number>(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs);
}

template <typename Number>
Vector4<Number> operator /(const Vector4<Number>& lhs, const Vector4<Number>& rhs)
{
	return Vector4<Number>(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w);
}

template <typename Number>
Vector4<Number> operator +=(Vector4<Number>& lhs, const Vector4<Number>& rhs)
{
	return lhs = Vector4<Number>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
}

template <typename Number>
Vector4<Number> operator -=(Vector4<Number>& lhs, const Vector4<Number>& rhs)
{
	return lhs = Vector4<Number>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
}

template <typename Number, typename Scalar>
Vector4<Number> operator *=(Vector4<Number>& lhs, const Scalar& rhs)
{
	return lhs = Vector4<Number>(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs);
}

template <typename Number>
Vector4<Number> operator *=(Vector4<Number>& lhs, const Vector4<Number>& rhs)
{
	return lhs = Vector4<Number>(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w);
}

template <typename Number, typename Scalar>
Vector4<Number> operator /=(Vector4<Number>& lhs, const Scalar& rhs)
{
	return lhs = Vector4<Number>(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs);
}

template <typename Number>
Vector4<Number> operator /=(Vector4<Number>& lhs, const Vector4<Number>& rhs)
{
	return lhs = Vector4<Number>(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w);
}

template <typename Number>
Number LengthSquared(const Vector4<Number>& vec)
{
	return (vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z) + (vec.w * vec.w);
}

template <typename Number>
Number Length(const Vector4<Number>& vec)
{
	return Utility::Sqrt(LengthSquared(vec));
}

template <typename Number>
Vector4<Number> Normalise(const Vector4<Number>& vec)
{
	return vec / Length(vec);
}

template <typename Number>
Number Dot(const Vector4<Number>& vec0, const Vector4<Number>& vec1)
{
	return (vec0.x * vec1.x) + (vec0.y * vec1.y) + (vec0.z * vec1.z) + (vec0.w * vec1.w);
}

}

}
