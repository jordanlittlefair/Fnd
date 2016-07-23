#include "TestClassResult.hpp"

using namespace Fnd::Test;

TestClassResult::TestClassResult( const std::string& description ):
	_description(description),
	_succeeded(true),
	_num_test_cases(0),
	_num_test_cases_succeeded(0),
	_num_test_cases_failed(0)
{
}

void TestClassResult::StartTimer()
{
	_timer.Start();
}

void TestClassResult::EndTimer()
{
	_timer.End();
}

void TestClassResult::AddTestCaseResult( const TestCaseResult& test_case_result )
{
	_succeeded = _succeeded && test_case_result.GetSucceeded();
	
	++_num_test_cases;
	
	if ( test_case_result.GetSucceeded() )
	{
		++_num_test_cases_succeeded;
	}
	else
	{
		++_num_test_cases_failed;
	}
	
	_test_case_results.push_back( test_case_result );
}

std::string TestClassResult::GetDescription() const
{
	return _description;
}

bool TestClassResult::GetSucceeded() const
{
	return _succeeded;
}

unsigned int TestClassResult::GetNumTestCases() const
{
	return _num_test_cases;
}

unsigned int TestClassResult::GetNumTestCasesSucceeded() const
{
	return _num_test_cases_succeeded;
}

unsigned int TestClassResult::GetNumTestCasesFailed() const
{
	return _num_test_cases_failed;
}

Timer::Duration TestClassResult::GetTimeElapsed() const
{
	return _timer.GetTimeElapsed();
}

const std::vector<TestCaseResult>& TestClassResult::GetTestCaseResults() const
{
	return _test_case_results;
}
