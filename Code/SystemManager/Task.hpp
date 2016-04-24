#pragma once

#include "ISystem.hpp"

#include <memory>

namespace Fnd
{
	
namespace SystemManager
{

class Task
{
public:

	enum class State
	{
		Pending,
		Running,
		Complete,
		ExceptionThrown
	};

	Task( SystemPtr parent_system );

	State GetState() const;

	void Run();
	
	ISystem::Id	GetParentSystemId() const;
	
	void RethrowException();
	
protected:

	virtual void OnRun() = 0;
	
private:

	void SetState( const State state );
	
	SystemPtr _parent_system;
	
	State _state;
	
	std::exception_ptr _exception;
};

typedef std::shared_ptr<Task> TaskPtr;
	
}

}
