#include "UtilityTestSuite.hpp"

#include "HashIdFromNameGeneratorTests.hpp"
#include "IdNameMapperTests.hpp"

using namespace Fnd::Test::Utility;

UtilityTestSuite::UtilityTestSuite():
	TestSuite("UtilityTestSuite")
{
	AddTestClass<HashIdFromNameGeneratorTests>();
	AddTestClass<IdNameMapperTests>();
}
