#pragma once

#include "../Framework/TestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{

class CyclicGraphCheckerTests:
	public TestClass
{
public:

	CyclicGraphCheckerTests();

private:

	void TestConstructor( TestCase& test_case );
	void TestClearSystemNodes( TestCase& test_case );
	void TestIsCyclic_Empty( TestCase& test_case );
	void TestIsCyclic_SingleNode( TestCase& test_case );
	void TestIsCyclic_MultipleUnlinked( TestCase& test_case );
	void TestIsCyclic_Chain( TestCase& test_case );
	void TestIsCyclic_MultipleDependencies( TestCase& test_case );
	void TestIsCyclic_SharedDependency( TestCase& test_case );
	void TestIsCyclic_SingleCycle( TestCase& test_case );
	void TestIsCyclic_MultipleCycles( TestCase& test_case );
	void TestIsCyclic_ForkAndJoin( TestCase& test_case );
};

}

}

}
