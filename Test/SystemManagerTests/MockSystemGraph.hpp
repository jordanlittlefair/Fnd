#pragma once

#pragma once

#include "../../Code/SystemManager/ISystemGraph.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{

class MockSystemGraph:
	public Fnd::SystemManager::ISystemGraph
{
public:

	void UpdateSystemNodes(const std::vector<Fnd::SystemManager::SystemPtr>& systems);
	
	std::vector<Fnd::SystemManager::SystemId> GetOptimalPath() const;
	
private:
	
	std::vector<Fnd::SystemManager::SystemId> _systems;
};

}

}

}
