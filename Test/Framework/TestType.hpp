#pragma once

#include <cassert>
#include <string>

namespace Fnd
{
	
namespace Test
{

enum class TestType
{
	Unit,
	Integration,
	Performance
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
