#pragma once

#include "TestCase.hpp"
#include "TestClassResult.hpp"

#include <memory>
#include <vector>

namespace Fnd
{
	
namespace Test
{

class TestClass
{
public:
	
	void Run();
	
	const TestClassResult& GetResult() const;

	virtual ~TestClass();
	
protected:

	TestClass( const std::string& desciption );

	template <typename FunctionType,typename DerivedType>
	void AddTestCase( const std::string& name, FunctionType function, DerivedType* ptr )
	{
		AddTestCase( std::make_shared<TestCase>( name, std::bind( function, ptr, std::placeholders::_1 ) ) );
	}
	
	virtual void SetupClass();
	
	virtual void CleanupClass();

	virtual void SetupTest();

	virtual void CleanupTest();
	
private:
	
	void AddTestCase( TestCasePtr test_case );
	
private:
	
	std::vector<TestCasePtr> _test_cases;
	
	TestClassResult _result;
};

typedef std::shared_ptr<TestClass> TestClassPtr;

}

}
