#pragma once

#include "Utility.hpp"
#include "Vector3.hpp"

namespace Fnd
{

namespace Math
{

template <typename Number>
struct Quaternion
{
	typedef Number NumberType;
	
	Number x;
	Number y;
	Number z;
	Number w;
	
	Quaternion()
	{
	}
	
	Quaternion(const Number& x_, const Number& y_, const Number& z_, const Number& w_):
		x(x_),
		y(y_),
		z(z_),
		w(w_)
	{
	}
	
	Vector3<Number> GetXAxis() const
	{
		return Vector3<Number>(
			1 - 2 * ( y * y + z * z ),
			2 * ( x * y + w * z ),
			2 * ( x * z - w * y ) );
		
	}
	
	Vector3<Number> GetYAxis() const
	{
		return Vector3<Number>(
			2 * ( x * y - w * z ),
			1 - 2 * ( x * x + z * z ),
			2 * ( y * z + w * x ) );
	}
	
	Vector3<Number> GetZAxis() const
	{
		return Vector3<Number>(
			2 * ( x * z + w * y ),
			2 * ( y * z - w * x ),
			1 - 2 * ( x * x + y * y ) );
	}
};
	
	typedef Quaternion<float> Quaternionf;
	
template <typename Number>
Quaternion<Number> operator *(const Quaternion<Number>& q1, const Quaternion<Number>& q2)
{
	return Quaternion<Number>(
		q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y,
		q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x,
		q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w,
		q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z );
}
	
template <typename Number>
Quaternion<Number> operator *=(Quaternion<Number>& q1, const Quaternion<Number>& q2)
{
	return q1 = (q1 * q2);
}
	
template <typename Number>
Number MagnitudeSquared(const Quaternion<Number>& q)
{
	return (q.x * q.x) + (q.y * q.y) + (q.z * q.z) + (q.w * q.w);
}
	
template <typename Number>
Number Magnitude(const Quaternion<Number>& q)
{
	return Utility::Sqrt(MagnitudeSquared(q));
}
	
template <typename Number>
Quaternion<Number> Normalise(const Quaternion<Number>& q)
{
	const Number magnitude = Magnitude(q);
	
	return Quaternion<Number>(q.x / magnitude, q.y / magnitude, q.z / magnitude, q.w / magnitude);
}
	
}

}
