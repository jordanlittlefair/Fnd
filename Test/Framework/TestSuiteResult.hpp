#pragma once

#include "UnitTestResult.hpp"

#include <string>
#include <vector>

namespace Fnd
{

namespace Test
{

struct TestSuiteResult
{
	std::string name;

	bool succeeded;

	unsigned int num_tests;
	unsigned int num_tests_succeeded;
	unsigned int num_tests_failed;

	std::vector<UnitTestResult> unit_test_results;
	
	TestSuiteResult();
};

}

}
