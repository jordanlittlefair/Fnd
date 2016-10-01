#include "NameMappedSystemTests.hpp"

#include "MockNameMappedSystem.hpp"


using namespace Fnd::Test;
using namespace Fnd::Test::SystemManager;
using namespace Fnd::SystemManager;

NameMappedSystemTests::NameMappedSystemTests():
	UnitTestClass("NameMappedSystemTests")
{
	AddTestCase( "GetId_Success", &NameMappedSystemTests::GetId_Success, this );
	AddTestCase( "GetName_Success", &NameMappedSystemTests::GetName_Success, this );
	AddTestCase( "IdNameMapper_IdHasBeenGenerated_True", &NameMappedSystemTests::IdNameMapper_IdHasBeenGenerated_True, this );
	AddTestCase( "IdNameMapper_IdHasBeenGenerated_False", &NameMappedSystemTests::IdNameMapper_IdHasBeenGenerated_False, this );
	AddTestCase( "IdNameMapper_GetName_MatchesSystemGetName", &NameMappedSystemTests::IdNameMapper_GetName_MatchesSystemGetName, this );
	AddTestCase( "IdNameMapper_GetId_MatchesSystemGetId", &NameMappedSystemTests::IdNameMapper_GetId_MatchesSystemGetId, this );
}

void NameMappedSystemTests::GetId_Success(TestCase& test_case)
{
	const std::string name = "ExampleName";

	SystemIdNameMapperPtr mapper = std::make_shared<SystemIdNameMapper>(std::make_shared<SystemIdFromNameGenerator>());

	MockNameMappedSystem system(mapper, name);

	test_case.AssertEqual(mapper->GetId(name), system.GetId());
}

void NameMappedSystemTests::GetName_Success(TestCase& test_case)
{
	const std::string name = "ExampleName";

	SystemIdNameMapperPtr mapper = std::make_shared<SystemIdNameMapper>(std::make_shared<SystemIdFromNameGenerator>());

	MockNameMappedSystem system(mapper, name);

	test_case.AssertEqual(name, system.GetName());
}

void NameMappedSystemTests::IdNameMapper_IdHasBeenGenerated_True(TestCase& test_case)
{
	const std::string name = "ExampleName";

	SystemIdNameMapperPtr mapper = std::make_shared<SystemIdNameMapper>(std::make_shared<SystemIdFromNameGenerator>());

	MockNameMappedSystem system(mapper, name);

	test_case.Assert(mapper->IdHasBeenGeneratedForName(name));
	test_case.Assert(mapper->IdHasBeenGenerated(system.GetId()));
}

void NameMappedSystemTests::IdNameMapper_IdHasBeenGenerated_False(TestCase& test_case)
{
	const std::string name = "ExampleName";
	const std::string other_name = "OtherName";

	SystemIdNameMapperPtr mapper = std::make_shared<SystemIdNameMapper>(std::make_shared<SystemIdFromNameGenerator>());

	MockNameMappedSystem system(mapper, name);

	const SystemId other_id = system.GetId() + 1;

	test_case.Assert(!mapper->IdHasBeenGeneratedForName(other_name));
	test_case.Assert(!mapper->IdHasBeenGenerated(other_id));
}

void NameMappedSystemTests::IdNameMapper_GetName_MatchesSystemGetName(TestCase& test_case)
{
	const std::string name = "ExampleName";

	SystemIdNameMapperPtr mapper = std::make_shared<SystemIdNameMapper>(std::make_shared<SystemIdFromNameGenerator>());

	MockNameMappedSystem system(mapper, name);

	test_case.AssertEqual(system.GetName(), mapper->GetName(system.GetId()));
}

void NameMappedSystemTests::IdNameMapper_GetId_MatchesSystemGetId(TestCase& test_case)
{
	const std::string name = "ExampleName";

	SystemIdNameMapperPtr mapper = std::make_shared<SystemIdNameMapper>(std::make_shared<SystemIdFromNameGenerator>());

	MockNameMappedSystem system(mapper, name);

	test_case.AssertEqual(system.GetId(), mapper->GetId(system.GetName()));
}
