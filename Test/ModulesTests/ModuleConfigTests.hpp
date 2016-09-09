#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace Modules
{

class ModuleConfigTests:
	public UnitTestClass
{
public:
	
	ModuleConfigTests();
	
private:
	
	void Test(Fnd::Test::TestCase& test_case);
};

}

}

}
