#pragma once

#include "TestSuiteResult.hpp"
#include "TestClass.hpp"

namespace Fnd
{

namespace Test
{

class TestSuite
{
public:

	TestSuite( const std::string& description );
	
	template <typename UnitTestType>
	void AddTestClass()
	{
		AddTestClass( std::make_shared<UnitTestType>() );
	}
	
	void AddTestClass( std::shared_ptr<TestClass> test_class );
	
	void Run();
	
	const TestSuiteResult& GetResult() const;
	
private:
	
	std::vector<std::shared_ptr<TestClass>> _test_classes;
	
	TestSuiteResult _result;
};

}

}
