#pragma once

#include "AssertResult.hpp"

#include <vector>

namespace Fnd
{

namespace Test
{

/**
	@brief The result of a TestCase.
	Stores an array of AssertResults. If any Asserts failed, the entire TestCase fails.
*/
class TestCaseResult
{
public:

	TestCaseResult( const std::string& description );
	
	//TestCaseResult( const TestCaseResult& ) = default;
	//TestCaseResult& operator=( const TestCaseResult& ) = default;
	
	void AddAssertResult( const AssertResult& assert_result );
	
	std::string GetDescription() const;
	
	bool GetSucceeded() const;
	
	unsigned int GetNumAsserts() const;
	unsigned int GetNumAssertsSucceeded() const;
	unsigned int GetNumAssertsFailed() const;
	
	const std::vector<AssertResult>& GetAssertResults() const;
	
private:

	std::string _description;

	bool _succeeded;

	unsigned int _num_asserts;
	unsigned int _num_asserts_succeeded;
	unsigned int _num_asserts_failed;

	std::vector<AssertResult> _assert_results;
};

}

}
