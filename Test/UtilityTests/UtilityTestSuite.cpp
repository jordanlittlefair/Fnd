#include "UtilityTestSuite.hpp"

#include "HashIdFromNameGeneratorTests.hpp"

using namespace Fnd::Test::Utility;

UtilityTestSuite::UtilityTestSuite():
	TestSuite("UtilityTestSuite")
{
	AddTestClass<HashIdFromNameGeneratorTests>();
}
