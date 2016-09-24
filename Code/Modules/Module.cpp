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
	// TODO
}

void Module::RegisterNodes(NodeManager& node_manager)
{
	// TODO
}

void Module::RegisterSystems(SystemManagerPtr system_manager) const
{
	std::vector<SystemPtr> systems = OnGetSystems();

	for (auto& system : systems)
	{
		system_manager->AddSystem(system);
	}
}
