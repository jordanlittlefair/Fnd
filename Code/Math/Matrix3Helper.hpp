#pragma once

#include "Matrix3.hpp"
#include "MatrixHelper.hpp"
#include "Utility.hpp"

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
				1, 0, 0,
				0, Utility::Cos(radians), -Utility::Sin(radians),
				0, Utility::Sin(radians), Utility::Cos(radians)));
	}
	
	template <typename Number>
	static Matrix3<Number> CreateYRotationMatrix(const Number& radians)
	{
		return MatrixHelper<MatrixOrderT>::ConvertOrder(
			Matrix3<Number>(
				Utility::Cos(radians), 0, Utility::Sin(radians),
				0, 1, 0,
				-Utility::Sin(radians), 0, Utility::Cos(radians)));
	}
	
	template <typename Number>
	static Matrix3<Number> CreateZRotationMatrix(const Number& radians)
	{
		return MatrixHelper<MatrixOrderT>::ConvertOrder(
			Matrix3<Number>(
				Utility::Cos(radians), 0, Utility::Sin(radians),
				-Utility::Sin(radians), 0, Utility::Cos(radians),
				0, 1, 0));
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
