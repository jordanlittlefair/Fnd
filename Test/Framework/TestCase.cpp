#include "TestCase.hpp"

using namespace Fnd::Test;

TestCase::TestCase( const std::string& name, TestFunction function ):
_function(function),
_name(name)
{
	_result.name = _name;
}

void TestCase::Run()
{
	_function( *this );
}

void TestCase::Assert( bool succeeded, const std::string& description )
{
	_result.succeeded = _result.succeeded && succeeded;
	++_result.num_asserts;
	
	if ( succeeded )
	{
		++_result.num_asserts_succeeded;
	}
	else
	{
		++_result.num_asserts_failed;
		
		TestCaseResult::Failure failure;
		failure.description = description;
		
		_result.failures.push_back( failure );
	}
}

const TestCaseResult& TestCase::GetResult() const
{
	return _result;
}
