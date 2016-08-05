#include "SystemTests.hpp"

#include "MockSystem.hpp"

#include "../../Code/SystemManager/LambdaTask.hpp"
#include "../../Code/SystemManager/TaskManager.hpp"

using namespace Fnd::SystemManager;
using namespace Fnd::Test;
using namespace Fnd::Test::SystemManager;

SystemTests::SystemTests():
	UnitTestClass("SystemTests")
{
	AddTestCase( "GetId_Success", &SystemTests::GetId_Success, this );
	AddTestCase( "AddDependency_Success", &SystemTests::AddDependency_Success, this );
	AddTestCase( "AddDependency_DuplicateId_Fail", &SystemTests::AddDependency_DuplicateId_Fail, this );
	AddTestCase( "Run_NoTasks_Succeess", &SystemTests::Run_NoTasks_Succeess, this );
	AddTestCase( "Run_OneTaskSynchronous_Success", &SystemTests::Run_OneTaskSynchronous_Success, this );
	AddTestCase( "Run_TwoTasksSynchronous_Success", &SystemTests::Run_TwoTasksSynchronous_Success, this );
	AddTestCase( "Run_FiftyTasksSynchronous_Success", &SystemTests::Run_FiftyTasksSynchronous_Success, this );
	AddTestCase( "Run_OneTaskAsynchronous_Success", &SystemTests::Run_OneTaskAsynchronous_Success, this );
	AddTestCase( "Run_TwoTasksAsynchronous_Success", &SystemTests::Run_TwoTasksAsynchronous_Success, this );
	AddTestCase( "Run_FiftyTasksAsynchronous_Success", &SystemTests::Run_FiftyTasksAsynchronous_Success, this );
}

void SystemTests::GetId_Success( TestCase& test_case )
{
	const SystemId id = 123;
	
	MockSystem system( id );
	
	test_case.Assert( system.GetId() == id );
}

void SystemTests::AddDependency_Success( TestCase& test_case )
{
	const SystemId dep1 = 1;
	const SystemId dep2 = 2;

	MockSystem system( 0 );
	
	system.AddDependency( dep1 );
	
	test_case.Assert( system.GetDependencies().size() == 1 );
	test_case.Assert( std::find( system.GetDependencies().begin(), system.GetDependencies().end(), dep1 ) != system.GetDependencies().end() );
	test_case.Assert( std::find( system.GetDependencies().begin(), system.GetDependencies().end(), dep2 ) == system.GetDependencies().end() );
	
	system.AddDependency( dep2 );

	test_case.Assert( system.GetDependencies().size() == 2 );
	test_case.Assert( std::find( system.GetDependencies().begin(), system.GetDependencies().end(), dep1 ) != system.GetDependencies().end() );
	test_case.Assert( std::find( system.GetDependencies().begin(), system.GetDependencies().end(), dep2 ) != system.GetDependencies().end() );
}

void SystemTests::AddDependency_DuplicateId_Fail( TestCase& test_case )
{
	const SystemId dep1 = 1;
	
	MockSystem system(123);
	
	system.AddDependency( dep1 );
	
	test_case.Assert( system.GetDependencies().size() == 1 );
	test_case.Assert( std::find( system.GetDependencies().begin(), system.GetDependencies().end(), dep1 ) != system.GetDependencies().end() );
	
	system.AddDependency( dep1 );
	
	test_case.Assert( system.GetDependencies().size() == 1 );
	test_case.Assert( std::find( system.GetDependencies().begin(), system.GetDependencies().end(), dep1 ) != system.GetDependencies().end() );
}

void SystemTests::Run_NoTasks_Succeess(TestCase& test_case)
{
	struct TestData
	{
		bool system_has_ran;
	};
	
	class TestSystem:
		public MockSystem
	{
	public:
		TestSystem(TestData& test_data):
			MockSystem(123),
			_test_data(test_data)
		{
		}
	protected:
		void OnRun()
		{
			_test_data.system_has_ran = true;
		}
	private:
		TestData& _test_data;
	};
	
	TestData test_data;
	test_data.system_has_ran = false;
	
	SystemPtr system = std::make_shared<TestSystem>(test_data);
	system->Initialise();
	
	test_case.Assert(!test_data.system_has_ran, "System must not have ran");
	
	system->Run();
	
	test_case.Assert(test_data.system_has_ran, "System must have ran");
}

