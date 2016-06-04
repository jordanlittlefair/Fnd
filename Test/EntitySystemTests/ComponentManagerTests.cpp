#include "ComponentManagerTests.hpp"

#include "../../Code/EntitySystem/ComponentManager.hpp"

#include "MockComponentTypes.hpp"

using namespace Fnd::Test::EntitySystem;
using namespace Fnd::EntitySystem;

ComponentManagerTests::ComponentManagerTests():
	TestClass("ComponentManagerTests")
{
	AddTestCase( "RegisterComponent_Succeed", &ComponentManagerTests::RegisterComponent_Succeed, this );
	AddTestCase( "RegisterComponent_Duplicate_Fail", &ComponentManagerTests::RegisterComponent_Duplicate_Fail, this );
	AddTestCase( "IsRegistered_True", &ComponentManagerTests::IsRegistered_True, this );
	AddTestCase( "IsRegistered_False", &ComponentManagerTests::IsRegistered_False, this );
	AddTestCase( "CreateComponent_Succeed", &ComponentManagerTests::CreateComponent_Succeed, this );
	AddTestCase( "CreateComponent_DuplicateId_Fail", &ComponentManagerTests::CreateComponent_DuplicateId_Fail, this );
	AddTestCase( "CreateComponent_UnregisteredComponent_Fail", &ComponentManagerTests::CreateComponent_UnregisteredComponent_Fail, this );
	AddTestCase( "CreateComponent_WithData_Succeed", &ComponentManagerTests::CreateComponent_WithData_Succeed, this );
	AddTestCase( "CreateComponent_WithData_DuplicateId_Fail", &ComponentManagerTests::CreateComponent_WithData_DuplicateId_Fail, this );
	AddTestCase( "CreateComponent_WithData_UnregisteredComponent_Fail", &ComponentManagerTests::CreateComponent_WithData_UnregisteredComponent_Fail, this );
	AddTestCase( "HasComponent_True", &ComponentManagerTests::HasComponent_True, this );
	AddTestCase( "HasComponent_Fail", &ComponentManagerTests::HasComponent_Fail, this );
	AddTestCase( "HasComponent_UnregisteredComponent_Fail", &ComponentManagerTests::HasComponent_UnregisteredComponent_Fail, this );
	AddTestCase( "GetComponentNonConst_Succeed", &ComponentManagerTests::GetComponentNonConst_Succeed, this );
	AddTestCase( "GetComponentNonConst_InvalidId_Fail", &ComponentManagerTests::GetComponentNonConst_InvalidId_Fail, this );
	AddTestCase( "GetComponentNonConst_UnregisteredComponent_Fail", &ComponentManagerTests::GetComponentNonConst_UnregisteredComponent_Fail, this );
	AddTestCase( "GetComponentConst_Succeed", &ComponentManagerTests::GetComponentConst_Succeed, this );
	AddTestCase( "GetComponentConst_InvalidId_Fail", &ComponentManagerTests::GetComponentConst_InvalidId_Fail, this );
	AddTestCase( "GetComponentConst_UnregisteredComponent_Fail", &ComponentManagerTests::GetComponentConst_UnregisteredComponent_Fail, this );
	AddTestCase( "DestroyComponent_Succeed", &ComponentManagerTests::DestroyComponent_Succeed, this );
	AddTestCase( "DestroyComponent_InvalidId_Fail", &ComponentManagerTests::DestroyComponent_InvalidId_Fail, this );
	AddTestCase( "DestroyComponent_UnregisteredComponent_Fail", &ComponentManagerTests::DestroyComponent_UnregisteredComponent_Fail, this );
}

void ComponentManagerTests::RegisterComponent_Succeed( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;
	
	cm.RegisterComponent<MockComponentType1>();

	// Nothing thrown
}

void ComponentManagerTests::RegisterComponent_Duplicate_Fail( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;
	
	cm.RegisterComponent<MockComponentType1>();

	bool caught_exception = false;

	try
	{
		cm.RegisterComponent<MockComponentType1>();
	}
	catch ( const InvalidComponentIdException& )
	{
		caught_exception = true;
	}

	test_case.Assert( caught_exception );
}

