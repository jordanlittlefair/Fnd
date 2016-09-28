#pragma once

#include "Vector3.hpp"

namespace Fnd
{
	
namespace Math
{

template <typename Number>
struct Matrix3
{
	Number m00;
	Number m01;
	Number m02;
	
	Number m10;
	Number m11;
	Number m12;
	
	Number m20;
	Number m21;
	Number m22;
	
	Matrix3()
	{
	}
	
	Matrix3(const Number m00_, const Number m01_, const Number m02_,
			const Number m10_, const Number m11_, const Number m12_,
			const Number m20_, const Number m21_, const Number m22_ ):
		m00(m00_), m01(m01_), m02(m02_),
		m10(m10_), m11(m11_), m12(m12_),
		m20(m20_), m21(m21_), m22(m22_)
	{
	}
	
	static Matrix3 Identity()
	{
		return Matrix3(1, 0, 0,
					   0, 1, 0,
					   0, 0, 1);
	}
};
	
typedef Matrix3<float> Matrix3f;
	
template <typename Number>
Matrix3<Number> operator *( const Matrix3<Number>& m1, const Matrix3<Number>& m2 )
{
	return Matrix3<Number>(
		m1.m00 * m2.m00 + m1.m01 * m2.m10 + m1.m02 * m2.m20,
		m1.m00 * m2.m01 + m1.m01 * m2.m11 + m1.m02 * m2.m21,
		m1.m00 * m2.m02 + m1.m01 * m2.m12 + m1.m02 * m2.m22,
		m1.m10 * m2.m00 + m1.m11 * m2.m10 + m1.m12 * m2.m20,
		m1.m10 * m2.m01 + m1.m11 * m2.m11 + m1.m12 * m2.m21,
		m1.m10 * m2.m02 + m1.m11 * m2.m12 + m1.m12 * m2.m22,
		m1.m20 * m2.m00 + m1.m21 * m2.m10 + m1.m22 * m2.m20,
		m1.m20 * m2.m01 + m1.m21 * m2.m11 + m1.m22 * m2.m21,
		m1.m20 * m2.m02 + m1.m21 * m2.m12 + m1.m22 * m2.m22);
}

template <typename Number>
Vector3<Number> operator *( const Vector3<Number>& v, const Matrix3<Number>& m )
{
	return Vector3<Number>(
		v.x * m.m00 + v.y * m.m10 + v.z * m.m20,
		v.x * m.m01 + v.y * m.m11 + v.z * m.m21,
		v.x * m.m02 + v.y * m.m12 + v.z * m.m22);
}

	
template <typename Number>
Vector3<Number> operator *( const Matrix3<Number>& m, const Vector3<Number>& v )
{
	return Vector3<Number>(
		v.x * m.m00 + v.y * m.m01 + v.z * m.m02,
		v.x * m.m10 + v.y * m.m11 + v.z * m.m12,
		v.x * m.m20 + v.y * m.m21 + v.z * m.m22);
}
	
template <typename Number>
Matrix3<Number> Transpose( const Matrix3<Number>& m )
{
	return Matrix3<Number>(
		m.m00, m.m10, m.m20,
		m.m01, m.m11, m.m21,
		m.m02, m.m12, m.m22);
}

template <typename Number>
Matrix3<Number> Inverse( const Matrix3<Number>& m )
{
	Matrix3<Number> to_return(
		m.m11 * m.m22 - m.m12 * m.m21,
		m.m02 * m.m21 - m.m01 * m.m22,
		m.m01 * m.m12 - m.m02 * m.m11,

		m.m12 * m.m20 - m.m10 * m.m22,
		m.m00 * m.m22 - m.m02 * m.m20,
		m.m02 * m.m10 - m.m00 * m.m12,

		m.m10 * m.m21 - m.m11 * m.m20,
		m.m01 * m.m20 - m.m00 * m.m21,
		m.m00 * m.m11 - m.m01 * m.m10);
	
	const Number determinant =
		to_return.m00 * m.m00 +
		to_return.m10 * m.m01 +
		to_return.m20 * m.m02;
	
	for (unsigned int i = 0; i < 9; ++i)
	{
		((Number*)&to_return)[i] /= determinant;
	}
	
	return to_return;
}
	
}
	
}
