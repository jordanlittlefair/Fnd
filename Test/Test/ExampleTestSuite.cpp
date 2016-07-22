#include "ExampleTestSuite.hpp"

using namespace Fnd::Test;

#include "ExampleIntegrationTestClass.hpp"
#include "ExamplePerformanceTestClass.hpp"
#include "ExampleUnitTestClass.hpp"

ExampleTestSuite::ExampleTestSuite():
	TestSuite("ExampleTestSuite")
{
	AddTestClass<ExamplePerformanceTestClass>();
	AddTestClass<ExampleIntegrationTestClass>();
	AddTestClass<ExampleUnitTestClass>();
}
