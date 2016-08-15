#include "IdNameMapperTests.hpp"

#include "MockIdFromNameGenerator.hpp"

#include "../../Code/Utility/IdNameMapper.hpp"
#include "../../Code/Utility/HashIdFromNameGenerator.hpp"

#include <memory>
#include <set>

using namespace Fnd::Test::Utility;
using namespace Fnd::Utility;


IdNameMapperTests::IdNameMapperTests():
UnitTestClass("IdNameMapperTests")
{
	AddTestCase("GenerateId_Single_Success", &IdNameMapperTests::GenerateId_Single_Success, this);
	AddTestCase("GenerateId_TwoUnique_Success", &IdNameMapperTests::GenerateId_TwoUnique_Success, this);
	AddTestCase("GenerateId_ClashingHashes_Success", &IdNameMapperTests::GenerateId_ClashingHashes_Success, this);
	AddTestCase("GenerateId_MultipleClashingHashes_Success", &IdNameMapperTests::GenerateId_MultipleClashingHashes_Success, this);
	AddTestCase("GenerateId_TwoDuplicate_Throw", &IdNameMapperTests::GenerateId_TwoDuplicate_Throw, this);
	
	AddTestCase("IdHasBeenGenerated_HasBeenGenerated_True", &IdNameMapperTests::IdHasBeenGenerated_HasBeenGenerated_True, this);
	AddTestCase("IdHasBeenGenerated_HasBeenGenerated_ClashingHashes_True", &IdNameMapperTests::IdHasBeenGenerated_HasBeenGenerated_ClashingHashes_True, this);
	AddTestCase("IdHasBeenGenerated_HasNotBeenGenerated_False", &IdNameMapperTests::IdHasBeenGenerated_HasNotBeenGenerated_False, this);
	
	AddTestCase("IdHasBeenGeneratedForName_HasBeenGenerated_True", &IdNameMapperTests::IdHasBeenGeneratedForName_HasBeenGenerated_True, this);
	AddTestCase("IdHasBeenGeneratedForName_HasBeenGenerated_ClashingHashes_True", &IdNameMapperTests::IdHasBeenGeneratedForName_HasBeenGenerated_ClashingHashes_True, this);
	AddTestCase("IdHasBeenGeneratedForName_HasNotBeenGenerated_False", &IdNameMapperTests::IdHasBeenGeneratedForName_HasNotBeenGenerated_False, this);
	
	AddTestCase("GetId_HasBeenGenerated_Success", &IdNameMapperTests::GetId_HasBeenGenerated_Success, this);
	AddTestCase("GetId_HasBeenGenerated_ClashingHashes_Success", &IdNameMapperTests::GetId_HasBeenGenerated_ClashingHashes_Success, this);
	AddTestCase("GetId_HasNotBeenGenerated_Throw", &IdNameMapperTests::GetId_HasNotBeenGenerated_Throw, this);
	
	AddTestCase("GetName_HasBeenGenerated_Success", &IdNameMapperTests::GetName_HasBeenGenerated_Success, this);
	AddTestCase("GetName_HasBeenGenerated_ClashingHashes_Success", &IdNameMapperTests::GetName_HasBeenGenerated_ClashingHashes_Success, this);
	AddTestCase("GetName_HasNotBeenGenerated_Throw", &IdNameMapperTests::GetName_HasNotBeenGenerated_Throw, this);
}

void IdNameMapperTests::GenerateId_Single_Success(Fnd::Test::TestCase& test_case)
{
	IdNameMapper<int> mapper(std::make_shared<MockIdFromNameGenerator>());
	
	int id = mapper.GenerateId("123");
	
	test_case.Assert(id != 0);
}

void IdNameMapperTests::GenerateId_TwoUnique_Success(Fnd::Test::TestCase& test_case)
{
	IdNameMapper<int> mapper(std::make_shared<MockIdFromNameGenerator>());
	
	int id0 = mapper.GenerateId("123");
	int id1 = mapper.GenerateId("456");
	
	test_case.AssertNotEqual(id0, id1);
}

