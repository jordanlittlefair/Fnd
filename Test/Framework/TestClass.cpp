#include "TestClass.hpp"

using namespace Fnd::Test;

TestClass::TestClass( const std::string& description ):
	_result(description)
{
}

void TestClass::Run()
{
	for ( auto& test_case : _test_cases )
	{
		SetUp();
		
		try
		{
			test_case->Run();
		}
		catch ( const std::exception& ex )
		{
			test_case->Assert( false, std::string( "Unexpected exception: " ) + ex.what() );
		}
		
		_result.AddTestCaseResult( test_case->GetResult() );
		
		CleanUp();
	}
}

const TestClassResult& TestClass::GetResult() const
{
	return _result;
}

void TestClass::AddTestCase( std::shared_ptr<TestCase> test_case )
{
	_test_cases.push_back( test_case );
}

void TestClass::SetUp()
{
}

void TestClass::CleanUp()
{
}
