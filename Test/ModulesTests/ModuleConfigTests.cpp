#include "ModuleConfigTests.hpp"

using namespace Fnd::Test::Modules;


ModuleConfigTests::ModuleConfigTests():
	UnitTestClass("ModuleConfigFileTests")
{
	AddTestCase("Test", &ModuleConfigTests::Test, this);
}

void ModuleConfigTests::Test(Fnd::Test::TestCase& test_case)
{
}
