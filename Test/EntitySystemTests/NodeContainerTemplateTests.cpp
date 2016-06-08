#include "NodeContainerTemplateTests.hpp"

#include "MockNodeTypes.hpp"

#include "../../Code/EntitySystem/NodeContainerTemplate.hpp"

using namespace Fnd::Test::EntitySystem;
using namespace Fnd::EntitySystem;

using namespace Fnd::Test::EntitySystem;

NodeContainerTemplateTests::NodeContainerTemplateTests():
	TestClass("NodeContainerTemplateTests")
{
	AddTestCase( "GetNodeId_Success", &NodeContainerTemplateTests::GetNodeId_Success, this );
	AddTestCase( "CreateNode_Success", &NodeContainerTemplateTests::CreateNode_Success, this );
	AddTestCase( "CreateNode_Duplicate_Fail", &NodeContainerTemplateTests::CreateNode_Duplicate_Fail, this );
	AddTestCase( "HasNode_True", &NodeContainerTemplateTests::HasNode_True, this );
	AddTestCase( "HasNode_False", &NodeContainerTemplateTests::HasNode_False, this );
	AddTestCase( "GetNodeConst_Success", &NodeContainerTemplateTests::GetNodeConst_Success, this );
	AddTestCase( "GetNodeConst_NonExistingEntityId_Fail", &NodeContainerTemplateTests::GetNodeConst_NonExistingEntityId_Fail, this );
	AddTestCase( "GetNodeNonConst_Success", &NodeContainerTemplateTests::GetNodeNonConst_Success, this );
	AddTestCase( "GetNodeNonConst_NonExistingEntityId_Fail", &NodeContainerTemplateTests::GetNodeNonConst_NonExistingEntityId_Fail, this );
	AddTestCase( "DestroyNode_Success", &NodeContainerTemplateTests::DestroyNode_Success, this );
	AddTestCase( "DestroyNode_NonExistingEntityId", &NodeContainerTemplateTests::DestroyNode_NonExistingEntityId, this );
	AddTestCase( "Base_GetNodeConst_Success", &NodeContainerTemplateTests::Base_GetNodeConst_Success, this );
	AddTestCase( "Base_GetNodeConst_NonExistingEntityId_Fail", &NodeContainerTemplateTests::Base_GetNodeConst_NonExistingEntityId_Fail, this );
	AddTestCase( "Base_GetNodeNonConst_Success", &NodeContainerTemplateTests::Base_GetNodeNonConst_Success, this );
	AddTestCase( "Base_GetNodeNonConst_NonExistingEntityId_Fail", &NodeContainerTemplateTests::Base_GetNodeNonConst_NonExistingEntityId_Fail, this );
}

void NodeContainerTemplateTests::GetNodeId_Success(Fnd::Test::TestCase& test_case)
{
	NodeContainerTemplate<MockNodeType1> container;
	
	test_case.Assert(container.GetNodeId() == MockNodeType1::Id);
}

void NodeContainerTemplateTests::CreateNode_Success(Fnd::Test::TestCase& test_case)
{
	NodeContainerTemplate<MockNodeType1> container;

	NodeTemplate<MockNodeType1>& created = container.CreateNode(123);
	
	test_case.Assert(created.GetNodeId() == MockNodeType1::Id);
	test_case.Assert(created.GetEntityId() == 123);
}

void NodeContainerTemplateTests::CreateNode_Duplicate_Fail(Fnd::Test::TestCase& test_case)
{
	NodeContainerTemplate<MockNodeType1> container;
	
	container.CreateNode(123);
	
	bool caught_exception = false;
	try
	{
		container.CreateNode(123);
	}
	catch (const InvalidEntityIdException&)
	{
		caught_exception = true;
	}
	test_case.Assert(caught_exception);
}

void NodeContainerTemplateTests::HasNode_True(Fnd::Test::TestCase& test_case)
{
	NodeContainerTemplate<MockNodeType1> container;
	
	container.CreateNode(123);
	
	test_case.Assert(container.HasNode(123));
}

void NodeContainerTemplateTests::HasNode_False(Fnd::Test::TestCase& test_case)
{
	NodeContainerTemplate<MockNodeType1> container;
	
	container.CreateNode(123);
	
	test_case.Assert(!container.HasNode(999));
}

void NodeContainerTemplateTests::GetNodeConst_Success(Fnd::Test::TestCase& test_case)
{
	NodeContainerTemplate<MockNodeType1> container;
	
	NodeTemplate<MockNodeType1>& created = container.CreateNode(123);
	
	const NodeContainerTemplate<MockNodeType1>& container_c = container;
	
	const NodeTemplate<MockNodeType1>& got = container_c.GetNode(123);
	
	test_case.Assert(created.GetNodeId() == got.GetNodeId());
	test_case.Assert(created.GetEntityId() == got.GetEntityId());
	test_case.Assert(&created == &got);
}

