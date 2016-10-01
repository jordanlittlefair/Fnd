#include "MathTestSuite.hpp"

#include "Vector2Tests.hpp"
#include "Vector3Tests.hpp"
#include "Vector4Tests.hpp"

using namespace Fnd::Test::Math;

MathTestSuite::MathTestSuite():
	TestSuite("MathTestSuite")
{
	AddTestClass(std::make_shared<Vector2Tests<float>>("float"));
	AddTestClass(std::make_shared<Vector2Tests<double>>("double"));
	AddTestClass(std::make_shared<Vector3Tests<float>>("float"));
	AddTestClass(std::make_shared<Vector3Tests<double>>("double"));
	AddTestClass(std::make_shared<Vector4Tests<float>>("float"));
	AddTestClass(std::make_shared<Vector4Tests<double>>("double"));
}