void SystemTests::Run_OneTaskSynchronous_Success(TestCase& test_case)
{
	struct TestData
	{
		bool task_has_ran;
	};
	
	class TestSystem:
	public MockSystem
	{
	public:
		TestSystem(TestData& test_data):
		MockSystem(123),
		_test_data(test_data)
		{
		}
	protected:
		void OnRun()
		{
			SubmitTask( CreateLambdaTask(This(), [&]()
			{
				_test_data.task_has_ran = true;
			}));
		}
	private:
		TestData& _test_data;
	};
	
	TestData test_data;
	test_data.task_has_ran = false;
	
	SystemPtr system = std::make_shared<TestSystem>(test_data);
	system->Initialise();
	
	test_case.Assert(!test_data.task_has_ran, "Task must not have ran");
	
	system->Run();
	
	test_case.Assert(test_data.task_has_ran, "Task must have ran");
}

void SystemTests::Run_TwoTasksSynchronous_Success(TestCase& test_case)
{
	struct TestData
	{
		bool system_has_ran[2];
	};
	
	class TestSystem:
	public MockSystem
	{
	public:
		TestSystem(TestData& test_data):
		MockSystem(123),
		_test_data(test_data)
		{
		}
	protected:
		void OnRun()
		{
			SubmitTask( CreateLambdaTask(This(), [&]()
			{
				_test_data.system_has_ran[0] = true;
			}));
			
			SubmitTask( CreateLambdaTask(This(), [&]()
			{
				_test_data.system_has_ran[1] = true;
			}));
		}
	private:
		TestData& _test_data;
	};
	
	TestData test_data;
	test_data.system_has_ran[0] = false;
	test_data.system_has_ran[1] = false;
	
	SystemPtr system = std::make_shared<TestSystem>(test_data);
	system->Initialise();
	
	test_case.Assert(!test_data.system_has_ran[0], "Task[0] must not have ran");
	test_case.Assert(!test_data.system_has_ran[1], "Task[1] must not have ran");
	
	system->Run();
	
	test_case.Assert(test_data.system_has_ran[0], "Task[0] must have ran");
	test_case.Assert(test_data.system_has_ran[1], "Task[1] must have ran");
}

void SystemTests::Run_FiftyTasksSynchronous_Success(TestCase& test_case)
{
	struct TestData
	{
		bool task_has_ran[50];
	};
	
	class TestSystem:
	public MockSystem
	{
	public:
		TestSystem(TestData& test_data):
		MockSystem(123),
		_test_data(test_data)
		{
		}
	protected:
		void OnRun()
		{
			for (unsigned int i = 0; i < 50; ++i)
			{
				SubmitTask( CreateLambdaTask(This(), [&,i]()
				{
					_test_data.task_has_ran[i] = true;
				}));
			}
		}
	private:
		TestData& _test_data;
	};
	
	TestData test_data;
	for (unsigned int i = 0; i < 50; ++i)
	{
		test_data.task_has_ran[i] = false;
	}
	
	SystemPtr system = std::make_shared<TestSystem>(test_data);
	system->Initialise();
	
	for (unsigned int i = 0; i < 50; ++i)
	{
		std::stringstream message;
		message << "Task[" << i << "] must not have ran";
		test_case.Assert(!test_data.task_has_ran[i], message.str());
	}
	
	system->Run();
		
	for (unsigned int i = 0; i < 50; ++i)
	{
		std::stringstream message;
		message << "Task[" << i << "] must have ran";
		test_case.Assert(test_data.task_has_ran[i], message.str());
	}
}

