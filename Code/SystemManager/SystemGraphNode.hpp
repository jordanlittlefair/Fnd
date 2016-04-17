#pragma once

#include "ISystem.hpp"

#include <string>
#include <vector>

namespace Fnd
{

namespace SystemManager
{

class SystemGraphNode
{
public:

	typedef float Weight;
	
	SystemGraphNode( const ISystem::Id& id );
	
	ISystem::Id GetId() const;
	
	void SetWeight( const Weight& weight );
	
	Weight GetWeight() const;
	
	void AddPrev( const ISystem::Id& prev );
	
	void AddNext( const ISystem::Id& next );
	
	void RemovePrev( const ISystem::Id& id );
	
	void RemoveNext( const ISystem::Id& id );
	
	void ClearPrev();
	
	void ClearNext();
	
	bool HasPrev() const;
	
	bool HasNext() const;
	
	bool ContainsPrev( const ISystem::Id& id ) const;
	
	bool ContainsNext( const ISystem::Id& id ) const;
	
	const std::vector<ISystem::Id>& GetPrev() const;
	
	const std::vector<ISystem::Id>& GetNext() const;
	
private:
	
	const ISystem::Id _id;
	Weight _weight;
	std::vector<ISystem::Id> _prev;
	std::vector<ISystem::Id> _next;
};

}

}
