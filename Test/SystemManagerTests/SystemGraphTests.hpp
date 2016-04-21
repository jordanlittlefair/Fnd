#pragma once

#include "../Framework/TestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{

class SystemGraphTests:
	public TestClass
{
public:

	SystemGraphTests();

private:

	void TestUpdateSystemNodes_Empty( TestCase& test_case );
	void TestUpdateSystemNodes_DuplicateIds( TestCase& test_case );
	void TestUpdateSystemNodes_SingleNode( TestCase& test_case );
	void TestUpdateSystemNodes_NoDependencies( TestCase& test_case );
	void TestUpdateSystemNodes_SingleDependency( TestCase& test_case );
	void TestUpdateSystemNodes_MultipleDependencies( TestCase& test_case );
	void TestUpdateSystemNodes_SharedDependencies( TestCase& test_case );
	void TestUpdateSystemNodes_Chain( TestCase& test_case );
	void TestUpdateSystemNodes_CyclicDependencies( TestCase& test_case );
};

}

}

}
