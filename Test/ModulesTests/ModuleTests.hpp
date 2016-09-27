#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace Modules
{

class ModuleTests:
	public UnitTestClass
{
public:
	
	ModuleTests();
	
private:
	
	void GetName_Success(Fnd::Test::TestCase& test_case);
	void RegisterComponents_Success(Fnd::Test::TestCase& test_case);
	void RegisterNodes_Success(Fnd::Test::TestCase& test_case);
	void RegisterSystems_Success(Fnd::Test::TestCase& test_case);
	void Initialise_Success(Fnd::Test::TestCase& test_case);
	void Initialise_Throw_Fail(Fnd::Test::TestCase& test_case);
	void Initialise_AlreadyInitialised_Fail(Fnd::Test::TestCase& test_case);
};

}

}

}
