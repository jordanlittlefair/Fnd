#pragma once

#include "../Framework/TestClass.hpp"

namespace Fnd
{
	
namespace Test
{

namespace SystemManager
{

class SystemManagerExceptionTests:
	public TestClass
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
