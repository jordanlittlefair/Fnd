#include "MockSystemGraph.hpp"

using namespace Fnd::Test::SystemManager;
using namespace Fnd::SystemManager;

void MockSystemGraph::UpdateSystemNodes(const std::vector<Fnd::SystemManager::SystemPtr>& systems)
{
	_systems.clear();
	
	for (auto system : systems)
	{
		_systems.push_back(system->GetId());
	}
}

std::vector<Fnd::SystemManager::SystemId> MockSystemGraph::GetOptimalPath() const
{
	return _systems;
}
