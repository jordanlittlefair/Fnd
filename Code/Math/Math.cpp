#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"
#include "Constants.hpp"
#include "Utility.hpp"
#include "Quaternion.hpp"
#include "Matrix3.hpp"
#include "Matrix4.hpp"
#include "Matrix3Helper.hpp"
#include "Matrix4Helper.hpp"

using namespace Fnd::Math;

void test()
{
	Vector4f fv;
	
	auto zero = Vector4f::Zero();
	
	fv = -fv + fv - fv * 5 * fv * fv / 5 / fv;
	fv /= 5;
	
	// TODO: normalise/dot etc
	
	Normalise(fv);
	
	Dot(fv, zero);
	
	Length(fv);
	LengthSquared(fv);
	
	Vector3f start(1,2,3);
	Vector3f end(4,5,6);
	
	Utility::Lerp(start, end, .75);
	
	Utility::Clamp(2,3,4);
	Utility::Sin(0.1);
	Utility::Cos(0.1);
	Utility::Tan(0.1);
	Utility::ASin(0.1);
	Utility::ACos(0.1);
	Utility::ATan(0.1);
	
	Quaternion<float> q = Quaternion<float>(1,0,0,1);
	
	q.GetXAxis() + q.GetYAxis() + q.GetZAxis();
	
	Normalise(q);
	
	q * q;
	
	Matrix3f m3;
	
	m3 = m3 * m3;
	Vector3f() * Transpose(m3);
	Inverse(m3) * Vector3f();
	
	Matrix4f m4;
	
	m4 = m4 * m4;
	Vector4f() * Transpose(m4);
	Inverse(m4) * Vector4f();
	
	Matrix3Helper<MatrixOrder::RowMajor>::CreateXRotationMatrix(0.5f);
	Matrix3Helper<MatrixOrder::RowMajor>::CreateYRotationMatrix(0.5f);
	Matrix3Helper<MatrixOrder::RowMajor>::CreateZRotationMatrix(0.5f);
	Matrix3Helper<MatrixOrder::ColumnMajor>::CreateXRotationMatrix(0.5f);
	Matrix3Helper<MatrixOrder::ColumnMajor>::CreateYRotationMatrix(0.5f);
	Matrix3Helper<MatrixOrder::ColumnMajor>::CreateZRotationMatrix(0.5f);
	Matrix3Helper<MatrixOrder::RowMajor>::CreateScaleMatrix(1.5f);
	Matrix3Helper<MatrixOrder::RowMajor>::CreateScaleMatrix(1.5f,1.5f,1.5f);
	
	Matrix4Helper<MatrixOrder::RowMajor>::CreateXRotationMatrix(0.5f);
	Matrix4Helper<MatrixOrder::RowMajor>::CreateYRotationMatrix(0.5f);
	Matrix4Helper<MatrixOrder::RowMajor>::CreateZRotationMatrix(0.5f);
	Matrix4Helper<MatrixOrder::ColumnMajor>::CreateXRotationMatrix(0.5f);
	Matrix4Helper<MatrixOrder::ColumnMajor>::CreateYRotationMatrix(0.5f);
	Matrix4Helper<MatrixOrder::ColumnMajor>::CreateZRotationMatrix(0.5f);
	Matrix4Helper<MatrixOrder::RowMajor>::CreateScaleMatrix(1.5f);
	Matrix4Helper<MatrixOrder::RowMajor>::CreateScaleMatrix(1.5f,1.5f,1.5f);
	Matrix4Helper<MatrixOrder::RowMajor>::CreateWorldMatrix<Handedness::Right>(Vector3f(), Vector3f(), Vector3f());
	Matrix4Helper<MatrixOrder::RowMajor>::CreateLookAtMatrix<Handedness::Left>(Vector3f(), Vector3f(), Vector3f());
	Matrix4Helper<MatrixOrder::ColumnMajor>::CreateProjectionMatrix<Handedness::Left>(1.0f, 16.0f / 9.0f, 0.01f, 1000.0f);
	Matrix4Helper<MatrixOrder::RowMajor>::CreateRotationMatrix(Quaternionf());
	Matrix4Helper<MatrixOrder::RowMajor>::TransformPosition(Vector3f(), Matrix4f());
	Matrix4Helper<MatrixOrder::ColumnMajor>::TransformDirection(Vector3f(), Matrix4f());
}
