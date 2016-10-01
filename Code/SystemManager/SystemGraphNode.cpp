#include "SystemGraphNode.hpp"

using namespace Fnd::SystemManager;

SystemGraphNode::SystemGraphNode( const SystemId& id ):
	_id(id),
	_weight(1)
{
}

SystemId SystemGraphNode::GetId() const
{
	return _id;
}

void SystemGraphNode::SetWeight( const Weight& weight )
{
	_weight = weight;
}

SystemGraphNode::Weight SystemGraphNode::GetWeight() const
{
	return _weight;
}

void SystemGraphNode::AddPrev( const SystemId& prev )
{
	if ( !ContainsPrev( prev ) )
	{
		_prev.push_back( prev );
	}
}

void SystemGraphNode::AddNext( const SystemId& next )
{
	if ( !ContainsNext( next ) )
	{
		_next.push_back( next );
	}
}

void SystemGraphNode::RemovePrev( const SystemId& id )
{
	for ( auto iter = _prev.begin(); iter != _prev.end(); ++iter )
	{
		if ( *iter == id )
		{
			_prev.erase( iter );
			return;
		}
	}
}

void SystemGraphNode::RemoveNext( const SystemId& id )
{
	for ( auto iter = _next.begin(); iter != _next.end(); ++iter )
	{
		if ( *iter == id )
		{
			_next.erase( iter );
			return;
		}
	}
}

void SystemGraphNode::ClearPrev()
{
	_prev.clear();
}

void SystemGraphNode::ClearNext()
{
	_next.clear();
}

bool SystemGraphNode::HasPrev() const
{
	return !_prev.empty();
}

bool SystemGraphNode::HasNext() const
{
	return !_next.empty();
}

bool SystemGraphNode::ContainsPrev( const SystemId& id ) const
{
	for ( const auto& prev : _prev )
	{
		if ( prev == id )
		{
			return true;
		}
	}
	
	return false;
}

bool SystemGraphNode::ContainsNext( const SystemId& id ) const
{
	for ( const auto& next : _next )
	{
		if ( next == id )
		{
			return true;
		}
	}
	
	return false;
}

const std::vector<SystemId>& SystemGraphNode::GetPrev() const
{
	return _prev;
}

const std::vector<SystemId>& SystemGraphNode::GetNext() const
{
	return _next;
}
