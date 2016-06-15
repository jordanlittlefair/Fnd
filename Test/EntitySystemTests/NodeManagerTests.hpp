#pragma once

#include "../Framework/TestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace EntitySystem
{
	
class NodeManagerTests:
	public TestClass
{
public:
	
	NodeManagerTests();
	
private:
	
	void RegisterNode_Succeed( Fnd::Test::TestCase& test_case );
	
	void RegisterNode_Duplicate_Fail( Fnd::Test::TestCase& test_case );
	
	void IsRegistered_True( Fnd::Test::TestCase& test_case );
	
	void IsRegistered_False( Fnd::Test::TestCase& test_case );
	
	void CreateNode_Succeed( Fnd::Test::TestCase& test_case );
	
	void CreateNode_DuplicateId_Fail( Fnd::Test::TestCase& test_case );
	
	void CreateNode_UnregisteredNode_Fail( Fnd::Test::TestCase& test_case );
	
	void HasNode_True( Fnd::Test::TestCase& test_case );
	
	void HasNode_False( Fnd::Test::TestCase& test_case );
	
	void HasNode_UnregisteredNode_Fail( Fnd::Test::TestCase& test_case );
	
	void GetNodeNonConst_Succeed( Fnd::Test::TestCase& test_case );
	
	void GetNodeNonConst_InvalidId_Fail( Fnd::Test::TestCase& test_case );
	
	void GetNodeNonConst_UnregisteredNode_Fail( Fnd::Test::TestCase& test_case );
	
	void GetNodeConst_Succeed( Fnd::Test::TestCase& test_case );
	
	void GetNodeConst_InvalidId_Fail( Fnd::Test::TestCase& test_case );
	
	void GetNodeConst_UnregisteredNode_Fail( Fnd::Test::TestCase& test_case );
	
	void DestroyNode_Succeed( Fnd::Test::TestCase& test_case );
	
	void DestroyNode_InvalidId_Fail( Fnd::Test::TestCase& test_case );
	
	void DestroyNode_UnregisteredNode_Fail( Fnd::Test::TestCase& test_case );
	
	void ForEachNodeNonConst_NoNodes_Success(Fnd::Test::TestCase& test_case);
	
	void ForEachNodeNonConst_MultipleNodes_Success(Fnd::Test::TestCase& test_case);
	
	void ForEachNodeNonConst_UnregisteredNode_Fail(Fnd::Test::TestCase& test_case);
	
	void ForEachNodeConst_NoNodes_Success(Fnd::Test::TestCase& test_case);
	
	void ForEachNodeConst_MultipleNodes_Success(Fnd::Test::TestCase& test_case);
	
	void ForEachNodeConst_UnregisteredNode_Fail(Fnd::Test::TestCase& test_case);
};

}

}

}
