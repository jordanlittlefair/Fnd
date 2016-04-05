#include "TestCase.hpp"

using namespace Fnd::Test;

TestCase::TestCase( const std::string& description, TestFunction function ):
_result(description),
_function(function)
{
}

void TestCase::Run()
{
	_function( *this );
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
