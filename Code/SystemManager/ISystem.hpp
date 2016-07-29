#pragma once

#include "SystemId.hpp"

#include <memory>
#include <string>
#include <vector>

namespace Fnd
{

namespace SystemManager
{
	
// Forward declare TaskProviderPtr
class ITaskProvider;
typedef std::shared_ptr<ITaskProvider> TaskProviderPtr;


class ISystem
{
public:
	
	virtual void SetTaskProvider(TaskProviderPtr task_provider) = 0;

	virtual SystemId GetId() const = 0;

	virtual const std::vector<SystemId>& GetDependencies() const = 0;
	
	virtual void Run() = 0;

	virtual ~ISystem() {}
};

typedef std::shared_ptr<ISystem> SystemPtr;

}

}
