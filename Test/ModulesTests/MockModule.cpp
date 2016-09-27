#include "MockModule.hpp"

using namespace Fnd::Test::Modules;
using namespace Fnd::Modules;

MockModule::MockModule(const std::string& name):
	Module(name),
	_initialise_should_throw(false)
{
}

void MockModule::SetThrowException()
{
	_initialise_should_throw = true;
}

void MockModule::OnRegisterComponents(EntitySystem::IComponentManager& component_manager)
{
	
}

void MockModule::OnRegisterNodes(EntitySystem::INodeManager& node_manager)
{
	
}

void MockModule::OnRegisterSystems(SystemManager::ISystemManager& system_manager)
{
	
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
