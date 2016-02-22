#pragma once

#include "TestCaseResult.hpp"

#include <functional>

namespace Fnd
{

namespace Test
{

class TestCase
{
public:

	typedef std::function<void(TestCase&)> TestFunction;

	TestCase( const std::string& name, TestFunction function );

	void Run();

	void Assert( bool succeeded, const std::string& description = "" );

	const TestCaseResult& GetResult() const;

private:

	TestFunction _function;

	std::string _name;

	TestCaseResult _result;

};

}

}
