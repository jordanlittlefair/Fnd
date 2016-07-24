#pragma once

#include "IResultPrinter.hpp"

#include <memory>

namespace Fnd
{

namespace Test
{

class XmlResultPrinter:
	public IResultPrinter
{
public:
	
	XmlResultPrinter(const std::string& output_filename);
	
	void PrintBeginTestSuiteResult(const std::string& description);
	
	void PrintBeginTestClassResult(const TestType test_type, const std::string& description);
	
	void PrintBeginTestCaseResult(const std::string& description);
	
	void PrintEndTestSuiteResult(const TestSuiteResult& test_suite_result);
	
	void PrintEndTestClassResult(const TestClassResult& test_class_result);
	
	void PrintEndTestCaseResult(const TestCaseResult& test_case_result);
	
	~XmlResultPrinter();
	
private:
	
	struct XmlImpl;
	
	std::shared_ptr<XmlImpl> _xml_impl;
	
	const std::string _output_filename;
	
	unsigned int _total_test_cases;
	unsigned int _total_test_cases_succeeded;
};

}

}
