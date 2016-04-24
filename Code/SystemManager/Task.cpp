#include "Task.hpp"

using namespace Fnd::SystemManager;

Task::Task( SystemPtr parent_system ):
	_parent_system(parent_system),
	_state(State::Pending)
{
}

Task::State Task::GetState() const
{
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
	_state = state;
}
