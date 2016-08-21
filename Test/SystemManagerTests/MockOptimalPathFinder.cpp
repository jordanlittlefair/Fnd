#include "MockOptimalPathFinder.hpp"

using namespace Fnd::Test;
using namespace Fnd::Test::SystemManager;
using namespace Fnd::SystemManager;

MockOptimalPathFinder::MockOptimalPathFinder()
{
	
}

void MockOptimalPathFinder::UpdateSystemGraphNodes(const std::vector<std::shared_ptr<Fnd::SystemManager::SystemGraphNode>>& system_nodes)
{
	ClearSystemGraphNodes();
	
	for (auto& system_node : system_nodes)
	{
		_optimal_path.push_back(system_node->GetId());
	}
}

void MockOptimalPathFinder::ClearSystemGraphNodes()
{
	_optimal_path.clear();
}

std::vector<Fnd::SystemManager::SystemId> MockOptimalPathFinder::GetOptimalPath() const
{
	return _optimal_path;
}
