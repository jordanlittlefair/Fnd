#pragma once

#include "SystemGraphNode.hpp"

#include <map>

namespace Fnd
{

namespace SystemManager
{

class OptimalPathFinder
{
public:

	OptimalPathFinder();

	OptimalPathFinder( const std::vector<std::shared_ptr<SystemGraphNode>>& system_nodes );
	
	void UpdateSystemGraphNodes( const std::vector<std::shared_ptr<SystemGraphNode>>& system_nodes );
	
	void ClearSystemNodes();
	
	std::vector<ISystem::Id> GetOptimalPath() const;
	
private:

	struct Node
	{
		std::shared_ptr<SystemGraphNode> graph_node;
	
		bool added_to_path;
	
		Node();
	
		Node( const std::shared_ptr<SystemGraphNode>& node );
	};
	
	void AddNodeAndDependencies( Node& node, std::map<ISystem::Id,Node>& nodes, std::vector<ISystem::Id>& path ) const;

	std::vector<std::shared_ptr<SystemGraphNode>> _system_graph_nodes;
};

}

}
