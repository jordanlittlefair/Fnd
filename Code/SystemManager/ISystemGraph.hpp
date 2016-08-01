#pragma once

#include "ISystem.hpp"

#include <memory>

namespace Fnd
{

namespace SystemManager
{

class ISystemGraph
{
public:
	
	virtual void UpdateSystemNodes(const std::vector<SystemPtr>& systems) = 0;
	
	virtual std::vector<SystemId> GetOptimalPath() const = 0;
	
	virtual ~ISystemGraph() {}
};
	
typedef std::shared_ptr<ISystemGraph> SystemGraphPtr;

}

}
