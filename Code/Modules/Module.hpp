#pragma once

#include "IModule.hpp"

namespace Fnd
{

namespace Modules
{

class Module:
	public IModule
	
{
public:

	std::string GetName() const;

	void RegisterComponents(EntitySystem::IComponentManager& component_manager);

	void RegisterNodes(EntitySystem::INodeManager& node_manager);

	void RegisterSystems(SystemManager::ISystemManager& system_manager);

protected:

	Module(const std::string& name);

protected:

	virtual void OnRegisterComponents(EntitySystem::IComponentManager& component_manager);
	
	virtual void OnRegisterNodes(EntitySystem::INodeManager& node_manager);
	
	virtual void OnRegisterSystems(SystemManager::ISystemManager& system_manager);

private:

	const std::string _name;
};

}

}
