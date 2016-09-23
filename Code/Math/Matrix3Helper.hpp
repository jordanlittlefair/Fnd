#pragma once

#include "Matrix3.hpp"
#include "MatrixHelper.hpp"

namespace Fnd
{

namespace Math
{

template <MatrixOrder MatrixOrderT>
class Matrix3Helper:
	public MatrixHelper<MatrixOrderT>
{
public:
	
	template <typename Number>
	static Matrix3<Number> CreateXRotationMatrix(const Number& radians)
	{
		return MatrixHelper<MatrixOrderT>::ConvertOrder(
			Matrix3<Number>(
				1.0f, 0.0f, 0.0f,
				0.0f, cos(radians), -sin(radians),
				0.0f, sin(radians), cos(radians)));
	}
	
	template <typename Number>
	static Matrix3<Number> CreateYRotationMatrix(const Number& radians)
	{
		return MatrixHelper<MatrixOrderT>::ConvertOrder(
			Matrix3<Number>(
				cos(radians), 0.0f, sin(radians),
				0.0f, 1.0f, 0.0f,
				-sin(radians), 0.0f, cos(radians)));
	}
	
	template <typename Number>
	static Matrix3<Number> CreateZRotationMatrix(const Number& radians)
	{
		return MatrixHelper<MatrixOrderT>::ConvertOrder(
			Matrix3<Number>(
				cos(radians), 0.0f, sin(radians),
				-sin(radians), 0.0f, cos(radians),
				0.0f, 1.0f, 0.0f));
	}
	
	template <typename Number>
	static Matrix3<Number> CreateScaleMatrix(const Number& scale)
	{
		return MatrixHelper<MatrixOrderT>::ConvertOrder(
			Matrix3<Number>(
				scale, 0, 0,
				0, scale, 0,
				0, 0, scale));
	}
	
	template <typename Number>
	static Matrix3<Number> CreateScaleMatrix(const Number& scale_x, const Number& scale_y, const Number& scale_z)
	{
		return MatrixHelper<MatrixOrderT>::ConvertOrder(
			Matrix3<Number>(
				scale_x, 0, 0,
				0, scale_y, 0,
				0, 0, scale_z));
	}
};

}

}
