#pragma once

#include "../Framework/TestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace EntitySystem
{

class ComponentManagerTests:
	public TestClass
{
public:

	ComponentManagerTests();

private:
	
	void RegisterComponent_Succeed( Fnd::Test::TestCase& test_case );

	void RegisterComponent_Duplicate_Fail( Fnd::Test::TestCase& test_case );

	void IsRegistered_True( Fnd::Test::TestCase& test_case );

	void IsRegistered_False( Fnd::Test::TestCase& test_case );

	void CreateComponent_Succeed( Fnd::Test::TestCase& test_case );

	void CreateComponent_DuplicateId_Fail( Fnd::Test::TestCase& test_case );

	void CreateComponent_UnregisteredComponent_Fail( Fnd::Test::TestCase& test_case );

	void CreateComponent_WithData_Succeed( Fnd::Test::TestCase& test_case );

	void CreateComponent_WithData_DuplicateId_Fail( Fnd::Test::TestCase& test_case );

	void CreateComponent_WithData_UnregisteredComponent_Fail( Fnd::Test::TestCase& test_case );

	void HasComponent_True( Fnd::Test::TestCase& test_case );

	void HasComponent_Fail( Fnd::Test::TestCase& test_case );

	void HasComponent_UnregisteredComponent_Fail( Fnd::Test::TestCase& test_case );

	void GetComponentNonConst_Succeed( Fnd::Test::TestCase& test_case );

	void GetComponentNonConst_InvalidId_Fail( Fnd::Test::TestCase& test_case );

	void GetComponentNonConst_UnregisteredComponent_Fail( Fnd::Test::TestCase& test_case );

	void GetComponentConst_Succeed( Fnd::Test::TestCase& test_case );

	void GetComponentConst_InvalidId_Fail( Fnd::Test::TestCase& test_case );

	void GetComponentConst_UnregisteredComponent_Fail( Fnd::Test::TestCase& test_case );

	void DestroyComponent_Succeed( Fnd::Test::TestCase& test_case );

	void DestroyComponent_InvalidId_Fail( Fnd::Test::TestCase& test_case );

	void DestroyComponent_UnregisteredComponent_Fail( Fnd::Test::TestCase& test_case );
};

}

}

}
