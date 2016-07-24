#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace EntitySystem
{

class ComponentTemplateTests:
	public UnitTestClass
{
public:

	ComponentTemplateTests();

private:
	
	void CheckIds( Fnd::Test::TestCase& test_case );
	
	void CheckDataIsEqual( Fnd::Test::TestCase& test_case );

	void CheckDataFromConstructorIsEqual( Fnd::Test::TestCase& test_case );
};

}

}

}
