#include "TestCaseResult.hpp"

using namespace Fnd::Test;

TestCaseResult::TestCaseResult( const std::string& description ):
	_description(description),
	_succeeded(true),
	_num_asserts(0),
	_num_asserts_succeeded(0),
	_num_asserts_failed(0)
{
}

void TestCaseResult::AddAssertResult( const AssertResult& assert_result )
{
	_succeeded = _succeeded && assert_result.GetSucceeded();
	
	++_num_asserts;
	
	if ( assert_result.GetSucceeded() )
	{
		++_num_asserts_succeeded;
	}
	else
	{
		++_num_asserts_failed;
	}
	
	_assert_results.push_back( assert_result );
}

std::string TestCaseResult::GetDescription() const
{
	return _description;
}

bool TestCaseResult::GetSucceeded() const
{
	return _succeeded;
}

unsigned int TestCaseResult::GetNumAsserts() const
{
	return _num_asserts;
}

unsigned int TestCaseResult::GetNumAssertsSucceeded() const
{
	return _num_asserts_succeeded;
}

unsigned int TestCaseResult::GetNumAssertsFailed() const
{
	return _num_asserts_failed;
}

const std::vector<AssertResult>& TestCaseResult::GetAssertResults() const
{
	return _assert_results;
}
