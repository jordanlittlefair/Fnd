#pragma once

#include "MockModuleConfig.hpp"

#include "../../Code/Modules/IModuleConfig.hpp"
#include "../../Code/Modules/Module.hpp"

namespace Fnd
{

namespace Test
{

namespace Modules
{

class MockModule:
public Fnd::Modules::Module
{
public:
	
	MockModule(const std::string& name);
	
	void SetThrowException();

protected:
	
	void OnRegisterComponents(Fnd::EntitySystem::IComponentManager& component_manager);

	void OnRegisterNodes(Fnd::EntitySystem::INodeManager& node_manager);
	
	void OnRegisterSystems(Fnd::SystemManager::ISystemManager& system_manager);
	
	Fnd::Modules::IModuleConfig& OnGetModuleConfig();
	
	void OnInitialise(const Fnd::Modules::IModuleConfig& config);
	
private:
	
	bool _initialise_should_throw;
	
	MockModuleConfig _config;
};

}

}

}
