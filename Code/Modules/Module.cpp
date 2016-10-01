#include "Module.hpp"

#include "Exceptions.hpp"

using namespace Fnd::EntitySystem;
using namespace Fnd::Modules;
using namespace Fnd::SystemManager;

Module::Module(const std::string& name):
	_name(name),
	_is_initialised(false)
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

bool Module::IsInitialised() const
{
	return _is_initialised;
}

void Module::Initialise()
{
	if (_is_initialised)
	{
		throw Modules::InvalidOperationException("Module is already initialised");
	}
	
	// OnInitialise(...) must cast the config to the appropriate derived config type and read any data needed to initialise itself
	OnInitialise(OnGetModuleConfig());
	
	_is_initialised = true;
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
