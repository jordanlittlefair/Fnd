#include "EntityManagerTests.hpp"

#include "MockEntityIdGenerator.hpp"
#include "../../Code/EntitySystem/EntityManager.hpp"

using namespace Fnd::EntitySystem;
using namespace Fnd::Test::EntitySystem;

EntityManagerTests::EntityManagerTests():
	UnitTestClass("EntityManagerTests")
{
	AddTestCase( "CreateEntity_Success", &EntityManagerTests::CreateEntity_Success, this );
	AddTestCase( "CreateEntity_Multiple_Success", &EntityManagerTests::CreateEntity_Multiple_Success, this );
	AddTestCase( "HasEntity_True", &EntityManagerTests::HasEntity_True, this );
	AddTestCase( "HasEntity_False", &EntityManagerTests::HasEntity_False, this );
	AddTestCase( "DestroyEntity_Success", &EntityManagerTests::DestroyEntity_Success, this );
	AddTestCase( "DestroyEntity_InvalidId_Fail", &EntityManagerTests::DestroyEntity_InvalidId_Fail, this );
}

void EntityManagerTests::CreateEntity_Success(Fnd::Test::TestCase& test_case)
{
	std::shared_ptr<MockEntityIdGenerator> id_generator = std::make_shared<MockEntityIdGenerator>();

	EntityManager em(id_generator);

	id_generator->SetNextId(123);

	EntityId created = em.CreateEntity();

	test_case.Assert( created == 123 );
}

void EntityManagerTests::CreateEntity_Multiple_Success(Fnd::Test::TestCase& test_case)
{
	std::shared_ptr<MockEntityIdGenerator> id_generator = std::make_shared<MockEntityIdGenerator>();

	EntityManager em(id_generator);

	id_generator->SetNextId(123);

	EntityId created0 = em.CreateEntity();

	id_generator->SetNextId(999);

	EntityId created1 = em.CreateEntity();

	test_case.Assert( created0 == 123 );
	test_case.Assert( created1 == 999 );
}

void EntityManagerTests::HasEntity_True(Fnd::Test::TestCase& test_case)
{
	std::shared_ptr<MockEntityIdGenerator> id_generator = std::make_shared<MockEntityIdGenerator>();

	EntityManager em(id_generator);

	id_generator->SetNextId(123);

	EntityId created = em.CreateEntity();

	test_case.Assert(em.HasEntity(123));
}

void EntityManagerTests::HasEntity_False(Fnd::Test::TestCase& test_case)
{
	std::shared_ptr<MockEntityIdGenerator> id_generator = std::make_shared<MockEntityIdGenerator>();

	EntityManager em(id_generator);

	id_generator->SetNextId(123);

	EntityId created = em.CreateEntity();

	test_case.Assert(!em.HasEntity(999));
}

void EntityManagerTests::DestroyEntity_Success(Fnd::Test::TestCase& test_case)
{
	std::shared_ptr<MockEntityIdGenerator> id_generator = std::make_shared<MockEntityIdGenerator>();

	EntityManager em(id_generator);

	id_generator->SetNextId(123);

	em.CreateEntity();

	test_case.Assert(em.HasEntity(123));

	em.DestroyEntity(123);

	test_case.Assert(!em.HasEntity(123));
}

void EntityManagerTests::DestroyEntity_InvalidId_Fail(Fnd::Test::TestCase& test_case)
{
	std::shared_ptr<MockEntityIdGenerator> id_generator = std::make_shared<MockEntityIdGenerator>();

	EntityManager em(id_generator);

	bool caught_exception = false;
	try
	{
		em.DestroyEntity(123);
	}
	catch (const InvalidEntityIdException&)
	{
		caught_exception = true;
	}
	test_case.Assert(caught_exception);
}
