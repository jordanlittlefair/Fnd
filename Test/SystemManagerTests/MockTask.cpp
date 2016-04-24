#include "MockTask.hpp"

using namespace Fnd::Test::SystemManager;
using namespace Fnd::SystemManager;

MockTask::MockTask( Fnd::SystemManager::SystemPtr parent_system ):
	Task(parent_system),
	_on_run_hit_count(0)
{
}

unsigned int MockTask::GetOnRunHitCount() const
{
	return _on_run_hit_count;
}

void MockTask::OnRun()
{
	++_on_run_hit_count;
	_state_in_on_run = GetState();
	
	if ( _forced_exception )
	{
		std::rethrow_exception(_forced_exception);
	}
}

Task::State MockTask::GetStateInOnRun() const
{
	return _state_in_on_run;
}
