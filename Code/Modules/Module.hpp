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

	void RegisterSystems(SystemManager::SystemManagerPtr system_manager) const;

protected:

	Module(const std::string& name);

protected:

	virtual std::vector<SystemManager::SystemPtr> OnGetSystems() const = 0;

private:

	const std::string _name;
};

}

}
