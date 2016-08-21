#include "MockSystem.hpp"

using namespace Fnd::SystemManager;
using namespace Fnd::Test::SystemManager;

MockSystem::MockSystem(const SystemId& id, const std::string& name):
	System(id,name)
{
}

bool MockSystem::HasTaskProvider() const
{
	return System::HasTaskProvider();
}

void MockSystem::OnInitialise()
{
}

void MockSystem::OnRun()
{
}
