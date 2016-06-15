#include "NodeManagerTests.hpp"

#include "../../Code/EntitySystem/NodeManager.hpp"

#include "MockNodeTypes.hpp"

using namespace Fnd::Test::EntitySystem;
using namespace Fnd::EntitySystem;


NodeManagerTests::NodeManagerTests():
	TestClass("NodeManagerTests")
{
	AddTestCase( "RegisterNode_Succeed", &NodeManagerTests::RegisterNode_Succeed, this );
	AddTestCase( "RegisterNode_Duplicate_Fail", &NodeManagerTests::RegisterNode_Duplicate_Fail, this );
	AddTestCase( "IsRegistered_True", &NodeManagerTests::IsRegistered_True, this );
	AddTestCase( "IsRegistered_False", &NodeManagerTests::IsRegistered_False, this );
	AddTestCase( "CreateNode_Succeed", &NodeManagerTests::CreateNode_Succeed, this );
	AddTestCase( "CreateNode_DuplicateId_Fail", &NodeManagerTests::CreateNode_DuplicateId_Fail, this );
	AddTestCase( "CreateNode_UnregisteredNode_Fail", &NodeManagerTests::CreateNode_UnregisteredNode_Fail, this );
	AddTestCase( "HasNode_True", &NodeManagerTests::HasNode_True, this );
	AddTestCase( "HasNode_False", &NodeManagerTests::HasNode_False, this );
	AddTestCase( "HasNode_UnregisteredNode_Fail", &NodeManagerTests::HasNode_UnregisteredNode_Fail, this );
	AddTestCase( "GetNodeNonConst_Succeed", &NodeManagerTests::GetNodeNonConst_Succeed, this );
	AddTestCase( "GetNodeNonConst_InvalidId_Fail", &NodeManagerTests::GetNodeNonConst_InvalidId_Fail, this );
	AddTestCase( "GetNodeNonConst_UnregisteredNode_Fail", &NodeManagerTests::GetNodeNonConst_UnregisteredNode_Fail, this );
	AddTestCase( "GetNodeConst_Succeed", &NodeManagerTests::GetNodeConst_Succeed, this );
	AddTestCase( "GetNodeConst_InvalidId_Fail", &NodeManagerTests::GetNodeConst_InvalidId_Fail, this );
	AddTestCase( "GetNodeConst_UnregisteredNode_Fail", &NodeManagerTests::GetNodeConst_UnregisteredNode_Fail, this );
	AddTestCase( "DestroyNode_Succeed", &NodeManagerTests::DestroyNode_Succeed, this );
	AddTestCase( "DestroyNode_InvalidId_Fail", &NodeManagerTests::DestroyNode_InvalidId_Fail, this );
	AddTestCase( "DestroyNode_UnregisteredNode_Fail", &NodeManagerTests::DestroyNode_UnregisteredNode_Fail, this );
	AddTestCase( "ForEachNodeNonConst_NoNodes_Success", &NodeManagerTests::ForEachNodeNonConst_NoNodes_Success, this );
	AddTestCase( "ForEachNodeNonConst_MultipleNodes_Success", &NodeManagerTests::ForEachNodeNonConst_MultipleNodes_Success, this );
	AddTestCase( "ForEachNodeNonConst_UnregisteredNode_Fail", &NodeManagerTests::ForEachNodeNonConst_UnregisteredNode_Fail, this );
	AddTestCase( "ForEachNodeConst_NoNodes_Success", &NodeManagerTests::ForEachNodeConst_NoNodes_Success, this );
	AddTestCase( "ForEachNodeConst_MultipleNodes_Success", &NodeManagerTests::ForEachNodeConst_MultipleNodes_Success, this );
	AddTestCase( "ForEachNodeConst_UnregisteredNode_Fail", &NodeManagerTests::ForEachNodeConst_UnregisteredNode_Fail, this );
}

void NodeManagerTests::RegisterNode_Succeed( Fnd::Test::TestCase& test_case )
{
	NodeManager nm;
	
	nm.RegisterNode<MockNodeType1>();
}

