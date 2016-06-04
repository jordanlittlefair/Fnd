#pragma once

#include "TestSuiteResult.hpp"

#include <memory>

namespace Fnd
{

namespace Test
{

class IResultPrinter
{
public:

	virtual void PrintBeginTestSuiteResult(const std::string& description) = 0;
	
	virtual void PrintBeginTestClassResult(const std::string& description) = 0;

	virtual void PrintBeginTestCaseResult(const std::string& description) = 0;

	virtual void PrintEndTestSuiteResult(const TestSuiteResult& test_suite_result) = 0;
	
	virtual void PrintEndTestClassResult(const TestClassResult& test_class_result) = 0;

	virtual void PrintEndTestCaseResult(const TestCaseResult& test_case_result) = 0;
};

typedef std::shared_ptr<IResultPrinter> ResultPrinterPtr;

}

}
