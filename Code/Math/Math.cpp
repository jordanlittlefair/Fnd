#include "Vector4.hpp"

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
}
