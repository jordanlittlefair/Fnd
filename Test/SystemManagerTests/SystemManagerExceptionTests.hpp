#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{
	
namespace Test
{

namespace SystemManager
{

class SystemManagerExceptionTests:
	public UnitTestClass
{
public:

	SystemManagerExceptionTests();

private:

	void TestInvalidSystemIdException( TestCase& test_case );
	void TestInvalidSystemDependenciesException( TestCase& test_case );
};

}

}
	
}
