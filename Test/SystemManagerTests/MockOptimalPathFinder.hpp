#pragma once

#include "../../Code/SystemManager/IOptimalPathFinder.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{

class MockOptimalPathFinder:
	public Fnd::SystemManager::IOptimalPathFinder
{
public:
	
	MockOptimalPathFinder();
	
	void UpdateSystemGraphNodes(const std::vector<std::shared_ptr<Fnd::SystemManager::SystemGraphNode>>& system_nodes);
	
	void ClearSystemGraphNodes();
	
	std::vector<Fnd::SystemManager::SystemId> GetOptimalPath() const;
	
private:
	
	std::vector<Fnd::SystemManager::SystemId> _optimal_path; // Not optimal - just in the order given
};

}

}

}
