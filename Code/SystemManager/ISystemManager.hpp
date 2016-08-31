#pragma once

#include <memory>

namespace Fnd
{
	
namespace SystemManager
{

class ISystemManager
{
public:
	
	virtual bool IsInitialised() const = 0;
	
	virtual bool IsAlive() const = 0;
	
	virtual void AddSystem(SystemPtr system) = 0;
	
	virtual void Initialise() = 0;
	
	virtual void Start() = 0;
	
	virtual void Run() = 0;
	
	virtual void Kill() = 0;
	
	virtual ~ISystemManager() {}
};
	
typedef std::shared_ptr<ISystemManager> SystemManagerPtr;
	
}
	
}
