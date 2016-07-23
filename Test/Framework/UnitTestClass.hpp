#pragma once

#include "TestClass.hpp"

namespace Fnd
{
	
namespace Test
{

class UnitTestClass:
	public TestClass
{
protected:
	
	UnitTestClass(const std::string& description);
};
	
}

}
