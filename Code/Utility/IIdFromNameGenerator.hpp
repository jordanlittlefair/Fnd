#pragma once

#include <string>

namespace Fnd
{
	
namespace Utility
{

template <typename IdType>
class IIdFromNameGenerator
{
public:
	
	virtual IdType GenerateIdFromName(const std::string& name) const = 0;
	
	virtual ~IIdFromNameGenerator() {}
};

}
	
}
