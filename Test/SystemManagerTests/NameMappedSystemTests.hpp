#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{

class NameMappedSystemTests:
	public UnitTestClass
{
public:

	NameMappedSystemTests();

private:

	void GetId_Success(TestCase& test_case);
	void GetName_Success(TestCase& test_case);

	void IdNameMapper_IdHasBeenGenerated_True(TestCase& test_case);
	void IdNameMapper_IdHasBeenGenerated_False(TestCase& test_case);
	void IdNameMapper_GetName_MatchesSystemGetName(TestCase& test_case);
	void IdNameMapper_GetId_MatchesSystemGetId(TestCase& test_case);
};

}

}

}
