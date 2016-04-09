#include "ComponentTemplateTests.hpp"

#include "../../Code/EntitySystem/ComponentTemplate.hpp"

using namespace Fnd::Test::EntitySystem;
using namespace Fnd::EntitySystem;
namespace
{
	struct TestComponent
	{
		static const ComponentId Id = 123;

		struct Data
		{
			int some_int;
			std::string some_string;
		};
	};
}

ComponentTemplateTests::ComponentTemplateTests():
	TestClass("ComponentTemplateTests")
{
	AddTestCase( "CheckIds", &ComponentTemplateTests::CheckIds, this );
	AddTestCase( "CheckDataIsEqual", &ComponentTemplateTests::CheckDataIsEqual, this );
	AddTestCase( "CheckDataFromConstructorIsEqual", &ComponentTemplateTests::CheckDataFromConstructorIsEqual, this );
}

void ComponentTemplateTests::CheckIds( Fnd::Test::TestCase& test_case )
{
	const EntityId entity_id = 123;

	std::shared_ptr<Component> component = std::make_shared<ComponentTemplate<TestComponent>>( entity_id );

	test_case.Assert( component->GetComponentId() == TestComponent::Id );
	test_case.Assert( component->GetEntityId() == entity_id );
}

void ComponentTemplateTests::CheckDataIsEqual( Fnd::Test::TestCase& test_case )
{
	TestComponent::Data expected_data;
	expected_data.some_int = 123;
	expected_data.some_string = "123";

	ComponentTemplate<TestComponent> component( 0 );

	component.GetData() = expected_data;

	test_case.Assert( component.GetData().some_int == expected_data.some_int );
	test_case.Assert( component.GetData().some_string == expected_data.some_string );

	expected_data.some_int = 1234;
	expected_data.some_string = "1234";

	*component = expected_data;

	test_case.Assert( (*component).some_int == expected_data.some_int );
	test_case.Assert( (*component).some_string == expected_data.some_string );

	expected_data.some_int = 12345;
	expected_data.some_string = "12345";

	component->some_int = expected_data.some_int;
	component->some_string = expected_data.some_string;

	test_case.Assert( component->some_int == expected_data.some_int );
	test_case.Assert( component->some_string == expected_data.some_string );
}

void ComponentTemplateTests::CheckDataFromConstructorIsEqual( Fnd::Test::TestCase& test_case )
{	
	TestComponent::Data expected_data;
	expected_data.some_int = 123;
	expected_data.some_string = "123";

	ComponentTemplate<TestComponent> component( 0, expected_data );
	
	test_case.Assert( component.GetData().some_int == expected_data.some_int );
	test_case.Assert( component.GetData().some_string == expected_data.some_string );
}