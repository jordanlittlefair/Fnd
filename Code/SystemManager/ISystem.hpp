#pragma once

#include <string>
#include <vector>

namespace Fnd
{

namespace SystemManager
{

class ISystem
{
public:

	typedef std::string Id;

	virtual Id GetId() const = 0;

	virtual void AddDependency( const Id& dependency ) = 0;

	virtual const std::vector<Id>& GetDependencies() const = 0;

	virtual ~ISystem() {}
};

}

}