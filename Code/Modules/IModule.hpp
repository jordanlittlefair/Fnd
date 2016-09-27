#pragma once

#include "../EntitySystem/IComponentManager.hpp"
#include "../EntitySystem/INodeManager.hpp"
#include "../SystemManager/ISystemManager.hpp"

namespace Fnd
{

namespace Modules
{

class IModule
{
public:
	
	virtual std::string GetName() const = 0;
	
	virtual void RegisterComponents(EntitySystem::IComponentManager& component_manager) = 0;
	
	virtual void RegisterNodes(EntitySystem::INodeManager& node_manager) = 0;
	
	virtual void RegisterSystems(SystemManager::ISystemManager& system_manager) = 0;
	
	virtual ~IModule() {}
};

}

}
