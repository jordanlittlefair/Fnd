#pragma once

#include "SystemGraphNode.hpp"

#include <map>

namespace Fnd
{

namespace SystemManager
{

class IOptimalPathFinder
{
public:
	
	virtual void UpdateSystemGraphNodes(const std::vector<std::shared_ptr<SystemGraphNode>>& system_nodes) = 0;
	
	virtual void ClearSystemGraphNodes() = 0;
	
	virtual std::vector<SystemId> GetOptimalPath() const = 0;
	
	virtual ~IOptimalPathFinder() {}
};

typedef std::shared_ptr<IOptimalPathFinder> OptimalPathFinderPtr;

}

}
