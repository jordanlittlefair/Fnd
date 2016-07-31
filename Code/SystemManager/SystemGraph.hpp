#pragma once

#include "IOptimalPathFinder.hpp"
#include "ISystem.hpp"
#include "SystemGraphNode.hpp"

#include <map>

namespace Fnd
{

namespace SystemManager
{

class SystemGraph
{
public:

	SystemGraph();
	
	void SetOptimalPathFinder(OptimalPathFinderPtr optimal_path_finder);
	
	void UpdateSystemNodes(const std::vector<SystemPtr>& systems);
	
	std::vector<SystemId> GetOptimalPath();
	
protected:

	const std::vector<std::shared_ptr<SystemGraphNode>>& GetSystemNodes() const;
	
private:

	std::shared_ptr<SystemGraphNode> GetNode(const SystemId& id) const;
	
	bool ContainsDuplicateSystemIds(const std::vector<std::shared_ptr<ISystem>>& systems);

	bool IsGraphCyclic() const;
	
private:
	
	OptimalPathFinderPtr _optimal_path_finder;

	std::vector<std::shared_ptr<SystemGraphNode>> _system_nodes;
};

}

}
