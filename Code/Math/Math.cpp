#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"
#include "Constants.hpp"
#include "Utility.hpp"

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
}
