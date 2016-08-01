#pragma once

#include "ICyclicGraphChecker.hpp"
#include "IOptimalPathFinder.hpp"
#include "ISystem.hpp"
#include "ISystemGraph.hpp"
#include "SystemGraphNode.hpp"

#include <map>

namespace Fnd
{

namespace SystemManager
{

class SystemGraph:
	public ISystemGraph
{
public:

	SystemGraph();
	
	void SetCyclicGraphChecker(CyclicGraphCheckerPtr cyclic_graph_checker);
	
	void SetOptimalPathFinder(OptimalPathFinderPtr optimal_path_finder);
	
	void UpdateSystemNodes(const std::vector<SystemPtr>& systems);
	
	std::vector<SystemId> GetOptimalPath() const;
	
protected:

	const std::vector<std::shared_ptr<SystemGraphNode>>& GetSystemNodes() const;
	
private:

	std::shared_ptr<SystemGraphNode> GetNode(const SystemId& id) const;
	
	bool ContainsDuplicateSystemIds(const std::vector<std::shared_ptr<ISystem>>& systems);

	bool IsGraphCyclic() const;
	
private:
	
	CyclicGraphCheckerPtr _cyclic_graph_checker;
	
	OptimalPathFinderPtr _optimal_path_finder;

	std::vector<std::shared_ptr<SystemGraphNode>> _system_nodes;
};

}

}
