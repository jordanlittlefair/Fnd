#include "TestClass.hpp"

using namespace Fnd::Test;

TestClass::TestClass(const TestType type, const std::string& description):
	_type(type),
	_description(description),
	_result(description)
{
}

void TestClass::SetWorkingDirectory(const std::string& working_directory)
{
	_working_directory = working_directory;
}

std::string TestClass::GetWorkingDirectory() const
{
	return _working_directory;
}

void TestClass::SetResultPrinter(ResultPrinterPtr result_printer)
{
	_result_printer = result_printer;
}

TestType TestClass::GetTestType() const
{
	return _type;
}

std::string TestClass::GetDescription() const
{
	return _description;
}

void TestClass::Run()
{
	SetupClass();

	if (_result_printer)
	{
		_result_printer->PrintBeginTestClassResult(_type, _result.GetDescription());
	}
	
	_result.StartTimer();

	for ( auto& test_case : _test_cases )
	{
		SetupTest(test_case->GetDescription());

		test_case->SetResultPrinter(_result_printer);
		
		test_case->Run();
		
		_result.AddTestCaseResult(test_case->GetResult());
		
		CleanupTest(test_case->GetDescription());
	}
	
	_result.EndTimer();
	
	if (_result_printer)
	{
		_result_printer->PrintEndTestClassResult(_result);
	}

	CleanupClass();
}

const TestClassResult& TestClass::GetResult() const
{
	return _result;
}

TestClass::~TestClass()
{
}

void TestClass::AddTestCase( TestCasePtr test_case )
{
	_test_cases.push_back( test_case );
}

void TestClass::SetupClass()
{
}

void TestClass::CleanupClass()
{
}

void TestClass::SetupTest(const std::string& test_description)
{
}

void TestClass::CleanupTest(const std::string& test_description)
{
}