void NodeManagerTests::RegisterNode_Duplicate_Fail( Fnd::Test::TestCase& test_case )
{
	NodeManager nm;
	
	nm.RegisterNode<MockNodeType1>();

	bool caught_exception = false;
	try
	{
		nm.RegisterNode<MockNodeType1>();
	}
	catch (const InvalidNodeIdException&)
	{
		caught_exception = true;
	}
	test_case.Assert(caught_exception);
}

void NodeManagerTests::IsRegistered_True( Fnd::Test::TestCase& test_case )
{
	NodeManager nm;
	
	nm.RegisterNode<MockNodeType1>();
	
	test_case.Assert(nm.IsRegistered<MockNodeType1>());
}

void NodeManagerTests::IsRegistered_False( Fnd::Test::TestCase& test_case )
{
	NodeManager nm;
	
	test_case.Assert(!nm.IsRegistered<MockNodeType1>());
}

void NodeManagerTests::CreateNode_Succeed( Fnd::Test::TestCase& test_case )
{
	NodeManager nm;
	
	nm.RegisterNode<MockNodeType1>();
	
	NodeTemplate<MockNodeType1>& node = nm.CreateNode<MockNodeType1>(123);
	
	test_case.Assert(node.GetNodeId() == MockNodeType1::Id);
	test_case.Assert(node.GetEntityId() == 123);
}

void NodeManagerTests::CreateNode_DuplicateId_Fail( Fnd::Test::TestCase& test_case )
{
	NodeManager nm;
	
	nm.RegisterNode<MockNodeType1>();
	
	nm.CreateNode<MockNodeType1>(123);
	
	bool exception_caught = false;
	try
	{
		nm.CreateNode<MockNodeType1>(123);
	}
	catch (const InvalidEntityIdException&)
	{
		exception_caught = true;
	}
	
	test_case.Assert(exception_caught);
}

void NodeManagerTests::CreateNode_UnregisteredNode_Fail( Fnd::Test::TestCase& test_case )
{
	NodeManager nm;
	
	bool exception_caught = false;
	try
	{
		nm.CreateNode<MockNodeType1>(123);
	}
	catch (const InvalidNodeIdException&)
	{
		exception_caught = true;
	}
	test_case.Assert(exception_caught);
}

void NodeManagerTests::HasNode_True( Fnd::Test::TestCase& test_case )
{
	NodeManager nm;
	
	nm.RegisterNode<MockNodeType1>();
	
	nm.CreateNode<MockNodeType1>(123);
	
	test_case.Assert(nm.HasNode<MockNodeType1>(123));
}

void NodeManagerTests::HasNode_False( Fnd::Test::TestCase& test_case )
{
	NodeManager nm;
	
	nm.RegisterNode<MockNodeType1>();
	
	test_case.Assert(!nm.HasNode<MockNodeType1>(123));
}

void NodeManagerTests::HasNode_UnregisteredNode_Fail( Fnd::Test::TestCase& test_case )
{
	NodeManager nm;
	
	bool exception_caught = false;
	try
	{
		nm.HasNode<MockNodeType1>(123);
	}
	catch (const InvalidNodeIdException&)
	{
		exception_caught = true;
	}
	test_case.Assert(exception_caught);
}

void NodeManagerTests::GetNodeNonConst_Succeed( Fnd::Test::TestCase& test_case )
{
	NodeManager nm;
	
	nm.RegisterNode<MockNodeType1>();
	
	NodeTemplate<MockNodeType1>& created = nm.CreateNode<MockNodeType1>(123);
	
	NodeTemplate<MockNodeType1>& got = nm.GetNode<MockNodeType1>(123);
	
	test_case.Assert(got.GetNodeId() == created.GetNodeId());
	test_case.Assert(got.GetEntityId() == created.GetEntityId());
	test_case.Assert(&got == &created);
}

void NodeManagerTests::GetNodeNonConst_InvalidId_Fail( Fnd::Test::TestCase& test_case )
{
	NodeManager nm;
	
	nm.RegisterNode<MockNodeType1>();
	
	bool exception_caught = false;
	try
	{
		nm.GetNode<MockNodeType1>(123);
	}
	catch (const InvalidEntityIdException&)
	{
		exception_caught = true;
	}
	test_case.Assert(exception_caught);
}

