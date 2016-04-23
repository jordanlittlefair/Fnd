#include "OptimalPathFinder.hpp"

using namespace Fnd::SystemManager;

OptimalPathFinder::Node::Node():
	graph_node(nullptr),
	added_to_path(false)
{
}

OptimalPathFinder::Node::Node( const std::shared_ptr<SystemGraphNode>& node ):
	graph_node(node),
	added_to_path(false)
{
}

OptimalPathFinder::OptimalPathFinder()
{
}

OptimalPathFinder::OptimalPathFinder( const std::vector<std::shared_ptr<SystemGraphNode>>& system_nodes ):
	_system_graph_nodes(system_nodes)
{	
}

void OptimalPathFinder::UpdateSystemGraphNodes( const std::vector<std::shared_ptr<SystemGraphNode>>& system_nodes )
{
	_system_graph_nodes = system_nodes;
}

void OptimalPathFinder::ClearSystemNodes()
{
	_system_graph_nodes.clear();
}

std::vector<ISystem::Id> OptimalPathFinder::GetOptimalPath() const
{
	std::vector<ISystem::Id> path;
	
	std::map<ISystem::Id,Node> nodes;
	
	for ( const auto& node : _system_graph_nodes )
	{
		nodes[node->GetId()] = Node(node);
	}
	
	for ( auto& node : nodes )
	{
		AddNodeAndDependencies( node.second, nodes, path );
	}
	
	return path;
}

void OptimalPathFinder::AddNodeAndDependencies( Node& node, std::map<ISystem::Id,Node>& nodes, std::vector<ISystem::Id>& path ) const
{
	if ( node.added_to_path )
	{
		return;
	}
	
	for ( auto& dependency : node.graph_node->GetPrev() )
	{
		if ( !nodes[dependency].added_to_path )
		{
			AddNodeAndDependencies( nodes[dependency], nodes, path );
		}
	}
	
	path.push_back( node.graph_node->GetId() );
	
	node.added_to_path = true;
}
