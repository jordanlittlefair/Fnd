#pragma once

#pragma once

#include "../../Code/SystemManager/SystemGraph.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{

class MockSystemGraph:
	public Fnd::SystemManager::SystemGraph
{
public:

	const std::vector<std::shared_ptr<Fnd::SystemManager::SystemGraphNode>> GetSystemNodes() const;
};

}

}

}