void NodeManagerTests::GetNodeNonConst_UnregisteredNode_Fail( Fnd::Test::TestCase& test_case )
{
	NodeManager nm;
	
	bool exception_caught = false;
	try
	{
		nm.GetNode<MockNodeType1>(123);
	}
	catch (const InvalidNodeIdException&)
	{
		exception_caught = true;
	}
	test_case.Assert(exception_caught);
}

void NodeManagerTests::GetNodeConst_Succeed( Fnd::Test::TestCase& test_case )
{
	NodeManager nm;
	
	nm.RegisterNode<MockNodeType1>();
	
	NodeTemplate<MockNodeType1>& created = nm.CreateNode<MockNodeType1>(123);
	
	const NodeManager& nm_c = nm;
	
	const NodeTemplate<MockNodeType1>& got = nm_c.GetNode<MockNodeType1>(123);
	
	test_case.Assert(got.GetNodeId() == created.GetNodeId());
	test_case.Assert(got.GetEntityId() == created.GetEntityId());
	test_case.Assert(&got == &created);
}

void NodeManagerTests::GetNodeConst_InvalidId_Fail( Fnd::Test::TestCase& test_case )
{
	NodeManager nm;
	
	nm.RegisterNode<MockNodeType1>();
	
	const NodeManager& nm_c = nm;
	
	bool exception_caught = false;
	try
	{
		nm_c.GetNode<MockNodeType1>(123);
	}
	catch (const InvalidEntityIdException&)
	{
		exception_caught = true;
	}
	test_case.Assert(exception_caught);
}

void NodeManagerTests::GetNodeConst_UnregisteredNode_Fail( Fnd::Test::TestCase& test_case )
{
	NodeManager nm;
	
	const NodeManager& nm_c = nm;
	
	bool exception_caught = false;
	try
	{
		nm_c.GetNode<MockNodeType1>(123);
	}
	catch (const InvalidNodeIdException&)
	{
		exception_caught = true;
	}
	test_case.Assert(exception_caught);
}

void NodeManagerTests::DestroyNode_Succeed( Fnd::Test::TestCase& test_case )
{
	NodeManager nm;
	
	nm.RegisterNode<MockNodeType1>();
	
	nm.CreateNode<MockNodeType1>(123);
	
	test_case.Assert(nm.HasNode<MockNodeType1>(123));
	
	nm.DestroyNode<MockNodeType1>(123);
	
	test_case.Assert(!nm.HasNode<MockNodeType1>(123));
}

void NodeManagerTests::DestroyNode_InvalidId_Fail( Fnd::Test::TestCase& test_case )
{
	NodeManager nm;
	
	nm.RegisterNode<MockNodeType1>();
	
	bool exception_caught = false;
	try
	{
		nm.DestroyNode<MockNodeType1>(123);
	}
	catch (const InvalidEntityIdException&)
	{
		exception_caught = true;
	}
	test_case.Assert(exception_caught);
}

void NodeManagerTests::DestroyNode_UnregisteredNode_Fail( Fnd::Test::TestCase& test_case )
{
	NodeManager nm;
	
	bool exception_caught = false;
	try
	{
		nm.DestroyNode<MockNodeType1>(123);
	}
	catch (const InvalidNodeIdException&)
	{
		exception_caught = true;
	}
	test_case.Assert(exception_caught);
}

void NodeManagerTests::ForEachNodeNonConst_NoNodes_Success(Fnd::Test::TestCase& test_case)
{
	NodeManager nm;
	
	nm.RegisterNode<MockNodeType1>();
	
	bool has_operated_on_node = false;
	nm.ForEachNode<MockNodeType1>([&](NodeTemplate<MockNodeType1>& node)
	{
		has_operated_on_node = true;
	} );
	
	test_case.Assert(!has_operated_on_node);
}

