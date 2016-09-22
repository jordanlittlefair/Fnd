#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"
#include "Constants.hpp"
#include "Utility.hpp"
#include "Quaternion.hpp"
#include "Matrix3.hpp"

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
	
	m3 = m3 * Transpose(m3);
	m3 = Inverse(m3) * m3;
}
