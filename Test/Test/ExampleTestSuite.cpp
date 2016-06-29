#include "ExampleTestSuite.hpp"

using namespace Fnd::Test;

#include "ExampleTestClass.hpp"

ExampleTestSuite::ExampleTestSuite():
	TestSuite("ExampleTestSuite")
{
	AddTestClass<ExampleTestClass>();
}
