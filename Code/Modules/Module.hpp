#pragma once

#include "../EntitySystem/ComponentManager.hpp"
#include "../EntitySystem/NodeManager.hpp"
#include "../SystemManager/ISystemManager.hpp"
#include "../SystemManager/ISystem.hpp"

namespace Fnd
{

namespace Modules
{

class Module
{
public:

	std::string GetName() const;

	void RegisterComponents(EntitySystem::ComponentManager& component_manager);

	void RegisterNodes(EntitySystem::NodeManager& node_manager);

	void RegisterSystems(SystemManager::SystemManagerPtr system_manager);

protected:

	Module(const std::string& name);

protected:

	virtual void OnRegisterComponents(EntitySystem::ComponentManager& component_manager);
	
	virtual void OnRegisterNodes(EntitySystem::NodeManager& node_manager);
	
	virtual void OnRegisterSystems(SystemManager::SystemManagerPtr system_manager);

private:

	const std::string _name;
};

}

}
