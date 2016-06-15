#pragma once

#include "IResultPrinter.hpp"
#include "TestSuiteResult.hpp"
#include "TestClass.hpp"

namespace Fnd
{

namespace Test
{

class TestSuite
{
public:
	
	void SetResultPrinter(ResultPrinterPtr result_printer);

	void Run();
	
	const TestSuiteResult& GetResult() const;
	
	virtual ~TestSuite();
	
protected:
	
	TestSuite( const std::string& description );
	
	template <typename UnitTestType>
	void AddTestClass()
	{
		AddTestClass( std::make_shared<UnitTestType>() );
	}
	
	void AddTestClass( TestClassPtr test_class );

private:
	
	std::vector<TestClassPtr> _test_classes;

	ResultPrinterPtr _result_printer;
	
	TestSuiteResult _result;
};

typedef std::shared_ptr<TestSuite> TestSuitePtr;

}

}
