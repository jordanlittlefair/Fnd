#include "ModulesTestSuite.hpp"

#include "ModuleConfigFileTests.hpp"
#include "ModuleConfigTests.hpp"
#include "ModuleTests.hpp"

using namespace Fnd::Test::Modules;

ModulesTestSuite::ModulesTestSuite():
	TestSuite("ModulesTestSuiteTestSuite")
{
	AddTestClass<ModuleConfigFileTests>();
	AddTestClass<ModuleConfigTests>();
	AddTestClass<ModuleTests>();
}
