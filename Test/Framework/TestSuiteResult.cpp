#include "TestSuiteResult.hpp"

using namespace Fnd::Test;

TestSuiteResult::TestSuiteResult():
	name(),
	succeeded(true),
	num_tests(0),
	num_tests_succeeded(0),
	num_tests_failed(0),
	unit_test_results()
{
}
