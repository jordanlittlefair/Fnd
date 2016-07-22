#include "TestClass.hpp"

using namespace Fnd::Test;

TestClass::TestClass(const TestType type, const std::string& description):
	_type(type),
	_result(description)
{
}

void TestClass::SetResultPrinter(ResultPrinterPtr result_printer)
{
	_result_printer = result_printer;
}

TestType TestClass::GetTestType() const
{
	return _type;
}

void TestClass::Run()
{
	SetupClass();

	if (_result_printer)
	{
		_result_printer->PrintBeginTestClassResult(_result.GetDescription() + " [" + GetTestTypeString(_type) + "]");
	}

	for ( auto& test_case : _test_cases )
	{
		SetupTest();

		test_case->SetResultPrinter(_result_printer);
		
		test_case->Run();
		
		_result.AddTestCaseResult(test_case->GetResult());
		
		CleanupTest();
	}
	
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

void TestClass::SetupTest()
{
}

void TestClass::CleanupTest()
{
}
