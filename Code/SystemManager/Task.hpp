#pragma once

#include "ISystem.hpp"

#include <mutex>
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
		Complete
	};

	Task( SystemPtr parent_system );

	State GetState() const;

	void Run();
	
	SystemId GetParentSystemId() const;
	
protected:

	virtual void OnRun() = 0;
	
private:

	void SetState( const State state );
	
private:
	
	SystemPtr _parent_system;
	
	State _state;
	
	mutable std::mutex _state_mutex;
	
	std::exception_ptr _exception;
};

typedef std::shared_ptr<Task> TaskPtr;
	
}

}
