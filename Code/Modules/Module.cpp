#include "Module.hpp"

using namespace Fnd::EntitySystem;
using namespace Fnd::Modules;
using namespace Fnd::SystemManager;

Module::Module(const std::string& name):
	_name(name)
{
}

std::string Module::GetName() const
{
	return _name;
}

void Module::RegisterComponents(IComponentManager& component_manager)
{
	OnRegisterComponents(component_manager);
}

void Module::RegisterNodes(INodeManager& node_manager)
{
	OnRegisterNodes(node_manager);
}

void Module::RegisterSystems(ISystemManager& system_manager)
{
	OnRegisterSystems(system_manager);
}

void Module::OnRegisterComponents(IComponentManager& component_manager)
{
	// Override if additional components are required for this module
}

void Module::OnRegisterNodes(INodeManager& node_manager)
{
	// Override if additional nodes are required for this module
}

void Module::OnRegisterSystems(ISystemManager& system_manager)
{
	// Override if additional systems are required for this module
}
