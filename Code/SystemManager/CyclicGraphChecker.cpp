#include "CyclicGraphChecker.hpp"

using namespace Fnd::SystemManager;


CyclicGraphChecker::CyclicGraphChecker()
{
}

CyclicGraphChecker::CyclicGraphChecker( const std::vector<std::shared_ptr<SystemGraphNode>>& system_graph_nodes ):
	_system_graph_nodes(system_graph_nodes)
{
}

CyclicGraphChecker::Node::Node():
	state(State::NotExplored)
{
}

CyclicGraphChecker::Node::Node( const std::shared_ptr<SystemGraphNode>& node_ ):
	graph_node(node_),
	state(State::NotExplored)
{
}

void CyclicGraphChecker::UpdateSystemGraphNodes( const std::vector<std::shared_ptr<SystemGraphNode>>& system_graph_nodes )
{
	_system_graph_nodes = system_graph_nodes;
}

void CyclicGraphChecker::ClearSystemNodes()
{
	_system_graph_nodes.clear();
}

bool CyclicGraphChecker::IsCyclic() const
{
	std::map<ISystem::Id,Node> nodes;
	
	for ( const auto& node : _system_graph_nodes )
	{
		nodes[node->GetId()] = Node( node );
	}
	
	for ( auto& node : nodes )
	{
		if ( node.second.state != Node::State::FullyExplored )
		{
			if ( IsCyclicDFS( node.second, nodes ) )
			{
				return true;
			}
		}
	}
	
	return false;
}

bool CyclicGraphChecker::IsCyclicDFS( Node& node, std::map<ISystem::Id,Node>& nodes ) const
{
	node.state = Node::State::BeingExlored;
	
	bool is_cyclic = false;
	
	for ( auto& next : node.graph_node->GetNext() )
	{
		if ( nodes[next].state == Node::State::NotExplored )
		{
			is_cyclic = IsCyclicDFS( nodes[next], nodes );
		}
		else if ( nodes[next].state == Node::State::BeingExlored )
		{
			is_cyclic = true;
		}
		
		if ( is_cyclic )
		{
			break;
		}
	}
	
	node.state = Node::State::FullyExplored;
	
	return is_cyclic;
}
