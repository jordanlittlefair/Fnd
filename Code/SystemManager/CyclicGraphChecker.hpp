#pragma once

#include "SystemGraphNode.hpp"

#include <map>

namespace Fnd
{

namespace SystemManager
{

class CyclicGraphChecker
{
public:

	CyclicGraphChecker();
	
	CyclicGraphChecker( const std::vector<std::shared_ptr<SystemGraphNode>>& system_nodes );
	
	void UpdateSystemGraphNodes( const std::vector<std::shared_ptr<SystemGraphNode>>& system_nodes );
	
	void ClearSystemNodes();
	
	bool IsCyclic() const;
	
private:

	struct Node
	{
		enum class State
		{
			NotExplored,
			BeingExlored,
			FullyExplored
		};
		
		std::shared_ptr<SystemGraphNode> graph_node;
		
		State state;
		
		Node();
		
		Node( const std::shared_ptr<SystemGraphNode>& node_ );
	};
	
	bool IsCyclicDFS( Node& node, std::map<ISystem::Id,Node>& nodes ) const;
	
	std::vector<std::shared_ptr<SystemGraphNode>> _system_graph_nodes;
};

}

}
