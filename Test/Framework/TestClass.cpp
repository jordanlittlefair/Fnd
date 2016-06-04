#include "TestClass.hpp"

using namespace Fnd::Test;

TestClass::TestClass( const std::string& description ):
	_result(description)
{
}

void TestClass::Run()
{
	SetupClass();

	for ( auto& test_case : _test_cases )
	{
		SetupTest();
		
		try
		{
			test_case->Run();
		}
		catch (const std::exception& ex)
		{
			test_case->Assert(false, std::string("Unhandled exception: ") + ex.what());
		}
		
		_result.AddTestCaseResult( test_case->GetResult() );
		
		CleanupTest();
	}

	CleanupClass();
}

const TestClassResult& TestClass::GetResult() const
{
	return _result;
}

void TestClass::AddTestCase( std::shared_ptr<TestCase> test_case )
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
