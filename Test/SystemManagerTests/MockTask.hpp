#pragma once

#include "../../Code/SystemManager/Task.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{

class MockTask:
	public Fnd::SystemManager::Task
{
public:
	
	MockTask( Fnd::SystemManager::SystemPtr parent_system );
	
	unsigned int GetOnRunHitCount() const;
	
	State GetStateInOnRun() const;
	
	template <typename ExceptionType>
	void SetForceError( const ExceptionType& ex )
	{
		try
		{
			throw ex;
		}
		catch (...)
		{
			_forced_exception = std::current_exception();
		}
	}
	
protected:

	void OnRun();
	
	unsigned int _on_run_hit_count;
	State _state_in_on_run;
	std::exception_ptr _forced_exception;
};

}

}

}
