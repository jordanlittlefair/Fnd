#pragma once

#include "TestCaseResult.hpp"

#include <string>
#include <vector>

namespace Fnd
{

namespace Test
{

/**
	@brief The result of a TestClass.
	Stores an array of TestCaseResults. If any TestCases failed, the entire TestClass fails.
*/
class TestClassResult
{
public:

	TestClassResult( const std::string& description );
	
	TestClassResult( const TestClassResult& ) = default;
	TestClassResult& operator=( const TestClassResult& ) = default;
	
	void AddTestCaseResult( const TestCaseResult& test_case_result );
	
	std::string GetDescription() const;
	
	bool GetSucceeded() const;
	
	unsigned int GetNumTestCases() const;
	unsigned int GetNumTestCasesSucceeded() const;
	unsigned int GetNumTestCasesFailed() const;
	
	const std::vector<TestCaseResult>& GetTestCaseResults() const;
	
private:

	std::string _description;

	bool _succeeded;

	unsigned int _num_test_cases;
	unsigned int _num_test_cases_succeeded;
	unsigned int _num_test_cases_failed;

	std::vector<TestCaseResult> _test_case_results;
};

}

}
