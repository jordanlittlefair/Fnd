#pragma once

#include "../../Code/SystemManager/ITaskConsumer.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{

class MockTaskConsumer:
	public Fnd::SystemManager::ITaskConsumer
{
public:
	
	MockTaskConsumer();
	
	void SetTaskProvider(Fnd::SystemManager::TaskProviderPtr task_provider);
	
	bool IsAlive() const;
	
	void Start();
	
	void Kill();
	
private:
	
	bool _is_alive;
};

}

}

}
