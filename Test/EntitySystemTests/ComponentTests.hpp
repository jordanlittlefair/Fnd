#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace EntitySystem
{

class ComponentTests:
	public UnitTestClass
{
public:

	ComponentTests();

private:
	
	void CheckIds( Fnd::Test::TestCase& test_case );
};

}

}

}
