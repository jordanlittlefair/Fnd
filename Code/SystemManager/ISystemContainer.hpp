#pragma once

#include "ISystem.hpp"
#include "ISystemGraph.hpp"

#include <memory>
#include <vector>

namespace Fnd
{

namespace SystemManager
{

class ISystemContainer
{
public:
	
	virtual void SetTaskProvider(TaskProviderPtr task_provider) = 0;
	
	virtual bool IsInitialised() const = 0;
	
	virtual void AddSystem(SystemPtr system) = 0;
	
	virtual void Initialise() = 0;
	
	// Get the systems in their optimal path order
	virtual const std::vector<SystemPtr>& GetOrderedSystems() const = 0;
	
	virtual ~ISystemContainer() {}
};
	
typedef std::shared_ptr<ISystemContainer> SystemContainerPtr;

}

}
