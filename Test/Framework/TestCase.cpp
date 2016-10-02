#include "TestCase.hpp"

using namespace Fnd::Test;

TestCase::TestCase( const std::string& description, TestFunction function ):
_result(description),
_description(description),
_function(function)
{
}

void TestCase::SetResultPrinter(ResultPrinterPtr result_printer)
{
	_result_printer = result_printer;
}

std::string TestCase::GetDescription() const
{
	return _description;
}

void TestCase::Run()
{
	if (_result_printer)
	{
		_result_printer->PrintBeginTestCaseResult(_result.GetDescription());
	}
	
	_result.StartTimer();

	try
	{
		_function( *this );
	}
	catch (const std::exception& ex)
	{
		Assert(false, std::string("Unhandled exception: ") + ex.what());
	}
	catch (...)
	{
		Assert(false, "Unhandled exception: Unknown exception (...)");
	}
	
	_result.EndTimer();
	
	if (_result_printer)
	{
		_result_printer->PrintEndTestCaseResult(_result);
	}
}

void TestCase::Assert( bool succeeded, const std::string& description )
{
	AssertResult assert_result( succeeded, description );
	
	_result.AddAssertResult( assert_result );
}

const TestCaseResult& TestCase::GetResult() const
{
	return _result;
}

TestCase::~TestCase()
{
}
