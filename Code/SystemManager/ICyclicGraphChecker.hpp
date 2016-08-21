#pragma once

#include "SystemGraphNode.hpp"

#include <map>
#include <memory>

namespace Fnd
{

namespace SystemManager
{

class ICyclicGraphChecker
{
public:
	
	virtual void UpdateSystemGraphNodes(const std::vector<std::shared_ptr<SystemGraphNode>>& system_nodes) = 0;
	
	virtual void ClearSystemNodes() = 0;
	
	virtual bool IsCyclic() const = 0;
	
	virtual ~ICyclicGraphChecker() {}
};
	
typedef std::shared_ptr<ICyclicGraphChecker> CyclicGraphCheckerPtr;

}

}