void IdNameMapperTests::GenerateId_ClashingHashes_Success(Fnd::Test::TestCase& test_case)
{
	IdNameMapper<int> mapper(std::make_shared<MockIdFromNameGenerator>());
	
	// Should produce a clash using MockIdFromNameGenerator
	int id0 = mapper.GenerateId("123");
	int id1 = mapper.GenerateId("321");
	
	test_case.AssertNotEqual(id0, id1);
}

void IdNameMapperTests::GenerateId_MultipleClashingHashes_Success(Fnd::Test::TestCase& test_case)
{
	IdNameMapper<int> mapper(std::make_shared<MockIdFromNameGenerator>());
	
	// Should produce clashes using MockIdFromNameGenerator
	int ids[] =
	{
		mapper.GenerateId("123"),
		mapper.GenerateId("132"),
		mapper.GenerateId("213"),
		mapper.GenerateId("231"),
		mapper.GenerateId("312"),
		mapper.GenerateId("321"),
		
		mapper.GenerateId("abcd"),
		mapper.GenerateId("abdc"),
		mapper.GenerateId("acbd"),
		mapper.GenerateId("acdb"),
		mapper.GenerateId("adbc"),
		mapper.GenerateId("adcb"),
		mapper.GenerateId("bacd"),
		mapper.GenerateId("badc"),
		mapper.GenerateId("bcad"),
		mapper.GenerateId("bcda"),
		mapper.GenerateId("bdac"),
		mapper.GenerateId("bdca"),
		mapper.GenerateId("cabd"),
		mapper.GenerateId("cadb"),
		mapper.GenerateId("cbad"),
		mapper.GenerateId("cbda"),
		mapper.GenerateId("cdab"),
		mapper.GenerateId("cdba"),
		mapper.GenerateId("dabc"),
		mapper.GenerateId("dacb"),
		mapper.GenerateId("dbac"),
		mapper.GenerateId("dbca"),
		mapper.GenerateId("dcab"),
		mapper.GenerateId("dcba")
	};
	
	const unsigned int num_ids = sizeof(ids) / sizeof(int);
	
	for (unsigned int i = 0; i < num_ids; ++i)
	{
		for (unsigned int j = i + 1; j < num_ids; ++j)
		{
			test_case.AssertNotEqual(ids[i], ids[j]);
		}
	}
	
	std::set<std::string> names;
	
	for (unsigned int i = 0; i < num_ids; ++i)
	{
		names.insert(mapper.GetName(ids[i]));
	}
	
	test_case.AssertEqual(num_ids, names.size());
}

void IdNameMapperTests::GenerateId_TwoDuplicate_Throw(Fnd::Test::TestCase& test_case)
{
	IdNameMapper<int> mapper(std::make_shared<MockIdFromNameGenerator>());
	
	int id0 = mapper.GenerateId("123");
	
	test_case.AssertException<std::exception>([&]()
	{
		int id1 = mapper.GenerateId("123");
	});
}

void IdNameMapperTests::IdHasBeenGenerated_HasBeenGenerated_True(Fnd::Test::TestCase& test_case)
{
	IdNameMapper<int> mapper(std::make_shared<MockIdFromNameGenerator>());
	
	int id0 = mapper.GenerateId("123");
	
	test_case.Assert(mapper.IdHasBeenGenerated(id0));
}

void IdNameMapperTests::IdHasBeenGenerated_HasBeenGenerated_ClashingHashes_True(Fnd::Test::TestCase& test_case)
{
	IdNameMapper<int> mapper(std::make_shared<MockIdFromNameGenerator>());
	
	// Should produce a clash using MockIdFromNameGenerator
	int id0 = mapper.GenerateId("123");
	int id1 = mapper.GenerateId("321");
	
	test_case.Assert(mapper.IdHasBeenGenerated(id0));
	test_case.Assert(mapper.IdHasBeenGenerated(id1));
}

void IdNameMapperTests::IdHasBeenGenerated_HasNotBeenGenerated_False(Fnd::Test::TestCase& test_case)
{
	IdNameMapper<int> mapper(std::make_shared<MockIdFromNameGenerator>());
	
	int id0 = mapper.GenerateId("123");
	
	test_case.Assert(!mapper.IdHasBeenGenerated(id0 + 1));
}

