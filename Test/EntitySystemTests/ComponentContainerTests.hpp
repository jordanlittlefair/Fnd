#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace EntitySystem
{

class ComponentContainerTests:
	public UnitTestClass
{
public:

	ComponentContainerTests();

private:
	
	void CheckComponentId( Fnd::Test::TestCase& test_case );
	void CheckGetComponent( Fnd::Test::TestCase& test_case );
};

}

}

}
