#pragma once

#include "IResultPrinter.hpp"
#include "TestCaseResult.hpp"

#include <functional>
#include <memory>

namespace Fnd
{

namespace Test
{

/**
	@brief A wrapper around a method used to test a single case.
	Created with a pointer to a method containing the test. 
	The method takes a pointer to this TestCase instance which can be used to Assert() various values and gather the result.
*/
class TestCase
{
public:

	typedef std::function<void(TestCase&)> TestFunction;

	TestCase( const std::string& description, TestFunction function );
	
	void SetResultPrinter( ResultPrinterPtr result_printer );
	
	void Run();

	void Assert( bool succeeded, const std::string& description = "" );

	const TestCaseResult& GetResult() const;

private:

	TestFunction _function;

	ResultPrinterPtr _result_printer;
	
	TestCaseResult _result;
};

typedef std::shared_ptr<TestCase> TestCasePtr;

}

}
