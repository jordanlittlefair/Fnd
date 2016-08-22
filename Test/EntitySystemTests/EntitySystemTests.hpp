#pragma once

#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace EntitySystem
{

class EntitySystemTests:
	public UnitTestClass
{
public:

	EntitySystemTests();

private:

	void GetEntityManagerNonConst(Fnd::Test::TestCase& test_case);
	
	void GetEntityManagerConst(Fnd::Test::TestCase& test_case);
	
	void GetComponentManagerNonConst(Fnd::Test::TestCase& test_case);
	
	void GetComponentManagerConst(Fnd::Test::TestCase& test_case);
	
	void GetNodeManagerNonConst(Fnd::Test::TestCase& test_case);
	
	void GetNodeManagerConst(Fnd::Test::TestCase& test_case);
};

}

}

}
