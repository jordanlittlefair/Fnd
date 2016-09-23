#pragma once

#include "Matrix4.hpp"
#include "MatrixHelper.hpp"
#include "Utility.hpp"
#include "Vector3.hpp"

namespace Fnd
{

namespace Math
{

template <MatrixOrder MatrixOrderT>
class Matrix4Helper:
	public MatrixHelper<MatrixOrderT>
{
public:
	
	template <typename Number>
	static Matrix4<Number> CreateTranslationMatrix(const Vector3<Number>& vec)
	{
		return MatrixHelper<MatrixOrderT>::ConvertOrder(
			Matrix4<Number>(
				1, 0, 0, 0,
				0, 1, 0, 0,
				0, 0, 1, 0,
				vec.x, vec.y, vec.z, 1));
	}
	
	template <typename Number>
	static Matrix4<Number> CreateScaleMatrix(const Number& scale)
	{
		return MatrixHelper<MatrixOrderT>::ConvertOrder(
			Matrix4<Number>(
				scale, 0, 0, 0,
				0, scale, 0, 0,
				0, 0, scale, 0,
				0, 0, 0, 1));
	}
	
	template <typename Number>
	static Matrix4<Number> CreateScaleMatrix(const Number& scale_x, const Number& scale_y, const Number& scale_z)
	{
		return MatrixHelper<MatrixOrderT>::ConvertOrder(
			Matrix4<Number>(
				scale_x, 0, 0, 0,
				0, scale_y, 0, 0,
				0, 0, scale_z, 0,
				0, 0, 0, 1));
	}
	
	template <typename Number>
	static Matrix4<Number> CreateXRotationMatrix(const Number& radians)
	{
		return MatrixHelper<MatrixOrderT>::ConvertOrder(
			Matrix4<Number>(
				1, 0, 0, 0,
				0, Utility::Cos(radians), -Utility::Sin(radians), 0,
				0, Utility::Sin(radians), Utility::Cos(radians), 0,
				0, 0, 0, 1));
	}
	
	template <typename Number>
	static Matrix4<Number> CreateYRotationMatrix(const Number& radians)
	{
		return MatrixHelper<MatrixOrderT>::ConvertOrder(
			Matrix4<Number>(
				Utility::Cos(radians), 0, Utility::Sin(radians), 0,
				0, 1, 0, 0,
				-Utility::Sin(radians), 0, Utility::Cos(radians), 0,
				0, 0, 0, 1));
	}
	
	template <typename Number>
	static Matrix4<Number> CreateZRotationMatrix(const Number& radians)
	{
		return MatrixHelper<MatrixOrderT>::ConvertOrder(
			Matrix4<Number>(
				Utility::Cos(radians), 0, Utility::Sin(radians), 0,
				-Utility::Sin(radians), 0, Utility::Cos(radians), 0,
				0, 1, 0, 0,
				0, 0, 0, 1));
	}
};

}

}
