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

void Module::RegisterComponents(ComponentManager& component_manager)
{
	OnRegisterComponents(component_manager);
}

void Module::RegisterNodes(NodeManager& node_manager)
{
	OnRegisterNodes(node_manager);
}

void Module::RegisterSystems(SystemManagerPtr system_manager)
{
	OnRegisterSystems(system_manager);
}

void Module::OnRegisterComponents(ComponentManager& component_manager)
{
	// Override if additional components are required for this module
}

void Module::OnRegisterNodes(NodeManager& node_manager)
{
	// Override if additional nodes are required for this module
}

void Module::OnRegisterSystems(SystemManagerPtr system_manager)
{
	// Override if additional systems are required for this module
}
