#include "SystemGraphNodeTests.hpp"

#include "../../Code/SystemManager/SystemGraphNode.hpp"

using namespace Fnd::Test;
using namespace Fnd::Test::SystemManager;
using namespace Fnd::SystemManager;

SystemGraphNodeTests::SystemGraphNodeTests():
	TestClass("SystemGraphNodeTests")
{
	AddTestCase( "SetAndGetId", &SystemGraphNodeTests::SetAndGetId, this );
	AddTestCase( "GetWeightDefault", &SystemGraphNodeTests::GetWeightDefault, this );
	AddTestCase( "SetAndGetWeight", &SystemGraphNodeTests::SetAndGetWeight, this );
	AddTestCase( "AddPrev", &SystemGraphNodeTests::AddPrev, this );
	AddTestCase( "AddPrev_Duplicate", &SystemGraphNodeTests::AddPrev_Duplicate, this );
	AddTestCase( "AddNext", &SystemGraphNodeTests::AddNext, this );
	AddTestCase( "AddNext_Duplicate", &SystemGraphNodeTests::AddNext_Duplicate, this );
	AddTestCase( "RemovePrev", &SystemGraphNodeTests::RemovePrev, this );
	AddTestCase( "RemovePrev_NonExisting", &SystemGraphNodeTests::RemovePrev_NonExisting, this );
	AddTestCase( "RemoveNext", &SystemGraphNodeTests::RemoveNext, this );
	AddTestCase( "RemoveNext_NonExisting", &SystemGraphNodeTests::RemoveNext_NonExisting, this );
	AddTestCase( "ClearPrev", &SystemGraphNodeTests::ClearPrev, this );
	AddTestCase( "ClearNext", &SystemGraphNodeTests::ClearNext, this );
	AddTestCase( "HasPrev", &SystemGraphNodeTests::HasPrev, this );
	AddTestCase( "HasNext", &SystemGraphNodeTests::HasNext, this );
	AddTestCase( "ContainsPrev", &SystemGraphNodeTests::ContainsPrev, this );
	AddTestCase( "ContainsNext", &SystemGraphNodeTests::ContainsNext, this );
}

void SystemGraphNodeTests::SetAndGetId( TestCase& test_case )
{
	const SystemId id = 123;
	SystemGraphNode node(id);
	
	test_case.Assert( node.GetId() == id );
}

void SystemGraphNodeTests::GetWeightDefault( TestCase& test_case )
{
	SystemGraphNode::Weight default_weight = 1;
	
	SystemGraphNode node(123);
	
	test_case.Assert( node.GetWeight() == default_weight );
}

void SystemGraphNodeTests::SetAndGetWeight( TestCase& test_case )
{
	SystemGraphNode::Weight weight = 100;
	
	SystemGraphNode node(123);
	
	node.SetWeight( weight );
	
	test_case.Assert( node.GetWeight() == weight );
}

void SystemGraphNodeTests::AddPrev( TestCase& test_case )
{
	SystemId prev1 = 1;
	SystemId prev2 = 2;
	
	SystemGraphNode node(0);
	
	node.AddPrev( prev1 );
	
	test_case.Assert( node.GetPrev().size() == 1 );
	test_case.Assert( node.ContainsPrev( prev1 ) );
	test_case.Assert( node.HasPrev() );
	
	node.AddPrev( prev2 );
	
	test_case.Assert( node.GetPrev().size() == 2 );
	test_case.Assert( node.ContainsPrev( prev2 ) );
	test_case.Assert( node.HasPrev() );
}

void SystemGraphNodeTests::AddPrev_Duplicate( TestCase& test_case )
{
	SystemId prev1 = 1;
	SystemId prev2 = 1;
	
	SystemGraphNode node(0);
	
	node.AddPrev( prev1 );
	
	test_case.Assert( node.GetPrev().size() == 1 );
	test_case.Assert( node.ContainsPrev( prev1 ) );
	
	node.AddPrev( prev2 );
	
	test_case.Assert( node.GetPrev().size() == 1 );
	test_case.Assert( node.ContainsPrev( prev2 ) );
}

