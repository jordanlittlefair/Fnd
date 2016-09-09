#include "UtilityTestSuite.hpp"

#include "HashIdFromNameGeneratorTests.hpp"
#include "IdNameMapperTests.hpp"
#include "DocumentTreeTests.hpp"
#include "StdFileTests.hpp"
#include "JsonParserTests.hpp"

using namespace Fnd::Test::Utility;

UtilityTestSuite::UtilityTestSuite():
	TestSuite("UtilityTestSuite")
{
	AddTestClass<HashIdFromNameGeneratorTests>();
	AddTestClass<IdNameMapperTests>();
	AddTestClass<DocumentTreeTests>();
	AddTestClass<StdFileTests>();
	AddTestClass<JsonParserTests>();
}
