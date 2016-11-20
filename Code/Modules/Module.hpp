#pragma once

#include "IModule.hpp"
#include "IModuleConfig.hpp"

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
	
	bool IsInitialised() const;
	
	void Initialise();

protected:

	Module(const std::string& name);

protected:

	virtual void OnRegisterComponents(EntitySystem::IComponentManager& component_manager);
	
	virtual void OnRegisterNodes(EntitySystem::INodeManager& node_manager);
	
	virtual void OnRegisterSystems(SystemManager::ISystemManager& system_manager);
	
	virtual IModuleConfig* OnGetModuleConfig();
	
	virtual void OnInitialise(const IModuleConfig* config) = 0;

private:

	const std::string _name;
	
	bool _is_initialised;
};

}

}
