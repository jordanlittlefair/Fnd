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
	
	SystemGraphNode( const SystemId& id );
	
	SystemId GetId() const;
	
	void SetWeight( const Weight& weight );
	
	Weight GetWeight() const;
	
	void AddPrev( const SystemId& prev );
	
	void AddNext( const SystemId& next );
	
	void RemovePrev( const SystemId& id );
	
	void RemoveNext( const SystemId& id );
	
	void ClearPrev();
	
	void ClearNext();
	
	bool HasPrev() const;
	
	bool HasNext() const;
	
	bool ContainsPrev( const SystemId& id ) const;
	
	bool ContainsNext( const SystemId& id ) const;
	
	const std::vector<SystemId>& GetPrev() const;
	
	const std::vector<SystemId>& GetNext() const;
	
private:
	
	const SystemId _id;
	Weight _weight;
	std::vector<SystemId> _prev;
	std::vector<SystemId> _next;
};

}

}
