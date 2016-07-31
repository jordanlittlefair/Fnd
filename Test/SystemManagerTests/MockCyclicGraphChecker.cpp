#include "MockCyclicGraphChecker.hpp"

using namespace Fnd::Test;
using namespace Fnd::Test::SystemManager;
using namespace Fnd::SystemManager;

MockCyclicGraphChecker::MockCyclicGraphChecker():
	_is_cyclic(false)
{
}

void MockCyclicGraphChecker::SetIsCyclicResult(const bool is_cyclic)
{
	_is_cyclic = is_cyclic;
}

void MockCyclicGraphChecker::UpdateSystemGraphNodes(const std::vector<std::shared_ptr<SystemGraphNode>>& system_nodes)
{

}

void MockCyclicGraphChecker::ClearSystemNodes()
{
	
}

bool MockCyclicGraphChecker::IsCyclic() const
{
	return _is_cyclic;
}
