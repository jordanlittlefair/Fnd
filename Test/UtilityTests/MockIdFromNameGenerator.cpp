#include "MockIdFromNameGenerator.hpp"

using namespace Fnd::Test::Utility;
using namespace Fnd::Utility;

int MockIdFromNameGenerator::GenerateIdFromName(const std::string& name) const
{	
	int sum = 0;
	
	for (char c : name)
	{
		sum += c;
	}
	
	return sum;
}
