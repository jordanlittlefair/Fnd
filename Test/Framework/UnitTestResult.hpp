#pragma once

#include "TestCaseResult.hpp"

#include <string>
#include <vector>

namespace Fnd
{

namespace Test
{

struct UnitTestResult
{
	std::string name;

	bool succeeded;

	unsigned int num_test_cases;
	unsigned int num_test_cases_succeeded;
	unsigned int num_test_cases_failed;

	std::vector<TestCaseResult> test_case_results;
	
	UnitTestResult();
};

}

}
