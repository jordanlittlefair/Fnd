#include "TestClass.hpp"

using namespace Fnd::Test;

TestClass::TestClass( const std::string& description ):
	_result(description)
{
}

void TestClass::SetResultPrinter(ResultPrinterPtr result_printer)
{
	_result_printer = result_printer;
}

void TestClass::Run()
{
	SetupClass();

	if (_result_printer)
	{
		_result_printer->PrintBeginTestClassResult(_result.GetDescription());
	}

	for ( auto& test_case : _test_cases )
	{
		SetupTest();

		test_case->SetResultPrinter(_result_printer);
		
		try
		{
			test_case->Run();
		}
		catch (const std::exception& ex)
		{
			test_case->Assert(false, std::string("Unhandled exception: ") + ex.what());
		}
		
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
