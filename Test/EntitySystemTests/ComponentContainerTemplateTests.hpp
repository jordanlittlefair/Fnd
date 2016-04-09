#pragma once

#include "../Framework/TestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace EntitySystem
{

class ComponentContainerTemplateTests:
	public TestClass
{
public:

	ComponentContainerTemplateTests();

private:
	
	void CheckComponentId( Fnd::Test::TestCase& test_case );

	void CheckCreateComponent( Fnd::Test::TestCase& test_case );

	void CheckCreateDuplicateComponent( Fnd::Test::TestCase& test_case );

	void CheckHasComponent( Fnd::Test::TestCase& test_case );
	
	void CheckDataIsEqual( Fnd::Test::TestCase& test_case );

	void CheckDataFromConstructorIsEqual( Fnd::Test::TestCase& test_case );

	void CheckDestroyComponent( Fnd::Test::TestCase& test_case );

	void CheckComponentDoesntExist( Fnd::Test::TestCase& test_case );

	void CheckGetComponentBase( Fnd::Test::TestCase& test_case );
};

}

}

}
