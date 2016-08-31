#include "UtilityTestSuite.hpp"

#include "HashIdFromNameGeneratorTests.hpp"
#include "IdNameMapperTests.hpp"
#include "DocumentTreeTests.hpp"

using namespace Fnd::Test::Utility;

UtilityTestSuite::UtilityTestSuite():
	TestSuite("UtilityTestSuite")
{
	AddTestClass<HashIdFromNameGeneratorTests>();
	AddTestClass<IdNameMapperTests>();
	AddTestClass<DocumentTreeTests>();
}
