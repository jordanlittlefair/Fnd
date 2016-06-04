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

void TestSuite::Run()
{
	for ( auto test_class : _test_classes )
	{
		test_class->Run();
		
		_result.AddTestClassResult( test_class->GetResult() );
	}
}

const TestSuiteResult& TestSuite::GetResult() const
{
	return _result;
}
