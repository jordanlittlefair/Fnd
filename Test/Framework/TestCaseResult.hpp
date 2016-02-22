#pragma once

#include <string>
#include <vector>

namespace Fnd
{

namespace Test
{

struct TestCaseResult
{
	std::string name;

	bool succeeded;

	unsigned int num_asserts;
	unsigned int num_asserts_succeeded;
	unsigned int num_asserts_failed;

	struct Failure
	{
		std::string description;
	};

	std::vector<Failure> failures;
	
	TestCaseResult();
};

}

}
