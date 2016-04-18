#pragma once

#include "../Framework/TestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{

class SystemTests:
public TestClass
{
public:

	SystemTests();

private:

	void TestGetId( TestCase& test_case );
	void TestAddDependency( TestCase& test_case );
	void TestAddDependency_Duplicate( TestCase& test_case );
	void TestGetDependencies( TestCase& test_case );
};

}

}

}
