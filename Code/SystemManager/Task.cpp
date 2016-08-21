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
		_exception = std::current_exception();
	}
}

SystemId	Task::GetParentSystemId() const
{
	return _parent_system->GetId();
}

void Task::SetState( const Fnd::SystemManager::Task::State state )
{
	std::lock_guard<std::mutex> lock(_state_mutex);
	
	_state = state;
}
