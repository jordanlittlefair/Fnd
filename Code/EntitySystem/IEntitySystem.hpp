#pragma once

#include "IEntityManager.hpp"
#include "IComponentManager.hpp"
#include "INodeManager.hpp"

namespace Fnd
{
namespace EntitySystem
{

class IEntitySystem
{
public:

	virtual IEntityManager& GetEntityManager() = 0;
	virtual const IEntityManager& GetEntityManager() const = 0;

	virtual IComponentManager& GetComponentManager() = 0;
	virtual const IComponentManager& GetComponentManager() const = 0;

	virtual INodeManager& GetNodeManager() = 0;
	virtual const INodeManager& GetNodeManager() const = 0;
};

}
	
}
