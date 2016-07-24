#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace EntitySystem
{
	
class NodeTemplateTests:
	public UnitTestClass
{
public:
	
	NodeTemplateTests();
	
private:
	
	void GetNodeId_Success( Fnd::Test::TestCase& test_case );
	
	void GetEntityId_Success( Fnd::Test::TestCase& test_case );
	
	void GetNodeNonConst_Success( Fnd::Test::TestCase& test_case );
	
	void GetNodeNonConst_NonExistingEntityId( Fnd::Test::TestCase& test_case );
	
	void GetNodeNonConst_PartExistingEntityId( Fnd::Test::TestCase& test_case );
	
	void GetNodeNonConst_UnregisteredComponent( Fnd::Test::TestCase& test_case );
	
	void GetNodeNonConst_PartUnregisteredComponent( Fnd::Test::TestCase& test_case );
	
	void GetNodeConst_Success( Fnd::Test::TestCase& test_case );
	
	void GetNodeConst_NonExistingEntityId( Fnd::Test::TestCase& test_case );

	void GetNodeConst_PartExistingEntityId( Fnd::Test::TestCase& test_case );
	
	void GetNodeConst_UnregisteredComponent( Fnd::Test::TestCase& test_case );
	
	void GetNodeConst_PartUnregisteredComponent( Fnd::Test::TestCase& test_case );
};
	
}

}

}
