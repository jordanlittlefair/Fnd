#include "System.hpp"

using namespace Fnd::SystemManager;

System::System( const SystemId& id ):
	_id(id)
{
}

void System::SetTaskProvider(TaskProviderPtr task_provider)
{
	_task_provider = task_provider;
}

SystemId System::GetId() const
{
	return _id;
}

void System::AddDependency( const SystemId& dependency )
{
	if ( std::find( _dependencies.begin(), _dependencies.end(), dependency ) == _dependencies.end() )
	{
		_dependencies.push_back( dependency );
	}
}

const std::vector<SystemId>& System::GetDependencies() const
{
	return _dependencies;
}

void System::Run()
{
	OnRun();
	
	WaitForSystemTasks();
}

SystemPtr System::This()
{
	return shared_from_this();
}

void System::SubmitTask(TaskPtr task)
{
	if (_task_provider)
	{
		_task_provider->SubmitTask(task);
	}
	else
	{
		task->Run();
	}
}

void System::WaitForSystemTasks()
{
	if (_task_provider)
	{
		SystemId system_ids[] = { _id };
	
		_task_provider->WaitForTasks(system_ids, sizeof(system_ids)/sizeof(SystemId));
	}
}

System::~System()
{
}
