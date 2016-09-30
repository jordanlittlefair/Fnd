#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace Modules
{

class TemplatedModuleConfigTests:
public UnitTestClass
{
public:
	
	TemplatedModuleConfigTests();
	
private:
	
	void LoadDefault_Success(Fnd::Test::TestCase& test_case);
	void Load_Success(Fnd::Test::TestCase& test_case);
	void Save_Success(Fnd::Test::TestCase& test_case);
};

}

}

}
