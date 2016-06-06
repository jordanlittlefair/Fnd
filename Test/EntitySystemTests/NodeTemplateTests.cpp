#include "NodeTemplateTests.hpp"

#include "../../Code/EntitySystem/ComponentManager.hpp"
#include "../../Code/EntitySystem/NodeTemplate.hpp"

#include "MockNodeTypes.hpp"

using namespace Fnd::EntitySystem;
using namespace Fnd::Test::EntitySystem;

NodeTemplateTests::NodeTemplateTests():
	TestClass("NodeTemplateTests")
{
	AddTestCase( "GetNodeId_Success", &NodeTemplateTests::GetNodeId_Success, this );
	AddTestCase( "GetEntityId_Success", &NodeTemplateTests::GetEntityId_Success, this );
	AddTestCase( "GetNodeNonConst_Success", &NodeTemplateTests::GetNodeNonConst_Success, this );
	AddTestCase( "GetNodeNonConst_NonExistingEntityId", &NodeTemplateTests::GetNodeNonConst_NonExistingEntityId, this );
	AddTestCase( "GetNodeNonConst_PartExistingEntityId", &NodeTemplateTests::GetNodeNonConst_PartExistingEntityId, this );
	AddTestCase( "GetNodeNonConst_UnregisteredComponent", &NodeTemplateTests::GetNodeNonConst_UnregisteredComponent, this );
	AddTestCase( "GetNodeNonConst_PartUnregisteredComponent", &NodeTemplateTests::GetNodeNonConst_PartUnregisteredComponent, this );
	AddTestCase( "GetNodeConst_Success", &NodeTemplateTests::GetNodeConst_Success, this );
	AddTestCase( "GetNodeConst_NonExistingEntityId", &NodeTemplateTests::GetNodeConst_NonExistingEntityId, this );
	AddTestCase( "GetNodeConst_PartExistingEntityId", &NodeTemplateTests::GetNodeConst_PartExistingEntityId, this );
	AddTestCase( "GetNodeConst_UnregisteredComponent", &NodeTemplateTests::GetNodeConst_UnregisteredComponent, this );
	AddTestCase( "GetNodeConst_PartUnregisteredComponent", &NodeTemplateTests::GetNodeConst_PartUnregisteredComponent, this );
}

void NodeTemplateTests::GetNodeId_Success( Fnd::Test::TestCase& test_case )
{
	NodeTemplate<MockNodeType1> node(123);
	
	test_case.Assert(node.GetNodeId() == MockNodeType1::Id);
}

void NodeTemplateTests::GetEntityId_Success( Fnd::Test::TestCase& test_case )
{
	NodeTemplate<MockNodeType1> node(123);
	
	test_case.Assert(node.GetEntityId() == 123);
}

void NodeTemplateTests::GetNodeNonConst_Success( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;
	
	cm.RegisterComponent<MockComponentType1>();
	
	MockComponentType1::Data data;
	data.some_int = 999;
	data.some_string = "999";
	
	ComponentTemplate<MockComponentType1> created = cm.CreateComponent<MockComponentType1>(123, data);
	
	
	NodeTemplate<MockNodeType1> node(123);
	
	MockNodeType1::Components got = node.GetComponents(cm);
	
	test_case.Assert(created->some_int == got.component1->some_int);
	test_case.Assert(created->some_string == got.component1->some_string);
}

void NodeTemplateTests::GetNodeNonConst_NonExistingEntityId( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;
	
	cm.RegisterComponent<MockComponentType1>();
	
	cm.CreateComponent<MockComponentType1>(123);
	
	
	NodeTemplate<MockNodeType1> node(999);
	
	bool caught_exception = false;
	try
	{
		node.GetComponents(cm);
	}
	catch (const InvalidEntityIdException&)
	{
		caught_exception = true;
	}
	test_case.Assert(caught_exception);
}

void NodeTemplateTests::GetNodeNonConst_PartExistingEntityId( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;
	
	cm.RegisterComponent<MockComponentType1>();
	cm.RegisterComponent<MockComponentType2>();
	
	cm.CreateComponent<MockComponentType1>(123);
	//cm.CreateComponent<MockComponentType2>(123); // This component doesn't exist
	
	
	NodeTemplate<MockNodeType2> node(123);
	
	bool caught_exception = false;
	try
	{
		node.GetComponents(cm);
	}
	catch (const InvalidEntityIdException&)
	{
		caught_exception = true;
	}
	test_case.Assert(caught_exception);
}

