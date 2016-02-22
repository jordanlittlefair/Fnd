#include "UnitTest.hpp"

using namespace Fnd::Test;

UnitTest::UnitTest( const std::string& name ):
	_name(name),
	_test_cases(),
	_result()
{
	_result.name = _name;
}

void UnitTest::Run()
{
	for ( auto& test_case : _test_cases )
	{
		SetUp();
		
		test_case->Run();
		
		_result.succeeded = _result.succeeded && test_case->GetResult().succeeded;
		
		++_result.num_test_cases;
		
		if ( test_case->GetResult().succeeded )
		{
			++_result.num_test_cases_succeeded;
		}
		else
		{
			++_result.num_test_cases_failed;
		}
		
		_result.test_case_results.push_back( test_case->GetResult() );
		
		CleanUp();
	}
}

const UnitTestResult& UnitTest::GetResult() const
{
	return _result;
}

void UnitTest::AddTestCase( std::shared_ptr<TestCase> test_case )
{
	_test_cases.push_back( test_case );
}

void UnitTest::SetUp()
{
}

void UnitTest::CleanUp()
{
}