void SystemGraphNodeTests::AddNext( TestCase& test_case )
{
	SystemId next1= 1;
	SystemId next2 = 2;
	
	SystemGraphNode node(0);
	
	node.AddNext( next1 );
	
	test_case.Assert( node.GetNext().size() == 1 );
	test_case.Assert( node.ContainsNext( next1 ) );
	test_case.Assert( node.HasNext() );
	
	node.AddNext( next2 );
	
	test_case.Assert( node.GetNext().size() == 2 );
	test_case.Assert( node.ContainsNext( next2 ) );
	test_case.Assert( node.HasNext() );
}

void SystemGraphNodeTests::AddNext_Duplicate( TestCase& test_case )
{
	SystemId next1= 1;
	SystemId next2 = 1;
	
	SystemGraphNode node(0);
	
	node.AddNext( next1 );
	
	test_case.Assert( node.GetNext().size() == 1 );
	test_case.Assert( node.ContainsNext( next1 ) );
	
	node.AddNext( next2 );
	
	test_case.Assert( node.GetNext().size() == 1 );
	test_case.Assert( node.ContainsNext( next2 ) );
}

void SystemGraphNodeTests::RemovePrev( TestCase& test_case )
{
	SystemId prev1 = 1;
	SystemId prev2 = 2;
	
	SystemGraphNode node(0);
	
	node.AddPrev( prev1 );
	node.AddPrev( prev2 );
	
	test_case.Assert( node.GetPrev().size() == 2 );
	test_case.Assert( node.ContainsPrev( prev1 ) );
	test_case.Assert( node.ContainsPrev( prev2 ) );
	
	node.RemovePrev( prev1 );
	
	test_case.Assert( node.GetPrev().size() == 1 );
	test_case.Assert( !node.ContainsPrev( prev1 ) );
	test_case.Assert( node.ContainsPrev( prev2 ) );
	
	node.RemovePrev( prev2 );
	
	test_case.Assert( node.GetPrev().size() == 0 );
	test_case.Assert( !node.ContainsPrev( prev1 ) );
	test_case.Assert( !node.ContainsPrev( prev2 ) );
	test_case.Assert( !node.HasPrev() );
}

void SystemGraphNodeTests::RemovePrev_NonExisting( TestCase& test_case )
{
	SystemId prev1 = 1;
	SystemId prev2 = 2;
	
	SystemGraphNode node(0);
	
	node.AddPrev( prev1 );
	
	test_case.Assert( node.GetPrev().size() == 1 );
	test_case.Assert( node.ContainsPrev( prev1 ) );
	test_case.Assert( !node.ContainsPrev( prev2 ) );
	
	node.RemovePrev( prev2 );
	
	test_case.Assert( node.GetPrev().size() == 1 );
	test_case.Assert( node.ContainsPrev( prev1 ) );
	test_case.Assert( !node.ContainsPrev( prev2 ) );
}

void SystemGraphNodeTests::RemoveNext( TestCase& test_case )
{
	SystemId next1= 1;
	SystemId next2 = 2;
	
	SystemGraphNode node(0);
	
	node.AddNext( next1 );
	node.AddNext( next2 );
	
	test_case.Assert( node.GetNext().size() == 2 );
	test_case.Assert( node.ContainsNext( next1 ) );
	test_case.Assert( node.ContainsNext( next2 ) );
	
	node.RemoveNext( next1 );
	
	test_case.Assert( node.GetNext().size() == 1 );
	test_case.Assert( !node.ContainsNext( next1 ) );
	test_case.Assert( node.ContainsNext( next2 ) );
	
	node.RemoveNext( next2 );
	
	test_case.Assert( node.GetNext().size() == 0 );
	test_case.Assert( !node.ContainsNext( next1 ) );
	test_case.Assert( !node.ContainsNext( next2 ) );
	test_case.Assert( !node.HasNext() );
}

