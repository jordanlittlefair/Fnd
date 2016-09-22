#pragma once

#include "Vector4.hpp"

namespace Fnd
{

namespace Math
{

template <typename Number>
struct Matrix4
{
	Number m00;
	Number m01;
	Number m02;
	Number m03;
	
	Number m10;
	Number m11;
	Number m12;
	Number m13;
	
	Number m20;
	Number m21;
	Number m22;
	Number m23;
	
	Number m30;
	Number m31;
	Number m32;
	Number m33;
	
	Matrix4()
	{
	}
	
	Matrix4(const Number m00_, const Number m01_, const Number m02_, const Number m03_,
			const Number m10_, const Number m11_, const Number m12_, const Number m13_,
			const Number m20_, const Number m21_, const Number m22_, const Number m23_,
			const Number m30_, const Number m31_, const Number m32_, const Number m33_):
		m00(m00_),
		m01(m01_),
		m02(m02_),
		m03(m03_),
		m10(m10_),
		m11(m11_),
		m12(m12_),
		m13(m13_),
		m20(m20_),
		m21(m21_),
		m22(m22_),
		m23(m23_),
		m30(m30_),
		m31(m31_),
		m32(m32_),
		m33(m33_)
	{
	}
	
	static Matrix4 Identity()
	{
		return Matrix4(1, 0, 0, 0,
					   0, 1, 0, 0,
					   0, 0, 1, 0,
					   0, 0, 0, 1);
	}
};
	
typedef Matrix4<float> Matrix4f;
	
template <typename Number>
Matrix4<Number> operator *(const Matrix4<Number>& m1, const Matrix4<Number>& m2)
{
	return Matrix4<Number>(
		m1.m00 * m2.m00 + m1.m01 * m2.m10 + m1.m02 * m2.m20 + m1.m03 * m2.m30,
		m1.m00 * m2.m01 + m1.m01 * m2.m11 + m1.m02 * m2.m21 + m1.m03 * m2.m31,
		m1.m00 * m2.m02 + m1.m01 * m2.m12 + m1.m02 * m2.m22 + m1.m03 * m2.m32,
		m1.m00 * m2.m03 + m1.m01 * m2.m13 + m1.m02 * m2.m23 + m1.m03 * m2.m33,
		m1.m10 * m2.m00 + m1.m11 * m2.m10 + m1.m12 * m2.m20 + m1.m13 * m2.m30,
		m1.m10 * m2.m01 + m1.m11 * m2.m11 + m1.m12 * m2.m21 + m1.m13 * m2.m31,
		m1.m10 * m2.m02 + m1.m11 * m2.m12 + m1.m12 * m2.m22 + m1.m13 * m2.m32,
		m1.m10 * m2.m03 + m1.m11 * m2.m13 + m1.m12 * m2.m23 + m1.m13 * m2.m33,
		m1.m20 * m2.m00 + m1.m21 * m2.m10 + m1.m22 * m2.m20 + m1.m23 * m2.m30,
		m1.m20 * m2.m01 + m1.m21 * m2.m11 + m1.m22 * m2.m21 + m1.m23 * m2.m31,
		m1.m20 * m2.m02 + m1.m21 * m2.m12 + m1.m22 * m2.m22 + m1.m23 * m2.m32,
		m1.m20 * m2.m03 + m1.m21 * m2.m13 + m1.m22 * m2.m23 + m1.m23 * m2.m33,
		m1.m30 * m2.m00 + m1.m31 * m2.m10 + m1.m32 * m2.m20 + m1.m33 * m2.m30,
		m1.m30 * m2.m01 + m1.m31 * m2.m11 + m1.m32 * m2.m21 + m1.m33 * m2.m31,
		m1.m30 * m2.m02 + m1.m31 * m2.m12 + m1.m32 * m2.m22 + m1.m33 * m2.m32,
		m1.m30 * m2.m03 + m1.m31 * m2.m13 + m1.m32 * m2.m23 + m1.m33 * m2.m33);
}

template <typename Number>
Vector4<Number> operator *(const Vector4<Number>& v, const Matrix4<Number>& m)
{
	return Vector4<Number>(
		v.x * m.m00 + v.y * m.m10 + v.z * m.m20 + v.w * m.m30,
		v.x * m.m01 + v.y * m.m11 + v.z * m.m21 + v.w * m.m31,
		v.x * m.m02 + v.y * m.m12 + v.z * m.m22 + v.w * m.m32,
		v.x * m.m03 + v.y * m.m13 + v.z * m.m23 + v.w * m.m33);
}

template <typename Number>
Vector4<Number> operator *(const Matrix4<Number>& m, const Vector4<Number>& v)
{
	return Vector4<Number>(
		v.x * m.m00 + v.y * m.m01 + v.z * m.m02 + v.w * m.m03,
		v.x * m.m10 + v.y * m.m11 + v.z * m.m12 + v.w * m.m13,
		v.x * m.m20 + v.y * m.m21 + v.z * m.m22 + v.w * m.m23,
		v.x * m.m30 + v.y * m.m31 + v.z * m.m32 + v.w * m.m33);
}
	
template <typename Number>
Matrix4<Number> Transpose(const Matrix4<Number>& m)
{
	return Matrix4<Number>(
		m.m00, m.m10, m.m20, m.m30,
		m.m01, m.m11, m.m21, m.m31,
		m.m02, m.m12, m.m22, m.m32,
		m.m03, m.m13, m.m23, m.m33 );
}
	
template <typename Number>
Matrix4<Number> Inverse(const Matrix4<Number>& m)
{
	Number v0 = m.m20 * m.m31 - m.m21 * m.m30;
	Number v1 = m.m20 * m.m32 - m.m22 * m.m30;
	Number v2 = m.m20 * m.m33 - m.m23 * m.m30;
	Number v3 = m.m21 * m.m32 - m.m22 * m.m31;
	Number v4 = m.m21 * m.m33 - m.m23 * m.m31;
	Number v5 = m.m22 * m.m33 - m.m23 * m.m32;
	
	const Number t00 = + (v5 * m.m11 - v4 * m.m12 + v3 * m.m13);
	const Number t10 = - (v5 * m.m10 - v2 * m.m12 + v1 * m.m13);
	const Number t20 = + (v4 * m.m10 - v2 * m.m11 + v0 * m.m13);
	const Number t30 = - (v3 * m.m10 - v1 * m.m11 + v0 * m.m12);
	
	const Number determinant = t00 * m.m00 + t10 * m.m01 + t20 * m.m02 + t30 * m.m03;
	
	const Number d00 = t00 / determinant;
	const Number d10 = t10 / determinant;
	const Number d20 = t20 / determinant;
	const Number d30 = t30 / determinant;
	
	const Number d01 = - (v5 * m.m01 - v4 * m.m02 + v3 * m.m03) / determinant;
	const Number d11 = + (v5 * m.m00 - v2 * m.m02 + v1 * m.m03) / determinant;
	const Number d21 = - (v4 * m.m00 - v2 * m.m01 + v0 * m.m03) / determinant;
	const Number d31 = + (v3 * m.m00 - v1 * m.m01 + v0 * m.m02) / determinant;
	
	v0 = m.m10 * m.m31 - m.m11 * m.m30;
	v1 = m.m10 * m.m32 - m.m12 * m.m30;
	v2 = m.m10 * m.m33 - m.m13 * m.m30;
	v3 = m.m11 * m.m32 - m.m12 * m.m31;
	v4 = m.m11 * m.m33 - m.m13 * m.m31;
	v5 = m.m12 * m.m33 - m.m13 * m.m32;
	
	const Number d02 = + (v5 * m.m01 - v4 * m.m02 + v3 * m.m03) / determinant;
	const Number d12 = - (v5 * m.m00 - v2 * m.m02 + v1 * m.m03) / determinant;
	const Number d22 = + (v4 * m.m00 - v2 * m.m01 + v0 * m.m03) / determinant;
	const Number d32 = - (v3 * m.m00 - v1 * m.m01 + v0 * m.m02) / determinant;
	
	v0 = m.m21 * m.m10 - m.m20 * m.m11;
	v1 = m.m22 * m.m10 - m.m20 * m.m12;
	v2 = m.m23 * m.m10 - m.m20 * m.m13;
	v3 = m.m22 * m.m11 - m.m21 * m.m12;
	v4 = m.m23 * m.m11 - m.m21 * m.m13;
	v5 = m.m23 * m.m12 - m.m22 * m.m13;
	
	const Number d03 = - (v5 * m.m01 - v4 * m.m02 + v3 * m.m03) / determinant;
	const Number d13 = + (v5 * m.m00 - v2 * m.m02 + v1 * m.m03) / determinant;
	const Number d23 = - (v4 * m.m00 - v2 * m.m01 + v0 * m.m03) / determinant;
	const Number d33 = + (v3 * m.m00 - v1 * m.m01 + v0 * m.m02) / determinant;
	
	return Matrix4<Number>(
		d00, d01, d02, d03,
		d10, d11, d12, d13,
		d20, d21, d22, d23,
		d30, d31, d32, d33);
}
	
}
	
}
