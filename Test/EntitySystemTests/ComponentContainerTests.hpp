#pragma once

#include "../Framework/TestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace EntitySystem
{

class ComponentContainerTests:
	public TestClass
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
