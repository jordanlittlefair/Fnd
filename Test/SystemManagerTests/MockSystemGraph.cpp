#include "MockSystemGraph.hpp"

using namespace Fnd::Test::SystemManager;
using namespace Fnd::SystemManager;

const std::vector<std::shared_ptr<SystemGraphNode>> MockSystemGraph::GetSystemNodes() const
{
	return SystemGraph::GetSystemNodes();
}
