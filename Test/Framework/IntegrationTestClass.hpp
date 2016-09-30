#pragma once

#include "TestClass.hpp"

namespace Fnd
{

namespace Test
{

class IntegrationTestClass:
	public TestClass
{
protected:
	
	IntegrationTestClass(const std::string& description);
	
	std::string GetTestClassDirectory() const;
	
	std::string GetTestCaseDirectory() const;
	
	virtual void SetupClass();
	
	virtual void CleanupClass();
	
	virtual void SetupTest(const std::string& test_description);
	
	virtual void CleanupTest(const std::string& test_description);
	
private:
	
	std::string _current_test;
};

}

}
