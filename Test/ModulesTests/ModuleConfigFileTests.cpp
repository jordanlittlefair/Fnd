#include "ModuleConfigFileTests.hpp"

using namespace Fnd::Test::Modules;


ModuleConfigFileTests::ModuleConfigFileTests():
	UnitTestClass("ModuleConfigFileTests")
{
	AddTestCase("Test", &ModuleConfigFileTests::Test, this);
}

void ModuleConfigFileTests::Test(Fnd::Test::TestCase& test_case)
{
}
