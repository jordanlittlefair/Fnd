#pragma once

#include "IResultPrinter.hpp"

#include <memory>

namespace Fnd
{

namespace Test
{

class ConsoleResultPrinter:
	public IResultPrinter
{
public:

	void PrintBeginTestSuiteResult(const std::string& description);
	
	void PrintBeginTestClassResult(const TestType test_type, const std::string& description);

	void PrintBeginTestCaseResult(const std::string& description);

	void PrintEndTestSuiteResult(const TestSuiteResult& test_suite_result);
	
	void PrintEndTestClassResult(const TestClassResult& test_class_result);

	void PrintEndTestCaseResult(const TestCaseResult& test_case_result);
};

}

}
