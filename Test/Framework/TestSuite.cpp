#include "TestSuite.hpp"

using namespace Fnd::Test;

TestSuite::TestSuite( const std::string& name ):
	_name(name)
{
	_result.name = name;
}

void TestSuite::AddUnitTest( std::shared_ptr<UnitTest> unit_test )
{
	_unit_tests.push_back( unit_test );
}

void TestSuite::Run()
{
	for ( auto unit_test : _unit_tests )
	{
		unit_test->Run();
		
		_result.succeeded = _result.succeeded && unit_test->GetResult().succeeded;
		
		++_result.num_tests;
		
		if ( unit_test->GetResult().succeeded )
		{
			++_result.num_tests_succeeded;
		}
		else
		{
			++_result.num_tests_failed;
		}
		
		_result.unit_test_results.push_back( unit_test->GetResult() );
	}
}

const TestSuiteResult& TestSuite::GetResult() const
{
	return _result;
}
