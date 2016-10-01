#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace EntitySystem
{

class NodeContainerTests:
	public UnitTestClass
{
public:

	NodeContainerTests();

private:
	
	void GetNodeId_Success(Fnd::Test::TestCase& test_case);
	
	void GetNodeNonConst_Success(Fnd::Test::TestCase& test_case);
	
	void GetNodeConst_Success(Fnd::Test::TestCase& test_case);
};

}

}

}
