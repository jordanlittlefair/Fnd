#include "TestSuiteResult.hpp"

using namespace Fnd::Test;

TestSuiteResult::TestSuiteResult( const std::string& description ):
	_description(description),
	_succeeded(true),
	_num_test_classes(0),
	_num_test_classes_succeeded(0),
	_num_test_classes_failed(0)
{
}

void TestSuiteResult::AddTestClassResult( const TestClassResult& test_class_result )
{
	_succeeded = _succeeded && test_class_result.GetSucceeded();
	
	++_num_test_classes;
	
	if ( test_class_result.GetSucceeded() )
	{
		++_num_test_classes_succeeded;
	}
	else
	{
		++_num_test_classes_failed;
	}
	
	_test_class_results.push_back( test_class_result );
}

std::string TestSuiteResult::GetDescription() const
{
	return _description;
}

bool TestSuiteResult::GetSucceeded() const
{
	return _succeeded;
}

unsigned int TestSuiteResult::GetNumTestClasses() const
{
	return _num_test_classes;
}

unsigned int TestSuiteResult::GetNumTestClassesSucceeded() const
{
	return _num_test_classes_succeeded;
}

unsigned int TestSuiteResult::GetNumTestClassesFailed() const
{
	return _num_test_classes_failed;
}

const std::vector<TestClassResult> TestSuiteResult::GetTestClasses() const
{
	return _test_class_results;
}