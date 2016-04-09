#pragma once

#include "../Framework/TestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace EntitySystem
{

class ComponentTests:
	public TestClass
{
public:

	ComponentTests();

private:
	
	void CheckComponentId( Fnd::Test::TestCase& test_case );

	void CheckEntityId( Fnd::Test::TestCase& test_case );
};

}

}

}
