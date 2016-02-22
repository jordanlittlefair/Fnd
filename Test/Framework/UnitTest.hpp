#pragma once

#include "TestCase.hpp"
#include "UnitTestResult.hpp"

#include <memory>
#include <vector>

namespace Fnd
{
	
namespace Test
{

class UnitTest
{
public:
	
	void Run();
	
	const UnitTestResult& GetResult() const;
	
protected:

	UnitTest( const std::string& name );

	template <typename FunctionType,typename DerivedType>
	void AddTestCase( const std::string& name, FunctionType function, DerivedType* ptr )
	{
		AddTestCase( std::make_shared<TestCase>( name, std::bind( function, ptr, std::placeholders::_1 ) ) );
	}
	
	virtual void SetUp();
	
	virtual void CleanUp();
	
private:
	
	void AddTestCase( std::shared_ptr<TestCase> test_case );
	
private:

	std::string _name;
	
	std::vector<std::shared_ptr<TestCase>> _test_cases;
	
	UnitTestResult _result;
};

}

}
