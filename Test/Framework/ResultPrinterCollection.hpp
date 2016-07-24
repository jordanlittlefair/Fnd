#pragma once

#include "IResultPrinter.hpp"

#include <memory>

namespace Fnd
{

namespace Test
{

class ResultPrinterCollection:
	public IResultPrinter
{
public:
	
	void AddResultPrinter(ResultPrinterPtr result_printer);
	
	void PrintBeginTestSuiteResult(const std::string& description);
	
	void PrintBeginTestClassResult(const TestType test_type, const std::string& description);
	
	void PrintBeginTestCaseResult(const std::string& description);
	
	void PrintEndTestSuiteResult(const TestSuiteResult& test_suite_result);
	
	void PrintEndTestClassResult(const TestClassResult& test_class_result);
	
	void PrintEndTestCaseResult(const TestCaseResult& test_case_result);
	
private:
	
	std::vector<ResultPrinterPtr> _result_printers;
};

}

}
