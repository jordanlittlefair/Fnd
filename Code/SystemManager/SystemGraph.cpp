#include "SystemGraph.hpp"

#include "Exceptions.hpp"

#include <cassert>
#include <map>
#include <iostream>

using namespace Fnd::SystemManager;

SystemGraph::SystemGraph()
{
}

void SystemGraph::UpdateSystemNodes( const std::vector<std::shared_ptr<ISystem>>& systems )
{
	_system_nodes.clear();
	
	if ( ContainsDuplicateSystemIds(systems) )
	{
		throw InvalidSystemIdException();
	}
	
	// A small helper method to check if a system exists
	auto SystemExists = [&] ( const ISystem::Id& id ) -> bool
	{
		for ( const auto& system : systems )
		{
			if ( system->GetId() == id )
			{
				return true;
			}
		}
		
		return false;
	};
	
	// Add each system as a node, and add its dependencies to the 'prev' list if it's an existing system
	
	for ( const auto& system : systems )
	{
		std::shared_ptr<SystemGraphNode> node = std::make_shared<SystemGraphNode>( system->GetId() );
		
		for ( const auto& dependency : system->GetDependencies() )
		{
			if ( SystemExists( dependency ) )
			{
				node->AddPrev( dependency );
			}
		}
		
		_system_nodes.push_back( node );
	}
	
	// Use the dependencies in the 'prev' list to set the 'next' list and fully link the graph
	
	for ( const auto& node : _system_nodes )
	{
		for ( const auto& prev : node->GetPrev() )
		{
			GetNode( prev )->AddNext( node->GetId() );
		}
	}
}

std::shared_ptr<SystemGraphNode> SystemGraph::GetNode( const ISystem::Id& id ) const
{
	for ( const auto& node : _system_nodes )
	{
		if ( node->GetId() == id )
		{
			return node;
		}
	}
	
	throw std::runtime_error( "Invalid Id" );
}

const std::vector<std::shared_ptr<SystemGraphNode>>& SystemGraph::GetSystemNodes() const
{
	return _system_nodes;
}

bool SystemGraph::ContainsDuplicateSystemIds( const std::vector<std::shared_ptr<ISystem>>& systems )
{
	for ( unsigned int i = 0; i < systems.size(); ++i )
	{
		for ( unsigned int j = i + 1; j < systems.size(); ++j )
		{
			if ( systems[i]->GetId() == systems[j]->GetId() )
			{
				return true;
			}
		}
	}
	
	return false;
}
