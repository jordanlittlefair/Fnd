#pragma once

#include "IOptimalPathFinder.hpp"
#include "SystemGraphNode.hpp"

#include <map>

namespace Fnd
{

namespace SystemManager
{

class OptimalPathFinder:
	public IOptimalPathFinder
{
public:

	OptimalPathFinder();

	OptimalPathFinder( const std::vector<std::shared_ptr<SystemGraphNode>>& system_nodes );
	
	void UpdateSystemGraphNodes( const std::vector<std::shared_ptr<SystemGraphNode>>& system_nodes );
	
	void ClearSystemGraphNodes();
	
	std::vector<SystemId> GetOptimalPath() const;
	
private:

	struct Node
	{
		std::shared_ptr<SystemGraphNode> graph_node;
	
		bool added_to_path;
	
		Node();
	
		Node( const std::shared_ptr<SystemGraphNode>& node );
	};
	
	void AddNodeAndDependencies( Node& node, std::map<SystemId,Node>& nodes, std::vector<SystemId>& path ) const;

	std::vector<std::shared_ptr<SystemGraphNode>> _system_graph_nodes;
};

}

}
