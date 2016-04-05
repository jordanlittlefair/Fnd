#pragma once

#include "TestCaseResult.hpp"

#include <functional>

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

	void Run();

	void Assert( bool succeeded, const std::string& description = "" );

	const TestCaseResult& GetResult() const;

private:

	TestCaseResult _result;

	TestFunction _function;
};

}

}
