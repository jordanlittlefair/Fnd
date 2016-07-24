#include "ResultPrinterCollection.hpp"

using namespace Fnd::Test;

void ResultPrinterCollection::AddResultPrinter(ResultPrinterPtr result_printer)
{
	assert(result_printer);
	
	_result_printers.push_back(result_printer);
}

void ResultPrinterCollection::PrintBeginTestSuiteResult(const std::string& description)
{
	for (auto result_printer : _result_printers)
	{
		result_printer->PrintBeginTestSuiteResult(description);
	}
}

void ResultPrinterCollection::PrintBeginTestClassResult(const TestType test_type, const std::string& description)
{
	for (auto result_printer : _result_printers)
	{
		result_printer->PrintBeginTestClassResult(test_type, description);
	}
}

void ResultPrinterCollection::PrintBeginTestCaseResult(const std::string& description)
{
	for (auto result_printer : _result_printers)
	{
		result_printer->PrintBeginTestCaseResult(description);
	}
}

void ResultPrinterCollection::PrintEndTestSuiteResult(const TestSuiteResult& test_suite_result)
{
	for (auto result_printer : _result_printers)
	{
		result_printer->PrintEndTestSuiteResult(test_suite_result);
	}
}

void ResultPrinterCollection::PrintEndTestClassResult(const TestClassResult& test_class_result)
{
	for (auto result_printer : _result_printers)
	{
		result_printer->PrintEndTestClassResult(test_class_result);
	}
}

void ResultPrinterCollection::PrintEndTestCaseResult(const TestCaseResult& test_case_result)
{
	for (auto result_printer : _result_printers)
	{
		result_printer->PrintEndTestCaseResult(test_case_result);
	}
}
