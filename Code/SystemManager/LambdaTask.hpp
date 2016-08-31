#pragma once

#include "Task.hpp"

namespace Fnd
{

namespace SystemManager
{

template <typename LambdaType>
class LambdaTask:
	public Task
{
public:

	LambdaTask( SystemPtr parent_system, LambdaType lambda ):
		Task(parent_system),
		_lambda(lambda)
	{
	}
	
protected:

	void OnRun()
	{
		return _lambda();
	}
	
private:

	LambdaType _lambda;
};

template <typename LambdaType>
TaskPtr CreateLambdaTask( SystemPtr parent_system, LambdaType lambda )
{
	return std::make_shared<LambdaTask<LambdaType>>( parent_system, lambda );
}

}

}
