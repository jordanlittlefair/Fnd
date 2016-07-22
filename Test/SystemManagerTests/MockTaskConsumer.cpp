#include "MockTaskConsumer.hpp"

using namespace Fnd::Test::SystemManager;
using namespace Fnd::SystemManager;

MockTaskConsumer::MockTaskConsumer():
	_is_alive(false)
{
}

void MockTaskConsumer::SetTaskProvider(TaskProviderPtr task_provider)
{
}

bool MockTaskConsumer::IsAlive() const
{
	return _is_alive;
}

void MockTaskConsumer::Start()
{
	_is_alive = true;
}

void MockTaskConsumer::Kill()
{
	_is_alive = false;
}
