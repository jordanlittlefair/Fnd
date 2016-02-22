#include "TestCaseResult.hpp"

using namespace Fnd::Test;

TestCaseResult::TestCaseResult():
	name("Undefined"),
	succeeded(true),
	num_asserts(0),
	num_asserts_succeeded(0),
	num_asserts_failed(0),
	failures()
{
}
