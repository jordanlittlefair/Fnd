#include "MockTaskManager.hpp"


using namespace Fnd::Test::SystemManager;
using namespace Fnd::SystemManager;


MockTaskManager::MockTaskManager():
	_is_initialised(false),
	_is_alive(false)
{
}

bool MockTaskManager::IsInitialised() const
{
	return _is_initialised;
}

void MockTaskManager::Initialise()
{
	_is_initialised = true;
}

bool MockTaskManager::IsAlive() const
{
	return _is_alive;
}

void MockTaskManager::Start()
{
	_is_alive = true;
}

void MockTaskManager::Kill()
{
	_is_alive = false;
}

TaskConsumerPtr MockTaskManager::GetTaskConsumerPtr()
{
	return nullptr;
}

TaskProviderPtr MockTaskManager::GetTaskProviderPtr()
{
	return nullptr;
}
