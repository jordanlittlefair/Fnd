#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{

class OptimalPathFinderTests:
	public UnitTestClass
{
public:

	OptimalPathFinderTests();

private:

	void TestConstructor( TestCase& test_case );
	void TestClearSystemNodes( TestCase& test_case );
	void TestOptimalPath_Empty( TestCase& test_case );
	void TestOptimalPath_NoDependencies( TestCase& test_case );
	void TestOptimalPath_DependencyChain( TestCase& test_case );
	void TestOptimalPath_MultipleDependencies( TestCase& test_case );
	void TestOptimalPath_SharedDependency( TestCase& test_case );
	void TestOptimalPath_ForkAndJoin( TestCase& test_case );
};

}

}

}
