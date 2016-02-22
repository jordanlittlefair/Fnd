#include "UnitTestResult.hpp"

using namespace Fnd::Test;

UnitTestResult::UnitTestResult():
	name("Undefined"),
	succeeded(true),
	num_test_cases(0),
	num_test_cases_succeeded(0),
	num_test_cases_failed(0),
	test_case_results()
{
}
