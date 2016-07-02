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
	
	SystemId GetId() const;
	
	void AddDependency( const SystemId& dependency );
	
	const std::vector<SystemId>& GetDependencies() const;
	
	~System();
	
protected:

	System( const SystemId& id );
	
private:

	const SystemId _id;

	std::vector<SystemId> _dependencies;
};

}

}
