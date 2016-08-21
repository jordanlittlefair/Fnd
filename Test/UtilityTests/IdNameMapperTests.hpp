#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace Utility
{

class IdNameMapperTests:
	public UnitTestClass
{
public:
	
	IdNameMapperTests();
	
private:
	
	void GenerateId_Single_Success(Fnd::Test::TestCase& test_case);
	void GenerateId_TwoUnique_Success(Fnd::Test::TestCase& test_case);
	void GenerateId_ClashingHashes_Success(Fnd::Test::TestCase& test_case);
	void GenerateId_MultipleClashingHashes_Success(Fnd::Test::TestCase& test_case);
	void GenerateId_TwoDuplicate_Throw(Fnd::Test::TestCase& test_case);
	
	void IdHasBeenGenerated_HasBeenGenerated_True(Fnd::Test::TestCase& test_case);
	void IdHasBeenGenerated_HasBeenGenerated_ClashingHashes_True(Fnd::Test::TestCase& test_case);
	void IdHasBeenGenerated_HasNotBeenGenerated_False(Fnd::Test::TestCase& test_case);
	
	void IdHasBeenGeneratedForName_HasBeenGenerated_True(Fnd::Test::TestCase& test_case);
	void IdHasBeenGeneratedForName_HasBeenGenerated_ClashingHashes_True(Fnd::Test::TestCase& test_case);
	void IdHasBeenGeneratedForName_HasNotBeenGenerated_False(Fnd::Test::TestCase& test_case);
	
	void GetId_HasBeenGenerated_Success(Fnd::Test::TestCase& test_case);
	void GetId_HasBeenGenerated_ClashingHashes_Success(Fnd::Test::TestCase& test_case);
	void GetId_HasNotBeenGenerated_Throw(Fnd::Test::TestCase& test_case);
	
	void GetName_HasBeenGenerated_Success(Fnd::Test::TestCase& test_case);
	void GetName_HasBeenGenerated_ClashingHashes_Success(Fnd::Test::TestCase& test_case);
	void GetName_HasNotBeenGenerated_Throw(Fnd::Test::TestCase& test_case);
};

}

}

}
