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
};

}

}
