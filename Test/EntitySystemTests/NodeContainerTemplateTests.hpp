#pragma once

#include "../Framework/TestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace EntitySystem
{

class NodeContainerTemplateTests:
	public TestClass
{
public:

	NodeContainerTemplateTests();

private:

	void GetNodeId_Success(Fnd::Test::TestCase& test_case);
	
	void CreateNode_Success(Fnd::Test::TestCase& test_case);
	
	void CreateNode_Duplicate_Fail(Fnd::Test::TestCase& test_case);
	
	void HasNode_True(Fnd::Test::TestCase& test_case);
	
	void HasNode_False(Fnd::Test::TestCase& test_case);
	
	void GetNodeConst_Success(Fnd::Test::TestCase& test_case);
	
	void GetNodeConst_NonExistingEntityId_Fail(Fnd::Test::TestCase& test_case);
	
	void GetNodeNonConst_Success(Fnd::Test::TestCase& test_case);
	
	void GetNodeNonConst_NonExistingEntityId_Fail(Fnd::Test::TestCase& test_case);
	
	void DestroyNode_Success(Fnd::Test::TestCase& test_case);
	
	void DestroyNode_NonExistingEntityId(Fnd::Test::TestCase& test_case);

	void Base_GetNodeConst_Success(Fnd::Test::TestCase& test_case);
	
	void Base_GetNodeConst_NonExistingEntityId_Fail(Fnd::Test::TestCase& test_case);
	
	void Base_GetNodeNonConst_Success(Fnd::Test::TestCase& test_case);
	
	void Base_GetNodeNonConst_NonExistingEntityId_Fail(Fnd::Test::TestCase& test_case);
};

}

}

}
