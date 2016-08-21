#pragma once

#include "../../Code/SystemManager/ICyclicGraphChecker.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{

class MockCyclicGraphChecker:
	public Fnd::SystemManager::ICyclicGraphChecker
{
public:
	
	MockCyclicGraphChecker();
	
	void SetIsCyclicResult(const bool is_cyclic);
	
	void UpdateSystemGraphNodes(const std::vector<std::shared_ptr<Fnd::SystemManager::SystemGraphNode>>& system_nodes);
	
	void ClearSystemNodes();
	
	bool IsCyclic() const;
	
private:
	
	bool _is_cyclic;
};

}

}

}
