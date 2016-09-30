#include "EntitySystemTests.hpp"

#include "MockEntityIdGenerator.hpp"

#include "../../Code/EntitySystem/EntitySystem.hpp"

using namespace Fnd::Test::EntitySystem;
using namespace Fnd::EntitySystem;

EntitySystemTests::EntitySystemTests():
	UnitTestClass("EntitySystemTests")
{
	AddTestCase( "GetEntityManagerNonConst", &EntitySystemTests::GetEntityManagerNonConst, this );
	AddTestCase( "GetEntityManagerConst", &EntitySystemTests::GetEntityManagerConst, this );
	AddTestCase( "GetComponentManagerNonConst", &EntitySystemTests::GetComponentManagerNonConst, this );
	AddTestCase( "GetComponentManagerConst", &EntitySystemTests::GetComponentManagerConst, this );
	AddTestCase( "GetNodeManagerNonConst", &EntitySystemTests::GetNodeManagerNonConst, this );
	AddTestCase( "GetNodeManagerConst", &EntitySystemTests::GetNodeManagerConst, this );
}

void EntitySystemTests::GetEntityManagerNonConst(Fnd::Test::TestCase& test_case)
{
	class EntitySystem es(std::make_shared<MockEntityIdGenerator>());
	
	es.GetEntityManager();
	
	// Doesn't throw
}

void EntitySystemTests::GetEntityManagerConst(Fnd::Test::TestCase& test_case)
{
	class EntitySystem es(std::make_shared<MockEntityIdGenerator>());
	
	const IEntitySystem& es_c = es;
	
	es_c.GetEntityManager();
	
	// Doesn't throw
}

void EntitySystemTests::GetComponentManagerNonConst(Fnd::Test::TestCase& test_case)
{
	class EntitySystem es(std::make_shared<MockEntityIdGenerator>());
	
	es.GetComponentManager();
	
	// Doesn't throw
}

void EntitySystemTests::GetComponentManagerConst(Fnd::Test::TestCase& test_case)
{
	class EntitySystem es(std::make_shared<MockEntityIdGenerator>());
	
	const IEntitySystem& es_c = es;
	
	es_c.GetComponentManager();
	
	// Doesn't throw
}

void EntitySystemTests::GetNodeManagerNonConst(Fnd::Test::TestCase& test_case)
{
	class EntitySystem es(std::make_shared<MockEntityIdGenerator>());
	
	es.GetNodeManager();
	
	// Doesn't throw
}

void EntitySystemTests::GetNodeManagerConst(Fnd::Test::TestCase& test_case)
{
	class EntitySystem es(std::make_shared<MockEntityIdGenerator>());
	
	const IEntitySystem& es_c = es;
	
	es_c.GetNodeManager();
	
	// Doesn't throw
}
