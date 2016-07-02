#pragma once

#include "SystemId.hpp"
#include <memory>
#include <string>
#include <vector>

namespace Fnd
{

namespace SystemManager
{

class ISystem
{
public:

	virtual SystemId GetId() const = 0;

	virtual const std::vector<SystemId>& GetDependencies() const = 0;

	virtual ~ISystem() {}
};

typedef std::shared_ptr<ISystem> SystemPtr;

}

}