void ComponentManagerTests::IsRegistered_True( Fnd::Test::TestCase& test_case )
{	
	ComponentManager cm;
	
	cm.RegisterComponent<MockComponentType1>();

	test_case.Assert(cm.IsRegistered<MockComponentType1>());
}

void ComponentManagerTests::IsRegistered_False( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;
	
	cm.RegisterComponent<MockComponentType2>();

	test_case.Assert(!cm.IsRegistered<MockComponentType1>());
}

void ComponentManagerTests::CreateComponent_Succeed( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;

	cm.RegisterComponent<MockComponentType1>();

	ComponentTemplate<MockComponentType1>& component = cm.CreateComponent<MockComponentType1>(123);

	test_case.Assert(component.GetComponentId() == MockComponentType1::Id);
	test_case.Assert(component.GetEntityId() == 123);
}

void ComponentManagerTests::CreateComponent_DuplicateId_Fail( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;

	cm.RegisterComponent<MockComponentType1>();

	cm.CreateComponent<MockComponentType1>(123);

	bool exception_caught = false;
	try
	{
		cm.CreateComponent<MockComponentType1>(123);
	}
	catch (const InvalidEntityIdException&)
	{
		exception_caught = true;
	}

	test_case.Assert(exception_caught);
}

void ComponentManagerTests::CreateComponent_UnregisteredComponent_Fail( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;
	
	bool exception_caught = false;
	try
	{
		cm.CreateComponent<MockComponentType1>(123);
	}
	catch (const InvalidComponentIdException&)
	{
		exception_caught = true;
	}

	test_case.Assert(exception_caught);
}

void ComponentManagerTests::CreateComponent_WithData_Succeed( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;

	cm.RegisterComponent<MockComponentType1>();

	MockComponentType1::Data data;
	data.some_int = 999;
	data.some_string = "some_string";

	ComponentTemplate<MockComponentType1>& component = cm.CreateComponent<MockComponentType1>(123,data);

	test_case.Assert(component.GetComponentId() == MockComponentType1::Id);
	test_case.Assert(component.GetEntityId() == 123);
	test_case.Assert(component->some_int == 999);
	test_case.Assert(component->some_string == "some_string");
}

void ComponentManagerTests::CreateComponent_WithData_DuplicateId_Fail( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;

	cm.RegisterComponent<MockComponentType1>();

	MockComponentType1::Data data;

	cm.CreateComponent<MockComponentType1>(123, data);

	bool exception_caught = false;
	try
	{
		cm.CreateComponent<MockComponentType1>(123);
	}
	catch (const InvalidEntityIdException&)
	{
		exception_caught = true;
	}

	test_case.Assert(exception_caught);
}

void ComponentManagerTests::CreateComponent_WithData_UnregisteredComponent_Fail( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;

	MockComponentType1::Data data;
	
	bool exception_caught = false;
	try
	{
		cm.CreateComponent<MockComponentType1>(123,data);
	}
	catch (const InvalidComponentIdException&)
	{
		exception_caught = true;
	}

	test_case.Assert(exception_caught);
}

void ComponentManagerTests::HasComponent_True( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;

	cm.RegisterComponent<MockComponentType1>();

	cm.CreateComponent<MockComponentType1>(123);

	test_case.Assert(cm.HasComponent<MockComponentType1>(123));
}

void ComponentManagerTests::HasComponent_Fail( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;

	cm.RegisterComponent<MockComponentType1>();

	test_case.Assert(!cm.HasComponent<MockComponentType1>(123));
}

void ComponentManagerTests::HasComponent_UnregisteredComponent_Fail( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;
		
	bool exception_caught = false;
	try
	{
		cm.HasComponent<MockComponentType1>(123);
	}
	catch (const InvalidComponentIdException&)
	{
		exception_caught = true;
	}

	test_case.Assert(exception_caught);
}

