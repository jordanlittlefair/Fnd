#include "MockModule.hpp"

using namespace Fnd::Test::Modules;
using namespace Fnd::Modules;

MockModule::MockModule(const std::string& name):
	Module(name),
	_initialise_should_throw(false),
	_has_registered_components(false),
	_has_registered_nodes(false),
	_has_registered_systems(false)
{
}

void MockModule::SetThrowException()
{
	_initialise_should_throw = true;
}


bool MockModule::HasRegisteredComponents() const
{
	return _has_registered_components;
}

bool MockModule::HasRegisteredNodes() const
{
	return _has_registered_nodes;
}

bool MockModule::HasRegisteredSystems() const
{
	return _has_registered_systems;
}

void MockModule::OnRegisterComponents(Fnd::EntitySystem::IComponentManager& component_manager)
{
	_has_registered_components = true;
}

void MockModule::OnRegisterNodes(Fnd::EntitySystem::INodeManager& node_manager)
{
	_has_registered_nodes = true;
}

void MockModule::OnRegisterSystems(Fnd::SystemManager::ISystemManager& system_manager)
{
	_has_registered_systems = true;
}

IModuleConfig& MockModule::OnGetModuleConfig()
{
	return _config;
}

void MockModule::OnInitialise(const IModuleConfig& config)
{
	if (_initialise_should_throw)
	{
		throw std::runtime_error("Exception in OnInitialise");
	}
}
