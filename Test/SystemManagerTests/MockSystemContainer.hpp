#pragma once

#include "../../Code/SystemManager/ISystemContainer.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{

class MockSystemContainer:
	public Fnd::SystemManager::ISystemContainer
{
public:
	
	MockSystemContainer();
	
	void SetTaskProvider(Fnd::SystemManager::TaskProviderPtr task_provider);
	
	bool IsInitialised() const { return true; }
	
	void AddSystem(Fnd::SystemManager::SystemPtr system);
	
	void Initialise() {}
	
	const std::vector<Fnd::SystemManager::SystemPtr>& GetOrderedSystems() const;
	
private:
	
	Fnd::SystemManager::TaskProviderPtr _task_provider;
	
	std::vector<Fnd::SystemManager::SystemPtr> _systems;
};

}

}

}
