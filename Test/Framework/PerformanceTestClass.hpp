#pragma once

#include "TestClass.hpp"

namespace Fnd
{

namespace Test
{

class PerformanceTestClass:
	public TestClass
{
protected:
	
	PerformanceTestClass(const std::string& description);
};

}

}
