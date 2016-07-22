#pragma once

#include <cassert>
#include <string>

namespace Fnd
{
	
namespace Test
{

enum class TestType
{
	Unit			= 1 << 0,
	Integration		= 1 << 1,
	Performance		= 1 << 2
};
	
inline std::string GetTestTypeString(const TestType type)
{
	switch (type)
	{
	case TestType::Unit:
		return "Unit";
	case TestType::Integration:
		return "Integration";
	case TestType::Performance:
		return "Performance";
	default:
		assert(!"Unknown TestType");
		return "Unknown";
	}
}
	
}
	
}
