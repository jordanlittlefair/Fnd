#pragma once

#include "../Framework/TestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace EntitySystem
{

class ComponentTemplateTests:
	public TestClass
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
