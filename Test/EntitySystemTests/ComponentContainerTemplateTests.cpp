#include "ComponentContainerTemplateTests.hpp"

#include "MockComponentTypes.hpp"

#include "../../Code/EntitySystem/ComponentContainerTemplate.hpp"

using namespace Fnd::Test::EntitySystem;
using namespace Fnd::EntitySystem;

ComponentContainerTemplateTests::ComponentContainerTemplateTests():
	TestClass("ComponentContainerTemplateTests")
{
	AddTestCase( "CheckComponentId", &ComponentContainerTemplateTests::CheckComponentId, this );
	AddTestCase( "CheckCreateComponent", &ComponentContainerTemplateTests::CheckCreateComponent, this );
	AddTestCase( "CheckCreateDuplicateComponent", &ComponentContainerTemplateTests::CheckCreateDuplicateComponent, this );
	AddTestCase( "CheckHasComponent", &ComponentContainerTemplateTests::CheckHasComponent, this );
	AddTestCase( "CheckDataIsEqual", &ComponentContainerTemplateTests::CheckDataIsEqual, this );
	AddTestCase( "CheckDataFromConstructorIsEqual", &ComponentContainerTemplateTests::CheckDataFromConstructorIsEqual, this );
	AddTestCase( "CheckDestroyComponent", &ComponentContainerTemplateTests::CheckDestroyComponent, this );
	AddTestCase( "CheckComponentDoesntExist", &ComponentContainerTemplateTests::CheckComponentId, this );
	AddTestCase( "CheckGetComponentBase", &ComponentContainerTemplateTests::CheckGetComponentBase, this );
}

void ComponentContainerTemplateTests::CheckComponentId( Fnd::Test::TestCase& test_case )
{
	ComponentContainerTemplate<MockComponentType1> container;

	test_case.Assert( container.GetComponentId() == MockComponentType1::Id );
}

void ComponentContainerTemplateTests::CheckCreateComponent( Fnd::Test::TestCase& test_case )
{
	ComponentContainerTemplate<MockComponentType1> container;

	Component& component1 = container.CreateComponent( 1 );

	test_case.Assert( container.HasComponent( 1 ) );
	test_case.Assert( component1.GetEntityId() == 1 );

	Component& component2 = container.CreateComponent( 2, MockComponentType1::Data() );

	test_case.Assert( container.HasComponent( 2 ) );
	test_case.Assert( component2.GetEntityId() == 2 );
}

void ComponentContainerTemplateTests::CheckCreateDuplicateComponent( Fnd::Test::TestCase& test_case )
{
	ComponentContainerTemplate<MockComponentType1> container;

	container.CreateComponent( 1 );
	
	try
	{
		container.CreateComponent( 1 );

		test_case.Assert( false, "CreateComponent must throw InvalidEntityIdException" );
	}
	catch ( const InvalidEntityIdException& )
	{
		test_case.Assert( true, "CreateComponent must throw InvalidEntityIdException" );
	}
}

void ComponentContainerTemplateTests::CheckHasComponent( Fnd::Test::TestCase& test_case )
{
	ComponentContainerTemplate<MockComponentType1> container;

	container.CreateComponent( 1 );

	test_case.Assert( container.HasComponent( 1 ) );

	test_case.Assert( !container.HasComponent( 2 ) );
}
	
void ComponentContainerTemplateTests::CheckDataIsEqual( Fnd::Test::TestCase& test_case )
{
	MockComponentType1::Data expected_data;
	expected_data.some_int = 123;
	expected_data.some_string = "123";

	ComponentContainerTemplate<MockComponentType1> container;

	auto& created = container.CreateComponent( 1 );

	*created = expected_data;

	test_case.Assert( container.GetComponent( 1 )->some_int == expected_data.some_int );
	test_case.Assert( container.GetComponent( 1 )->some_string == expected_data.some_string );

	expected_data.some_int = 1234;
	expected_data.some_string = "1234";

	*container.GetComponent( 1 ) = expected_data;

	test_case.Assert( container.GetComponent( 1 )->some_int == expected_data.some_int );
	test_case.Assert( container.GetComponent( 1 )->some_string == expected_data.some_string );
}

void ComponentContainerTemplateTests::CheckDataFromConstructorIsEqual( Fnd::Test::TestCase& test_case )
{
	MockComponentType1::Data expected_data;
	expected_data.some_int = 123;
	expected_data.some_string = "123";

	ComponentContainerTemplate<MockComponentType1> container;

	auto& created = container.CreateComponent( 1, expected_data );

	test_case.Assert( created->some_int == expected_data.some_int );
	test_case.Assert( created->some_string == expected_data.some_string );

	test_case.Assert( container.GetComponent( 1 )->some_int == expected_data.some_int );
	test_case.Assert( container.GetComponent( 1 )->some_string == expected_data.some_string );
}

void ComponentContainerTemplateTests::CheckDestroyComponent( Fnd::Test::TestCase& test_case )
{
	ComponentContainerTemplate<MockComponentType1> container;

	Component& component1 = container.CreateComponent( 1 );
	Component& component2 = container.CreateComponent( 2, MockComponentType1::Data() );

	test_case.Assert( container.HasComponent( 1 ) );
	test_case.Assert( container.HasComponent( 2 ) );

	container.DestroyComponent( 1 );

	test_case.Assert( !container.HasComponent( 1 ) );
	test_case.Assert( container.HasComponent( 2 ) );

	container.DestroyComponent( 2 );

	test_case.Assert( !container.HasComponent( 1 ) );
	test_case.Assert( !container.HasComponent( 2 ) );
}

void ComponentContainerTemplateTests::CheckComponentDoesntExist( Fnd::Test::TestCase& test_case )
{
	ComponentContainerTemplate<MockComponentType1> container;
	
	test_case.Assert( !container.HasComponent( 1 ) );

	try
	{
		container.GetComponent( 1 );

		test_case.Assert( false, "GetComponent must throw InvalidEntityIdException" );
	}
	catch ( const InvalidEntityIdException& )
	{
		test_case.Assert( true, "GetComponent must throw InvalidEntityIdException" );
	}
}

void ComponentContainerTemplateTests::CheckGetComponentBase( Fnd::Test::TestCase& test_case )
{
	ComponentContainerTemplate<MockComponentType1> container;

	container.CreateComponent( 1 );

	ComponentContainer* base = &container;

	test_case.Assert( base->GetComponentId() == container.GetComponentId() );

	Component& component = base->GetComponent( 1 );
	
	test_case.Assert( component.GetComponentId() == container.GetComponentId() );
	test_case.Assert( component.GetEntityId() == 1 );
}