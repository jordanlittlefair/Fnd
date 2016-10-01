#pragma once

#include "../../Code/SystemManager/ITaskManager.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{

class MockTaskManager:
	public Fnd::SystemManager::ITaskManager
{
public:
	
	MockTaskManager();
	
	bool IsInitialised() const;
	
	void Initialise();
	
	bool IsAlive() const;
	
	void Start();
	
	void Kill();
	
	Fnd::SystemManager::TaskConsumerPtr GetTaskConsumerPtr();
	
	Fnd::SystemManager::TaskProviderPtr GetTaskProviderPtr();
	
private:
	
	bool _is_initialised;
	bool _is_alive;
};

}

}

}