void ComponentManagerTests::GetComponentNonConst_Succeed( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;

	cm.RegisterComponent<MockComponentType1>();

	MockComponentType1::Data data;
	data.some_int = 999;
	data.some_string = "some_string";

	ComponentTemplate<MockComponentType1>& created = cm.CreateComponent<MockComponentType1>(123,data);

	ComponentTemplate<MockComponentType1>& got = cm.GetComponent<MockComponentType1>(123);

	test_case.Assert(created.GetComponentId() == got.GetComponentId());
	test_case.Assert(created.GetEntityId() == got.GetEntityId());
	test_case.Assert(created->some_int == got->some_int);
	test_case.Assert(created->some_string == got->some_string);
}

void ComponentManagerTests::GetComponentNonConst_InvalidId_Fail( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;

	cm.RegisterComponent<MockComponentType1>();
	
	cm.CreateComponent<MockComponentType1>(123);

	bool exception_caught = false;
	try
	{
		cm.GetComponent<MockComponentType1>(999);
	}
	catch (const InvalidEntityIdException&)
	{
		exception_caught = true;
	}

	test_case.Assert(exception_caught);
}

void ComponentManagerTests::GetComponentNonConst_UnregisteredComponent_Fail( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;

	cm.RegisterComponent<MockComponentType1>();
	
	cm.CreateComponent<MockComponentType1>(123);

	bool exception_caught = false;
	try
	{
		cm.GetComponent<MockComponentType2>(123);
	}
	catch (const InvalidComponentIdException&)
	{
		exception_caught = true;
	}

	test_case.Assert(exception_caught);
}

void ComponentManagerTests::GetComponentConst_Succeed( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;

	cm.RegisterComponent<MockComponentType1>();

	MockComponentType1::Data data;
	data.some_int = 999;
	data.some_string = "some_string";

	ComponentTemplate<MockComponentType1>& created = cm.CreateComponent<MockComponentType1>(123,data);

	const ComponentManager& cm_const = cm;
	const ComponentTemplate<MockComponentType1>& got = cm_const.GetComponent<MockComponentType1>(123);

	test_case.Assert(created.GetComponentId() == got.GetComponentId());
	test_case.Assert(created.GetEntityId() == got.GetEntityId());
	test_case.Assert(created->some_int == got->some_int);
	test_case.Assert(created->some_string == got->some_string);
}

void ComponentManagerTests::GetComponentConst_InvalidId_Fail( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;

	cm.RegisterComponent<MockComponentType1>();
	
	cm.CreateComponent<MockComponentType1>(123);

	bool exception_caught = false;
	try
	{
		const ComponentManager& cm_const = cm;
		cm_const.GetComponent<MockComponentType1>(999);
	}
	catch (const InvalidEntityIdException&)
	{
		exception_caught = true;
	}

	test_case.Assert(exception_caught);
}

void ComponentManagerTests::GetComponentConst_UnregisteredComponent_Fail( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;

	cm.RegisterComponent<MockComponentType1>();
	
	cm.CreateComponent<MockComponentType1>(123);

	bool exception_caught = false;
	try
	{
		const ComponentManager& cm_const = cm;
		cm_const.GetComponent<MockComponentType2>(123);
	}
	catch (const InvalidComponentIdException&)
	{
		exception_caught = true;
	}

	test_case.Assert(exception_caught);
}

void ComponentManagerTests::DestroyComponent_Succeed( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;

	cm.RegisterComponent<MockComponentType1>();

	cm.CreateComponent<MockComponentType1>(123);
	
	cm.DestroyComponent<MockComponentType1>(123);

	test_case.Assert(!cm.HasComponent<MockComponentType1>(123));
}

void ComponentManagerTests::DestroyComponent_InvalidId_Fail( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;

	cm.RegisterComponent<MockComponentType1>();
		
	bool exception_caught = false;
	try
	{
		cm.DestroyComponent<MockComponentType1>(123);
	}
	catch (const InvalidEntityIdException&)
	{
		exception_caught = true;
	}

	test_case.Assert(exception_caught);
}

void ComponentManagerTests::DestroyComponent_UnregisteredComponent_Fail( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;

	cm.RegisterComponent<MockComponentType1>();
		
	bool exception_caught = false;
	try
	{
		cm.DestroyComponent<MockComponentType2>(123);
	}
	catch (const InvalidComponentIdException&)
	{
		exception_caught = true;
	}

	test_case.Assert(exception_caught);
}