void NodeManagerTests::ForEachNodeNonConst_MultipleNodes_Success(Fnd::Test::TestCase& test_case)
{
	NodeManager nm;
	
	nm.RegisterNode<MockNodeType1>();
	
	NodeTemplate<MockNodeType1>& created0 = nm.CreateNode<MockNodeType1>(0);
	NodeTemplate<MockNodeType1>& created1 = nm.CreateNode<MockNodeType1>(1);
	NodeTemplate<MockNodeType1>& created2 = nm.CreateNode<MockNodeType1>(2);
	
	unsigned int hit_count[3] = { 0 };
	
	nm.ForEachNode<MockNodeType1>([&](NodeTemplate<MockNodeType1>& node)
	{
		switch (node.GetEntityId())
		{
			case 0:
			{
				test_case.Assert(&node == &created0);
				++(hit_count[0]);
				break;
			}
			case 1:
			{
				test_case.Assert(&node == &created1);
				++(hit_count[1]);
				break;
			}
			case 2:
			{
				test_case.Assert(&node == &created2);
				++(hit_count[2]);
				break;
			}
			default:
			{
				test_case.Assert(false, "Found a node which hasn't been added!");
			}
		}
	} );
	
	for (auto hits : hit_count)
	{
		test_case.Assert(hits == 1);
	}
}

void NodeManagerTests::ForEachNodeNonConst_UnregisteredNode_Fail(Fnd::Test::TestCase& test_case)
{
	NodeManager nm;
	
	bool has_operated_on_node = false;
	bool exception_caught = false;
	try
	{
		nm.ForEachNode<MockNodeType1>([&](NodeTemplate<MockNodeType1>& node)
		{
			has_operated_on_node = true;
		} );
	}
	catch (const InvalidNodeIdException&)
	{
		exception_caught = true;
	}
	
	test_case.Assert(!has_operated_on_node);
	test_case.Assert(exception_caught);
}

void NodeManagerTests::ForEachNodeConst_NoNodes_Success(Fnd::Test::TestCase& test_case)
{
	NodeManager nm;
	
	nm.RegisterNode<MockNodeType1>();
	
	const NodeManager& nm_c = nm;
	
	bool hasOperatedOnNode = false;
	nm_c.ForEachNode<MockNodeType1>([&](const NodeTemplate<MockNodeType1>& node)
	{
		hasOperatedOnNode = true;
	} );
	
	test_case.Assert(!hasOperatedOnNode);
}

void NodeManagerTests::ForEachNodeConst_MultipleNodes_Success(Fnd::Test::TestCase& test_case)
{
	NodeManager nm;
	
	nm.RegisterNode<MockNodeType1>();
	
	NodeTemplate<MockNodeType1>& created0 = nm.CreateNode<MockNodeType1>(0);
	NodeTemplate<MockNodeType1>& created1 = nm.CreateNode<MockNodeType1>(1);
	NodeTemplate<MockNodeType1>& created2 = nm.CreateNode<MockNodeType1>(2);
	
	const NodeManager& nm_c = nm;
	
	unsigned int hit_count[3] = { 0 };
	
	nm_c.ForEachNode<MockNodeType1>([&](const NodeTemplate<MockNodeType1>& node)
	{
		switch (node.GetEntityId())
		{
			case 0:
			{
				test_case.Assert(&node == &created0);
				++(hit_count[0]);
				break;
			}
			case 1:
			{
				test_case.Assert(&node == &created1);
				++(hit_count[1]);
				break;
			}
			case 2:
			{
				test_case.Assert(&node == &created2);
				++(hit_count[2]);
				break;
			}
			default:
			{
				test_case.Assert(false, "Found a node which hasn't been added!");
			}
		}
	} );
	
	for (auto hits : hit_count)
	{
		test_case.Assert(hits == 1);
	}
}

void NodeManagerTests::ForEachNodeConst_UnregisteredNode_Fail(Fnd::Test::TestCase& test_case)
{
	NodeManager nm;
	
	
	const NodeManager& nm_c = nm;
	
	bool has_operated_on_node = false;
	bool exception_caught = false;
	try
	{
		nm_c.ForEachNode<MockNodeType1>([&](const NodeTemplate<MockNodeType1>& node)
		{
			has_operated_on_node = true;
		} );
	}
	catch (const InvalidNodeIdException&)
	{
		exception_caught = true;
	}
	
	test_case.Assert(!has_operated_on_node);
	test_case.Assert(exception_caught);
}
