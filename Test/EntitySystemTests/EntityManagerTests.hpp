#pragma once

#include "../Framework/TestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace EntitySystem
{

class EntityManagerTests:
	public TestClass
{
public:

	EntityManagerTests();

private:
	
	void CreateEntity_Success(Fnd::Test::TestCase& test_case);

	void CreateEntity_Multiple_Success(Fnd::Test::TestCase& test_case);

	void HasEntity_True(Fnd::Test::TestCase& test_case);

	void HasEntity_False(Fnd::Test::TestCase& test_case);

	void DestroyEntity_Success(Fnd::Test::TestCase& test_case);

	void DestroyEntity_InvalidId_Fail(Fnd::Test::TestCase& test_case);
};

}

}

}
