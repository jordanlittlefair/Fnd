#include "HashIdFromNameGeneratorTests.hpp"

#include "../../Code/Utility/HashIdFromNameGenerator.hpp"

#include <set>

using namespace Fnd::Test::Utility;
using namespace Fnd::Utility;

namespace
{
	// Can't properly test the generator... this is just to instansiate the template and make sure there are no obvious issues
	template <typename T>
	void TestUniqueIds(std::shared_ptr<IIdFromNameGenerator<T>> generator, Fnd::Test::TestCase& test_case)
	{
		// A selection of example names - assert these don't produce collisions (not really a great test... collisions should be handled externally)
		std::string names[] =
		{
			"a", "b", "c",
			"aa", "ab", "ac", "ba", "bb", "bc", "ca", "cb", "cc",
			"aaa", "aab", "aac", "aba", "abb", "abc", "aca", "acb", "acc",
			"baa", "bab", "bac", "bba", "bbb", "bbc", "bca", "bcb", "bcc",
			"caa", "cab", "cac", "cba", "cbb", "cbc", "cca", "ccb", "ccc",
			
			"",
			
			"System0",
			"System1",
			"System10",
			"System11",
			
			"01111",
			"10111",
			"11011",
			"11101",
			"11110"
		};
		const unsigned int num_names = sizeof(names) / sizeof(std::string);
		
		std::set<T> unique_ids;
		
		for (auto name : names)
		{
			unique_ids.insert(generator->GenerateIdFromName(name));
		}
		
		test_case.AssertEqual(num_names, unique_ids.size());
	}
}

HashIdFromNameGeneratorTests::HashIdFromNameGeneratorTests():
	UnitTestClass("HashIdFromNameGeneratorTests")
{
	AddTestCase("GenerateIdFromName_Int16_DifferentHashes", &HashIdFromNameGeneratorTests::GenerateIdFromName_Int16_DifferentHashes, this);
	AddTestCase("GenerateIdFromName_Int32_DifferentHashes", &HashIdFromNameGeneratorTests::GenerateIdFromName_Int32_DifferentHashes, this);
	AddTestCase("GenerateIdFromName_Int64_DifferentHashes", &HashIdFromNameGeneratorTests::GenerateIdFromName_Int64_DifferentHashes, this);
}

void HashIdFromNameGeneratorTests::GenerateIdFromName_Int16_DifferentHashes(Fnd::Test::TestCase& test_case)
{
	typedef short int IdType;
	
	std::shared_ptr<IIdFromNameGenerator<IdType>> generator = std::make_shared<HashIdFromNameGenerator<IdType>>();
	
	TestUniqueIds(generator, test_case);
}

void HashIdFromNameGeneratorTests::GenerateIdFromName_Int32_DifferentHashes(Fnd::Test::TestCase& test_case)
{
	typedef long int IdType;
	
	std::shared_ptr<IIdFromNameGenerator<IdType>> generator = std::make_shared<HashIdFromNameGenerator<IdType>>();
	
	TestUniqueIds(generator, test_case);
}

void HashIdFromNameGeneratorTests::GenerateIdFromName_Int64_DifferentHashes(Fnd::Test::TestCase& test_case)
{
	typedef long long int IdType;
	
	std::shared_ptr<IIdFromNameGenerator<IdType>> generator = std::make_shared<HashIdFromNameGenerator<IdType>>();
	
	TestUniqueIds(generator, test_case);
}
