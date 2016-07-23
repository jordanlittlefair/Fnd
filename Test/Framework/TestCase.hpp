#pragma once

#include "IResultPrinter.hpp"
#include "TestCaseResult.hpp"

#include <functional>
#include <memory>
#include <sstream>

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
	
	template <typename A, typename B>
	void AssertEqual(const A& expected, const B& real, const std::string& description = "")
	{
		std::stringstream ss;
		
		ss << "Expected [" << expected << "] must equal Real [" << real << "]";
		
		if (!description.empty())
		{
			ss << ": " << description;
		}
		
		Assert(expected == real, ss.str());
	}
	
	template <typename A, typename B>
	void AssertNotEqual(const A& expected, const B& real, const std::string& description = "")
	{
		std::stringstream ss;
		
		ss << "Expected [" << expected << "] must not equal Real [" << real << "]";
		
		if (!description.empty())
		{
			ss << ": " << description;
		}
		
		Assert(expected != real, ss.str());
	}
	
	template<typename ExceptionType,typename LambdaType>
	void AssertException(LambdaType lambda)
	{
		bool exception_caught = false;
		try
		{
			lambda();
		}
		catch (const ExceptionType&)
		{
			exception_caught = true;
		}
		Assert(exception_caught);
	}

	const TestCaseResult& GetResult() const;
	
	virtual ~TestCase();

private:

	TestFunction _function;

	ResultPrinterPtr _result_printer;
	
	TestCaseResult _result;
};

typedef std::shared_ptr<TestCase> TestCasePtr;

}

}