void NodeTemplateTests::GetNodeNonConst_UnregisteredComponent( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;
	
	// cm.RegisterComponent<MockComponentType1>();
	
	NodeTemplate<MockNodeType1> node(123);
	
	bool caught_exception = false;
	try
	{
		node.GetComponents(cm);
	}
	catch (const InvalidComponentIdException&)
	{
		caught_exception = true;
	}
	test_case.Assert(caught_exception);
}

void NodeTemplateTests::GetNodeNonConst_PartUnregisteredComponent( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;
	
	cm.RegisterComponent<MockComponentType1>();
	// cm.RegisterComponent<MockComponentType2>();
	
	cm.CreateComponent<MockComponentType1>(123);
	
	NodeTemplate<MockNodeType2> node(123);
	
	bool caught_exception = false;
	try
	{
		node.GetComponents(cm);
	}
	catch (const InvalidComponentIdException&)
	{
		caught_exception = true;
	}
	test_case.Assert(caught_exception);
}

void NodeTemplateTests::GetNodeConst_Success( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;
	
	cm.RegisterComponent<MockComponentType1>();
	
	MockComponentType1::Data data;
	data.some_int = 999;
	data.some_string = "999";
	
	ComponentTemplate<MockComponentType1> created = cm.CreateComponent<MockComponentType1>(123, data);
	
	
	const ComponentManager& cm_const = cm;
	
	NodeTemplate<MockNodeType1> node(123);
	
	MockNodeType1::ComponentsConst got = node.GetComponents(cm_const);
	
	test_case.Assert(created->some_int == got.component1->some_int);
	test_case.Assert(created->some_string == got.component1->some_string);
}

void NodeTemplateTests::GetNodeConst_NonExistingEntityId( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;
	
	cm.RegisterComponent<MockComponentType1>();
	
	cm.CreateComponent<MockComponentType1>(123);
	
	
	const ComponentManager& cm_const = cm;
	
	NodeTemplate<MockNodeType1> node(999);
	
	bool caught_exception = false;
	try
	{
		node.GetComponents(cm_const);
	}
	catch (const InvalidEntityIdException&)
	{
		caught_exception = true;
	}
	test_case.Assert(caught_exception);
}

void NodeTemplateTests::GetNodeConst_PartExistingEntityId( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;
	
	cm.RegisterComponent<MockComponentType1>();
	cm.RegisterComponent<MockComponentType2>();
	
	cm.CreateComponent<MockComponentType1>(123);
	//cm.CreateComponent<MockComponentType2>(123); // This component doesn't exist
	
	
	const ComponentManager& cm_const = cm;
	
	NodeTemplate<MockNodeType2> node(123);
	
	bool caught_exception = false;
	try
	{
		node.GetComponents(cm_const);
	}
	catch (const InvalidEntityIdException&)
	{
		caught_exception = true;
	}
	test_case.Assert(caught_exception);
}

void NodeTemplateTests::GetNodeConst_UnregisteredComponent( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;
	
	// cm.RegisterComponent<MockComponentType1>();
	
	NodeTemplate<MockNodeType1> node(123);
	
	
	const ComponentManager& cm_const = cm;
	
	bool caught_exception = false;
	try
	{
		node.GetComponents(cm_const);
	}
	catch (const InvalidComponentIdException&)
	{
		caught_exception = true;
	}
	test_case.Assert(caught_exception);
}

void NodeTemplateTests::GetNodeConst_PartUnregisteredComponent( Fnd::Test::TestCase& test_case )
{
	ComponentManager cm;
	
	cm.RegisterComponent<MockComponentType1>();
	// cm.RegisterComponent<MockComponentType2>();
	
	cm.CreateComponent<MockComponentType1>(123);
	
	NodeTemplate<MockNodeType2> node(123);
	
	
	const ComponentManager& cm_const = cm;
	
	bool caught_exception = false;
	try
	{
		node.GetComponents(cm_const);
	}
	catch (const InvalidComponentIdException&)
	{
		caught_exception = true;
	}
	test_case.Assert(caught_exception);
}