void NodeContainerTemplateTests::GetNodeConst_NonExistingEntityId_Fail(Fnd::Test::TestCase& test_case)
{
	NodeContainerTemplate<MockNodeType1> container;
	
	container.CreateNode(123);
	
	const NodeContainerTemplate<MockNodeType1>& container_c = container;
	
	bool caught_exception = false;
	try
	{
		container_c.GetNode(999);
	}
	catch (const InvalidEntityIdException&)
	{
		caught_exception = true;
	}
	test_case.Assert(caught_exception);
}

void NodeContainerTemplateTests::GetNodeNonConst_Success(Fnd::Test::TestCase& test_case)
{
	NodeContainerTemplate<MockNodeType1> container;
	
	NodeTemplate<MockNodeType1>& created = container.CreateNode(123);
	
	NodeTemplate<MockNodeType1>& got = container.GetNode(123);
	
	test_case.Assert(created.GetNodeId() == got.GetNodeId());
	test_case.Assert(created.GetEntityId() == got.GetEntityId());
	test_case.Assert(&created == &got);
}

void NodeContainerTemplateTests::GetNodeNonConst_NonExistingEntityId_Fail(Fnd::Test::TestCase& test_case)
{
	NodeContainerTemplate<MockNodeType1> container;
	
	container.CreateNode(123);
	
	bool caught_exception = false;
	try
	{
		container.GetNode(999);
	}
	catch (const InvalidEntityIdException&)
	{
		caught_exception = true;
	}
	test_case.Assert(caught_exception);
}

void NodeContainerTemplateTests::DestroyNode_Success(Fnd::Test::TestCase& test_case)
{
	NodeContainerTemplate<MockNodeType1> container;
	
	container.CreateNode(123);
	
	test_case.Assert(container.HasNode(123));
	
	container.DestroyNode(123);
	
	test_case.Assert(!container.HasNode(123));
}

void NodeContainerTemplateTests::DestroyNode_NonExistingEntityId(Fnd::Test::TestCase& test_case)
{
	NodeContainerTemplate<MockNodeType1> container;
	
	container.CreateNode(123);
	
	bool caught_exception = false;
	try
	{
		container.DestroyNode(999);
	}
	catch (const InvalidEntityIdException&)
	{
		caught_exception = true;
	}
	test_case.Assert(caught_exception);
}

void NodeContainerTemplateTests::Base_GetNodeConst_Success(Fnd::Test::TestCase& test_case)
{
	NodeContainerTemplate<MockNodeType1> container;
	
	NodeTemplate<MockNodeType1>& created = container.CreateNode(123);
	
	const NodeContainer& base_c = container;
	
	const Node& got = base_c.GetNode(123);
	
	test_case.Assert(created.GetNodeId() == got.GetNodeId());
	test_case.Assert(created.GetEntityId() == got.GetEntityId());
	test_case.Assert(&created == &got);
}

void NodeContainerTemplateTests::Base_GetNodeConst_NonExistingEntityId_Fail(Fnd::Test::TestCase& test_case)
{
	NodeContainerTemplate<MockNodeType1> container;
	
	container.CreateNode(123);
	
	const NodeContainer& base_c = container;
	
	bool caught_exception = false;
	try
	{
		base_c.GetNode(999);
	}
	catch (const InvalidEntityIdException&)
	{
		caught_exception = true;
	}
	test_case.Assert(caught_exception);
}

void NodeContainerTemplateTests::Base_GetNodeNonConst_Success(Fnd::Test::TestCase& test_case)
{
	NodeContainerTemplate<MockNodeType1> container;
	
	NodeTemplate<MockNodeType1>& created = container.CreateNode(123);
	
	NodeContainer& base = container;
	
	Node& got = base.GetNode(123);
	
	test_case.Assert(created.GetNodeId() == got.GetNodeId());
	test_case.Assert(created.GetEntityId() == got.GetEntityId());
	test_case.Assert(&created == &got);
}

void NodeContainerTemplateTests::Base_GetNodeNonConst_NonExistingEntityId_Fail(Fnd::Test::TestCase& test_case)
{
	NodeContainerTemplate<MockNodeType1> container;
	
	container.CreateNode(123);
	
	NodeContainer& base = container;
	
	bool caught_exception = false;
	try
	{
		base.GetNode(999);
	}
	catch (const InvalidEntityIdException&)
	{
		caught_exception = true;
	}
	test_case.Assert(caught_exception);
}