void IdNameMapperTests::IdHasBeenGeneratedForName_HasBeenGenerated_True(Fnd::Test::TestCase& test_case)
{
	IdNameMapper<int> mapper(std::make_shared<MockIdFromNameGenerator>());
	
	int id0 = mapper.GenerateId("123");
	
	test_case.Assert(mapper.IdHasBeenGeneratedForName("123"));
}

void IdNameMapperTests::IdHasBeenGeneratedForName_HasBeenGenerated_ClashingHashes_True(Fnd::Test::TestCase& test_case)
{
	IdNameMapper<int> mapper(std::make_shared<MockIdFromNameGenerator>());
	
	// Should produce a clash using MockIdFromNameGenerator
	int id0 = mapper.GenerateId("123");
	int id1 = mapper.GenerateId("321");
	
	test_case.Assert(mapper.IdHasBeenGeneratedForName("123"));
	test_case.Assert(mapper.IdHasBeenGeneratedForName("321"));
}

void IdNameMapperTests::IdHasBeenGeneratedForName_HasNotBeenGenerated_False(Fnd::Test::TestCase& test_case)
{
	IdNameMapper<int> mapper(std::make_shared<MockIdFromNameGenerator>());
	
	int id0 = mapper.GenerateId("123");
	
	test_case.Assert(!mapper.IdHasBeenGeneratedForName("321"));
}

void IdNameMapperTests::GetId_HasBeenGenerated_Success(Fnd::Test::TestCase& test_case)
{
	IdNameMapper<int> mapper(std::make_shared<MockIdFromNameGenerator>());
	
	int id0 = mapper.GenerateId("123");
	
	test_case.AssertEqual(id0, mapper.GetId("123"));
}

void IdNameMapperTests::GetId_HasBeenGenerated_ClashingHashes_Success(Fnd::Test::TestCase& test_case)
{
	IdNameMapper<int> mapper(std::make_shared<MockIdFromNameGenerator>());
	
	// Should produce a clash using MockIdFromNameGenerator
	int id0 = mapper.GenerateId("123");
	int id1 = mapper.GenerateId("321");
	
	test_case.AssertEqual(id0, mapper.GetId("123"));
	test_case.AssertEqual(id1, mapper.GetId("321"));
}

void IdNameMapperTests::GetId_HasNotBeenGenerated_Throw(Fnd::Test::TestCase& test_case)
{
	IdNameMapper<int> mapper(std::make_shared<MockIdFromNameGenerator>());
	
	int id0 = mapper.GenerateId("123");
	
	test_case.AssertException<std::exception>([&]()
	{
		mapper.GetId("321");
	});
}

void IdNameMapperTests::GetName_HasBeenGenerated_Success(Fnd::Test::TestCase& test_case)
{
	IdNameMapper<int> mapper(std::make_shared<MockIdFromNameGenerator>());
	
	int id0 = mapper.GenerateId("123");
	
	test_case.AssertEqual("123", mapper.GetName(id0));
}

void IdNameMapperTests::GetName_HasBeenGenerated_ClashingHashes_Success(Fnd::Test::TestCase& test_case)
{
	IdNameMapper<int> mapper(std::make_shared<MockIdFromNameGenerator>());
	
	// Should produce a clash using MockIdFromNameGenerator
	int id0 = mapper.GenerateId("123");
	int id1 = mapper.GenerateId("321");
	
	test_case.AssertEqual("123", mapper.GetName(id0));
	test_case.AssertEqual("321", mapper.GetName(id1));
}

void IdNameMapperTests::GetName_HasNotBeenGenerated_Throw(Fnd::Test::TestCase& test_case)
{
	IdNameMapper<int> mapper(std::make_shared<MockIdFromNameGenerator>());
	
	int id0 = mapper.GenerateId("123");
	
	test_case.AssertException<std::exception>([&]()
	{
		mapper.GetName(id0 + 1);
	});
}