void SystemTests::Run_OneTaskAsynchronous_Success(TestCase& test_case)
{
	struct TestData
	{
		bool task_has_ran;
	};
	
	class TestSystem:
	public MockSystem
	{
	public:
		TestSystem(TestData& test_data):
		MockSystem(123),
		_test_data(test_data)
		{
		}
	protected:
		void OnRun()
		{
			SubmitTask( CreateLambdaTask(This(), [&]()
			{
				_test_data.task_has_ran = true;
			}));
		}
	private:
		TestData& _test_data;
	};
	
	TestData test_data;
	test_data.task_has_ran = false;
	
	SystemPtr system = std::make_shared<TestSystem>(test_data);
	system->Initialise();
	
	// Run the tasks inside of the TaskManager
	TaskManager task_manager;
	task_manager.Initialise();
	task_manager.Start();
	
	system->SetTaskProvider(task_manager.GetTaskProviderPtr());
	
	test_case.Assert(!test_data.task_has_ran, "Task must not have ran");
	
	system->Run();
	
	test_case.Assert(test_data.task_has_ran, "Task must have ran");
}

void SystemTests::Run_TwoTasksAsynchronous_Success(TestCase& test_case)
{
	struct TestData
	{
		bool system_has_ran[2];
	};
	
	class TestSystem:
	public MockSystem
	{
	public:
		TestSystem(TestData& test_data):
		MockSystem(123),
		_test_data(test_data)
		{
		}
	protected:
		void OnRun()
		{
			SubmitTask( CreateLambdaTask(This(), [&]()
			{
				_test_data.system_has_ran[0] = true;
			}));
			
			SubmitTask( CreateLambdaTask(This(), [&]()
			{
				_test_data.system_has_ran[1] = true;
			}));
		}
	private:
		TestData& _test_data;
	};
	
	TestData test_data;
	test_data.system_has_ran[0] = false;
	test_data.system_has_ran[1] = false;
	
	SystemPtr system = std::make_shared<TestSystem>(test_data);
	system->Initialise();
	
	// Run the tasks inside of the TaskManager
	TaskManager task_manager;
	task_manager.Initialise();
	task_manager.Start();
	
	system->SetTaskProvider(task_manager.GetTaskProviderPtr());
	
	test_case.Assert(!test_data.system_has_ran[0], "Task[0] must not have ran");
	test_case.Assert(!test_data.system_has_ran[1], "Task[1] must not have ran");
	
	system->Run();
	
	test_case.Assert(test_data.system_has_ran[0], "Task[0] must have ran");
	test_case.Assert(test_data.system_has_ran[1], "Task[1] must have ran");
}

void SystemTests::Run_FiftyTasksAsynchronous_Success(TestCase& test_case)
{
	struct TestData
	{
		bool task_has_ran[50];
	};
	
	class TestSystem:
	public MockSystem
	{
	public:
		TestSystem(TestData& test_data):
		MockSystem(123),
		_test_data(test_data)
		{
		}
	protected:
		void OnRun()
		{
			for (unsigned int i = 0; i < 50; ++i)
			{
				SubmitTask( CreateLambdaTask(This(), [&,i]()
				{
					_test_data.task_has_ran[i] = true;
				}));
			}
		}
	private:
		TestData& _test_data;
	};
	
	TestData test_data;
	for (unsigned int i = 0; i < 50; ++i)
	{
		test_data.task_has_ran[i] = false;
	}
	
	SystemPtr system = std::make_shared<TestSystem>(test_data);
	system->Initialise();
	
	// Run the tasks inside of the TaskManager
	TaskManager task_manager;
	task_manager.Initialise();
	task_manager.Start();
	
	system->SetTaskProvider(task_manager.GetTaskProviderPtr());
	
	for (unsigned int i = 0; i < 50; ++i)
	{
		std::stringstream message;
		message << "Task[" << i << "] must not have ran";
		test_case.Assert(!test_data.task_has_ran[i], message.str());
	}
	
	system->Run();
	
	for (unsigned int i = 0; i < 50; ++i)
	{
		std::stringstream message;
		message << "Task[" << i << "] must have ran";
		test_case.Assert(test_data.task_has_ran[i], message.str());
	}
}
