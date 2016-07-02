#pragma once

#include "ISystem.hpp"

#include <condition_variable>
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
	
	void Wait();
	
	bool WaitTimeout( const std::chrono::nanoseconds& timeout );

	void Run();
	
	SystemId	GetParentSystemId() const;
	
	void RethrowException();
	
protected:

	virtual void OnRun() = 0;
	
private:

	void SetState( const State state );
	
	std::condition_variable _completed_condition;
	mutable std::mutex _state_mutex;
	
	SystemPtr _parent_system;
	
	State _state;
	
	std::exception_ptr _exception;
};

typedef std::shared_ptr<Task> TaskPtr;
	
}

}
