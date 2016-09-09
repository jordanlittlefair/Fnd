#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace Modules
{

class ModuleConfigFileTests:
	public UnitTestClass
{
public:
	
	ModuleConfigFileTests();
	
private:
	
	void Test(Fnd::Test::TestCase& test_case);
};

}

}

}
