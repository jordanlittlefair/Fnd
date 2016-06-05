#include "Task.hpp"

using namespace Fnd::SystemManager;

Task::Task( SystemPtr parent_system ):
	_parent_system(parent_system),
	_state(State::Pending)
{
}

Task::State Task::GetState() const
{
	std::lock_guard<std::mutex> lock(_state_mutex);
	
	return _state;
}

void Task::Wait()
{
	std::unique_lock<std::mutex> lock(_state_mutex);
	
	_completed_condition.wait( lock, [&]()
	{
		return _state == State::Complete || _state == State::ExceptionThrown;
	} );
}

bool Task::WaitTimeout( const std::chrono::nanoseconds& timeout )
{
	std::unique_lock<std::mutex> lock(_state_mutex);
	
	return _completed_condition.wait_for( lock, timeout, [&]()
	{
		return _state == State::Complete || _state == State::ExceptionThrown;
	} );
}

void Task::Run()
{
	SetState(State::Running);
	
	try
	{
		OnRun();
	
		SetState(State::Complete);
	}
	catch (...)
	{
		SetState(State::ExceptionThrown);
	
		_exception = std::current_exception();
	}
}

ISystem::Id	Task::GetParentSystemId() const
{
	return _parent_system->GetId();
}

void Task::RethrowException()
{
	std::rethrow_exception(_exception);
}

void Task::SetState( const Fnd::SystemManager::Task::State state )
{
	std::lock_guard<std::mutex> lock(_state_mutex);
	
	_state = state;
	
	_completed_condition.notify_all();
}
