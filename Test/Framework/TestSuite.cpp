#include "TestSuite.hpp"

using namespace Fnd::Test;

TestSuite::TestSuite( const std::string& description ):
	_result(description)
{
}

void TestSuite::AddTestClass( TestClassPtr test_class )
{
	_test_classes.push_back( test_class );
}

void TestSuite::SetResultPrinter(ResultPrinterPtr result_printer)
{
	_result_printer = result_printer;
}

void TestSuite::Run()
{
	if (_result_printer)
	{
		_result_printer->PrintBeginTestSuiteResult(GetResult().GetDescription());
	}

	for ( auto test_class : _test_classes )
	{
		test_class->SetResultPrinter(_result_printer);

		test_class->Run();
		
		_result.AddTestClassResult( test_class->GetResult() );
	}

	if (_result_printer)
	{
		_result_printer->PrintEndTestSuiteResult(GetResult());
	}
}

const TestSuiteResult& TestSuite::GetResult() const
{
	return _result;
}

TestSuite::~TestSuite()
{	
}
