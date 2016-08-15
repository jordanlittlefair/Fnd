#pragma once

#include "../Framework/UnitTestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace Utility
{

class HashIdFromNameGeneratorTests:
	public UnitTestClass
{
public:
	
	HashIdFromNameGeneratorTests();
	
private:
	
	void GenerateIdFromName_Int16_DifferentHashes(Fnd::Test::TestCase& test_case);
	void GenerateIdFromName_Int32_DifferentHashes(Fnd::Test::TestCase& test_case);
	void GenerateIdFromName_Int64_DifferentHashes(Fnd::Test::TestCase& test_case);
};

}

}

}
