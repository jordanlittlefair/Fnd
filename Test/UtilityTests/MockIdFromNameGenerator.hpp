#pragma once

#include "../../Code/Utility/IIdFromNameGenerator.hpp"

namespace Fnd
{

namespace Test
{

namespace Utility
{

class MockIdFromNameGenerator:
	public Fnd::Utility::IIdFromNameGenerator<int>
{
public:
	
	// Sum the chars - easy to produce clashes by using the same chars in a different order
	int GenerateIdFromName(const std::string& name) const;
};

}

}

}
