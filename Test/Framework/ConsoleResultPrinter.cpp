#include "ConsoleResultPrinter.hpp"

#include <iostream>

using namespace Fnd::Test;

void ConsoleResultPrinter::PrintBeginTestSuiteResult(const std::string& description)
{
	std::cout 
		<< description << "...\n";
}
	
void ConsoleResultPrinter::PrintBeginTestClassResult(const std::string& description)
{
	std::cout 
		<< "\t"
		<< description << "...\n";
}

void ConsoleResultPrinter::PrintBeginTestCaseResult(const std::string& description)
{
}

void ConsoleResultPrinter::PrintEndTestSuiteResult(const TestSuiteResult& test_suite_result)
{
	std::cout
		<< (test_suite_result.GetSucceeded() ? "Succeeded" : "Failed")
		<< " [" << test_suite_result.GetNumTestClassesSucceeded() << '/' << test_suite_result.GetNumTestClasses() << " Test Classes]\n";
}
	
void ConsoleResultPrinter::PrintEndTestClassResult(const TestClassResult& test_class_result)
{
	std::cout
		<< "\t"
		<< (test_class_result.GetSucceeded() ? "Succeeded" : "Failed")
		<< " [" << test_class_result.GetNumTestCasesSucceeded() << "/" << test_class_result.GetNumTestCases() << " Test Cases]\n";
}

void ConsoleResultPrinter::PrintEndTestCaseResult(const TestCaseResult& test_case_result)
{
	std::cout
		<< "\t\t"
		<< test_case_result.GetDescription()
		<< ": " << (test_case_result.GetSucceeded() ? "Succeeded" : "Failed")
		<< " [" << test_case_result.GetNumAssertsSucceeded() << "/" << test_case_result.GetNumAsserts() << " Asserts]\n";
}