#pragma once

#include "TestClassResult.hpp"

#include <string>
#include <vector>

namespace Fnd
{

namespace Test
{

/**
	@brief The result of a TestSuite.
	Stores an array of TestClassResults. If any TestClasses failed, the entire TestSuite fails.
*/
class TestSuiteResult
{
public:

	TestSuiteResult( const std::string& description );
	
	//TestSuiteResult( const TestSuiteResult& ) = default;
	//TestSuiteResult& operator=( const TestSuiteResult& ) = default;
	
	void AddTestClassResult( const TestClassResult& test_class_result );
	
	std::string GetDescription() const;
	
	bool GetSucceeded() const;
	
	unsigned int GetNumTestClasses() const;
	unsigned int GetNumTestClassesSucceeded() const;
	unsigned int GetNumTestClassesFailed() const;

	const std::vector<TestClassResult> GetTestClasses() const;
	
private:

	std::string _description;

	bool _succeeded;

	unsigned int _num_test_classes;
	unsigned int _num_test_classes_succeeded;
	unsigned int _num_test_classes_failed;

	std::vector<TestClassResult> _test_class_results;
};

}

}