void SystemGraphNodeTests::RemoveNext_NonExisting( TestCase& test_case )
{
	SystemId next1 = 1;
	SystemId next2 = 2;
	
	SystemGraphNode node(123);
	
	node.AddNext( next1 );
	
	test_case.Assert( node.GetNext().size() == 1 );
	test_case.Assert( node.ContainsNext( next1 ) );
	test_case.Assert( !node.ContainsNext( next2 ) );
	
	node.RemoveNext( next2 );
	
	test_case.Assert( node.GetNext().size() == 1 );
	test_case.Assert( node.ContainsNext( next1 ) );
	test_case.Assert( !node.ContainsNext( next2 ) );
}

void SystemGraphNodeTests::ClearPrev( TestCase& test_case )
{
	SystemId prev1 = 1;
	SystemId prev2 = 2;
	
	SystemGraphNode node(0);
	
	node.AddPrev( prev1 );
	node.AddPrev( prev2 );
	
	test_case.Assert( node.GetPrev().size() == 2 );
	test_case.Assert( node.ContainsPrev( prev1 ) );
	test_case.Assert( node.ContainsPrev( prev2 ) );
	
	node.ClearPrev();
	
	test_case.Assert( node.GetPrev().size() == 0 );
	test_case.Assert( !node.ContainsPrev( prev1 ) );
	test_case.Assert( !node.ContainsPrev( prev2 ) );
	test_case.Assert( !node.HasPrev() );
}

void SystemGraphNodeTests::ClearNext( TestCase& test_case )
{
	SystemId next1 = 1;
	SystemId next2 = 2;
	
	SystemGraphNode node(0);
	
	node.AddNext( next1 );
	node.AddNext( next2 );
	
	test_case.Assert( node.GetNext().size() == 2 );
	test_case.Assert( node.ContainsNext( next1 ) );
	test_case.Assert( node.ContainsNext( next2 ) );
	
	node.ClearNext();
	
	test_case.Assert( node.GetNext().size() == 0 );
	test_case.Assert( !node.ContainsNext( next1 ) );
	test_case.Assert( !node.ContainsNext( next2 ) );
	test_case.Assert( !node.HasNext() );
}

void SystemGraphNodeTests::HasPrev( TestCase& test_case )
{
	SystemId prev1 = 1;
	SystemId prev2 = 2;
	
	SystemGraphNode node(0);
	
	node.AddPrev( prev1 );
	
	test_case.Assert( node.HasPrev() );
	
	node.AddPrev( prev2 );
	
	test_case.Assert( node.HasPrev() );
}

void SystemGraphNodeTests::HasNext( TestCase& test_case )
{
	SystemId next1 = 1;
	SystemId next2 = 2;
	
	SystemGraphNode node(0);
	
	node.AddNext( next1 );
	
	test_case.Assert( node.HasNext() );
	
	node.AddNext( next2 );
	
	test_case.Assert( node.HasNext() );
}

void SystemGraphNodeTests::ContainsPrev( TestCase& test_case )
{
	SystemId prev1 = 1;
	SystemId prev2 = 2;
	
	SystemGraphNode node(0);
	
	node.AddPrev( prev1 );
	
	test_case.Assert( node.ContainsPrev( prev1 ) );
	test_case.Assert( !node.ContainsPrev( prev2 ) );
	
	node.AddPrev( prev2 );
	
	test_case.Assert( node.ContainsPrev( prev1 ) );
	test_case.Assert( node.ContainsPrev( prev2 ) );
}

void SystemGraphNodeTests::ContainsNext( TestCase& test_case )
{
	SystemId next1 = 1;
	SystemId next2 = 2;
	
	SystemGraphNode node(0);
	
	node.AddNext( next1 );
	
	test_case.Assert( node.ContainsNext( next1 ) );
	test_case.Assert( !node.ContainsNext( next2 ) );
	
	node.AddNext( next2 );
	
	test_case.Assert( node.ContainsNext( next1 ) );
	test_case.Assert( node.ContainsNext( next2 ) );
}
