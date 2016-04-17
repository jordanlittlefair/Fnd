#pragma once

#include "../Framework/TestClass.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{

class SystemGraphNodeTests:
	public TestClass
{
public:

	SystemGraphNodeTests();

private:

	void SetAndGetId( TestCase& test_case );
	void GetWeightDefault( TestCase& test_case );
	void SetAndGetWeight( TestCase& test_case );
	void AddPrev( TestCase& test_case );
	void AddPrev_Duplicate( TestCase& test_case );
	void AddNext( TestCase& test_case );
	void AddNext_Duplicate( TestCase& test_case );
	void RemovePrev( TestCase& test_case );
	void RemovePrev_NonExisting( TestCase& test_case );
	void RemoveNext( TestCase& test_case );
	void RemoveNext_NonExisting( TestCase& test_case );
	void ClearPrev( TestCase& test_case );
	void ClearNext( TestCase& test_case );
	void HasPrev( TestCase& test_case );
	void HasNext( TestCase& test_case );
	void ContainsPrev( TestCase& test_case );
	void ContainsNext( TestCase& test_case );
};

}

}

}
