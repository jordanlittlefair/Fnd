#pragma once

#include "TestSuiteResult.hpp"
#include "UnitTest.hpp"

namespace Fnd
{

namespace Test
{

class TestSuite
{
public:

	TestSuite( const std::string& name );
	
	template <typename UnitTestType>
	void AddUnitTest()
	{
		AddUnitTest( std::make_shared<UnitTestType>() );
	}
	
	void AddUnitTest( std::shared_ptr<UnitTest> unit_test );
	
	void Run();
	
	const TestSuiteResult& GetResult() const;
	
private:

	std::string _name;
	
	std::vector<std::shared_ptr<UnitTest>> _unit_tests;
	
	TestSuiteResult _result;
};

}

}
