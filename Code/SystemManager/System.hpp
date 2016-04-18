#pragma once

#include "ISystem.hpp"

#include <string>
#include <vector>

namespace Fnd
{

namespace SystemManager
{

class System:
	public ISystem
{
public:
	
	Id GetId() const;
	
	void AddDependency( const Id& dependency );
	
	const std::vector<Id>& GetDependencies() const;
	
	~System();
	
protected:

	System( const Id& id );
	
private:

	const Id _id;

	std::vector<Id> _dependencies;
};

}

}
