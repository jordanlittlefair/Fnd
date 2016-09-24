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
	
	template <Handedness Handedness, typename Number>
	static Matrix4<Number> CreateWorldMatrix(const Vector3<Number>& position, const Vector3<Number>& direction, const Vector3<Number>& up)
	{
		const Vector3<Number> z_axis = Handedness == Handedness::Left ? Normalise(direction) : -Normalise(direction);
		const Vector3<Number> x_axis = Normalise(Cross(up, z_axis));
		const Vector3<Number> y_axis = Cross(z_axis, x_axis);
		
		return MatrixHelper<MatrixOrderT>::ConvertOrder(
			Matrix4<Number>(
				x_axis.x, x_axis.y, x_axis.z, 0,
				y_axis.x, y_axis.y, y_axis.z, 0,
				z_axis.x, z_axis.y, z_axis.z, 0,
				position.x, position.y, position.z, 1));
	}
	
	template <Handedness Handedness, typename Number>
	static Matrix4<Number> CreateLookAtMatrix(const Vector3<Number>& eye, const Vector3<Number>& target, const Vector3<Number>& up)
	{
		const Vector3<Number> z_axis = Handedness == Handedness::Left ? Normalise(eye - target) : Normalise(target - eye);
		const Vector3<Number> x_axis = Normalise(Cross(up, z_axis));
		const Vector3<Number> y_axis = Normalise(Cross(z_axis, x_axis));
		
		return MatrixHelper<MatrixOrderT>::ConvertOrder(
			Matrix4<Number>(
				x_axis.x, y_axis.x, z_axis.x, 0,
				x_axis.y, y_axis.y, z_axis.y, 0,
				x_axis.z, y_axis.z, z_axis.z, 0,
				Dot(x_axis, eye), Dot(y_axis, eye), Dot(z_axis, eye), 1));
	}
	
	template <Handedness Handedness, typename Number>
	static Matrix4<Number> CreateProjectionMatrix(const Number fov_rad, const Number& aspect_ratio, const Number& near_plane, const Number& far_plane)
	{
		const Number y_scale = 1 / Utility::Tan( fov_rad / 2 );
		
		return MatrixHelper<MatrixOrderT>::ConvertOrder(
			Matrix4<Number>(
				y_scale / aspect_ratio, 0, 0, 0,
				0, y_scale, 0, 0,
				0, 0, far_plane / (Handedness == Handedness::Left ? (far_plane - near_plane) : (near_plane - far_plane)), Handedness == Handedness::Left ? 1 : -1,
				0, 0, near_plane * far_plane / ( near_plane - far_plane ), 0 ));
	}
};
	
}
	
}
