#pragma once

#include "Utility.hpp"

namespace Fnd
{

namespace Math
{

template <typename Number>
struct Vector3
{
	typedef Number NumberType;
		
	Number x;
	Number y;
	Number z;
	
	Vector3()
	{
	}
	
	Vector3(const Number& x_, const Number& y_, const Number& z_):
		x(x_),
		y(y_),
		z(z_)
	{
	}
	
	static Vector3 Zero()
	{
		return Vector3(0, 0, 0);
	}
};
	
typedef Vector3<float> Vector3f;

template <typename Number>
Vector3<Number> operator +(const Vector3<Number>& rhs)
{
	return Vector3<Number>(+rhs.x, +rhs.y, +rhs.z);
}

template <typename Number>
Vector3<Number> operator -(const Vector3<Number>& rhs)
{
	return Vector3<Number>(-rhs.x, -rhs.y, -rhs.z);
}

template <typename Number>
Vector3<Number> operator +(const Vector3<Number>& lhs, const Vector3<Number>& rhs)
{
	return Vector3<Number>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

template <typename Number>
Vector3<Number> operator -(const Vector3<Number>& lhs, const Vector3<Number>& rhs)
{
	return Vector3<Number>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

template <typename Number, typename Scalar>
Vector3<Number> operator *(const Vector3<Number>& lhs, const Scalar& rhs)
{
	return Vector3<Number>(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
}

template <typename Number, typename Scalar>
Vector3<Number> operator *(const Scalar& lhs, const Vector3<Number>& rhs)
{
	return Vector3<Number>(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
}

template <typename Number>
Vector3<Number> operator *(const Vector3<Number>& lhs, const Vector3<Number>& rhs)
{
	return Vector3<Number>(lhs.x * rhs.x, lhs.x * rhs.y, lhs.z * rhs.z);
}

template <typename Number, typename Scalar>
Vector3<Number> operator /(const Vector3<Number>& lhs, const Scalar& rhs)
{
	return Vector3<Number>(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
}

template <typename Number>
Vector3<Number> operator /(const Vector3<Number>& lhs, const Vector3<Number>& rhs)
{
	return Vector3<Number>(lhs.x / rhs.x, lhs.x / rhs.y, lhs.z / rhs.z);
}

template <typename Number>
Vector3<Number> operator +=(Vector3<Number>& lhs, const Vector3<Number>& rhs)
{
	return lhs = Vector3<Number>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

template <typename Number>
Vector3<Number> operator -=(Vector3<Number>& lhs, const Vector3<Number>& rhs)
{
	return lhs = Vector3<Number>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

template <typename Number, typename Scalar>
Vector3<Number> operator *=(Vector3<Number>& lhs, const Scalar& rhs)
{
	return lhs = Vector3<Number>(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
}

template <typename Number>
Vector3<Number> operator *=(Vector3<Number>& lhs, const Vector3<Number>& rhs)
{
	return lhs = Vector3<Number>(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
}

template <typename Number, typename Scalar>
Vector3<Number> operator /=(Vector3<Number>& lhs, const Scalar& rhs)
{
	return lhs = Vector3<Number>(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
}

template <typename Number>
Vector3<Number> operator /=(Vector3<Number>& lhs, const Vector3<Number>& rhs)
{
	return lhs = Vector3<Number>(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z);
}
	
template <typename Number>
Number LengthSquared(const Vector3<Number>& vec)
{
	return (vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z);
}

template <typename Number>
Number Length(const Vector3<Number>& vec)
{
	return Utility::Sqrt(LengthSquared(vec));
}

template <typename Number>
Vector3<Number> Normalise(const Vector3<Number>& vec)
{
	return vec / Length(vec);
}

template <typename Number>
Number Dot(const Vector3<Number>& vec0, const Vector3<Number>& vec1)
{
	return (vec0.x * vec1.x) + (vec0.y * vec1.y) + (vec0.z * vec1.z);
}

}

}
