#include "System.hpp"

#include "Exceptions.hpp"

#include <cassert>

using namespace Fnd::SystemManager;

System::System(const SystemId& id, const std::string& name):
	_id(id),
	_name(name),
	_is_initialised(false)
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

std::string System::GetName() const
{
	return _name;
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

bool System::IsInitialised() const
{
	return _is_initialised;
}

void System::Initialise()
{
	if (_is_initialised)
	{
		throw InvalidOperationException();
	}
	
	OnInitialise();
	
	_is_initialised = true;
}

void System::Run()
{
	if (!_is_initialised)
	{
		throw InvalidOperationException();
	}
	
	OnRun();
	
	WaitForSystemTasks();
}

SystemPtr System::This()
{
	return shared_from_this();
}

bool System::HasTaskProvider() const
{
	return _task_provider != nullptr;
}

void System::SubmitTask(TaskPtr task)
{
	if (HasTaskProvider())
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
	if (HasTaskProvider())
	{
		SystemId system_ids[] = { _id };
	
		_task_provider->WaitForTasks(system_ids, sizeof(system_ids)/sizeof(SystemId));
	}
}

System::~System()
{
}
