#include "SystemManagerIntegrationTests.hpp"

#include "MockNameMappedSystem.hpp"

using namespace Fnd::Test;
using namespace Fnd::Test::SystemManager;
using namespace Fnd::SystemManager;

SystemManagerIntegrationTests::SystemManagerIntegrationTests():
	IntegrationTestClass("SystemManagerIntegrationTests")
{
	AddTestCase("Initialise_Start_Kill_Success", &SystemManagerIntegrationTests::Initialise_Start_Kill_Success, this);
	AddTestCase("Add_Initialise_Run_Systems_InOrder", &SystemManagerIntegrationTests::Add_Initialise_Run_Systems_InOrder, this);
}

std::shared_ptr<SystemManagerIntegrationTests::IntegratedSystemManagerClasses> SystemManagerIntegrationTests::GetClasses() const
{
	std::shared_ptr<IntegratedSystemManagerClasses> classes = std::make_shared<IntegratedSystemManagerClasses>();
	
	auto system_manager = std::make_shared<class SystemManager>();
	auto system_container = std::make_shared<SystemContainer>();
	auto system_id_from_name_generator = std::make_shared<SystemIdFromNameGenerator>();
	auto system_id_name_mapper = std::make_shared<SystemIdNameMapper>(system_id_from_name_generator);
	auto optimal_path_finder = std::make_shared<OptimalPathFinder>();
	auto cyclic_graph_checker = std::make_shared<CyclicGraphChecker>();
	auto system_graph = std::make_shared<SystemGraph>();
	auto task_provider = std::make_shared<TaskQueue>();
	auto task_consumer = std::make_shared<ConcurrentTaskProcessor>(4);
	auto task_manager = std::make_shared<TaskManager>();
	
	system_graph->SetOptimalPathFinder(optimal_path_finder);
	system_graph->SetCyclicGraphChecker(cyclic_graph_checker);
	
	system_container->SetSystemGraph(system_graph);
	
	task_manager->SetTaskProvider(task_provider);
	task_manager->SetTaskConsumer(task_consumer);
	
	system_manager->SetSystemContainer(system_container);
	system_manager->SetSystemIdNameMapper(system_id_name_mapper);
	system_manager->SetTaskManager(task_manager);

	classes->system_manager = system_manager;
	classes->system_container = system_container;
	classes->system_id_from_name_generator = system_id_from_name_generator;
	classes->system_id_name_mapper = system_id_name_mapper;
	classes->optimal_path_finder = optimal_path_finder;
	classes->cyclic_graph_checker = cyclic_graph_checker;
	classes->system_graph = system_graph;
	classes->task_provider = task_provider;
	classes->task_consumer = task_consumer;
	classes->task_manager = task_manager;
	
	return classes;
}

void SystemManagerIntegrationTests::Initialise_Start_Kill_Success(TestCase& test_case)
{
	auto classes = GetClasses();
	auto system_manager = classes->system_manager;
	
	test_case.Assert(!system_manager->IsInitialised());
	test_case.Assert(!system_manager->IsAlive());
	
	system_manager->Initialise();
	
	test_case.Assert(system_manager->IsInitialised());
	test_case.Assert(!system_manager->IsAlive());
	
	classes->system_manager->Start();
	
	test_case.Assert(system_manager->IsInitialised());
	test_case.Assert(system_manager->IsAlive());
	
	system_manager->Kill();
	
	test_case.Assert(system_manager->IsInitialised());
	test_case.Assert(!system_manager->IsAlive());
}

void SystemManagerIntegrationTests::Add_Initialise_Run_Systems_InOrder(TestCase& test_case)
{
	class OrderedSystem:
		public MockNameMappedSystem
	{
	public:
		OrderedSystem(std::vector<SystemId>& run_order, Fnd::SystemManager::SystemIdNameMapperPtr system_id_name_mapper, const std::string& name):
			MockNameMappedSystem(system_id_name_mapper, name),
			_run_order(run_order),
			_run_count(0)
		{
		}
		unsigned int GetRunCount() const
		{
			return _run_count;
		}
	protected:
		void OnRun()
		{
			_run_order.push_back(GetId());
			
			++_run_count;
		}
	private:
		std::vector<SystemId>& _run_order;
		unsigned int _run_count;
	};
	
	auto classes = GetClasses();
	auto system_manager = classes->system_manager;
	
	std::vector<SystemId> run_order;
	
	auto system0 = std::make_shared<OrderedSystem>(run_order, classes->system_id_name_mapper, "System Zero");
	auto system1 = std::make_shared<OrderedSystem>(run_order, classes->system_id_name_mapper, "System One");
	auto system2 = std::make_shared<OrderedSystem>(run_order, classes->system_id_name_mapper, "System Two");
	
	system0->AddDependency(system1->GetId());
	system1->AddDependency(system2->GetId());
	
	system_manager->AddSystem(system0);
	system_manager->AddSystem(system1);
	system_manager->AddSystem(system2);
	
	system_manager->Initialise();
	
	test_case.Assert(system0->IsInitialised());
	test_case.Assert(system1->IsInitialised());
	test_case.Assert(system2->IsInitialised());
	
	system_manager->Start();
	
	for (unsigned int i = 0; i < 10; ++i)
	{
		test_case.AssertEqual(i, system0->GetRunCount());
		test_case.AssertEqual(i, system1->GetRunCount());
		test_case.AssertEqual(i, system2->GetRunCount());
		
		system_manager->Run();
		
		test_case.Assert(run_order[(i * 3) + 0] == system2->GetId());
		test_case.Assert(run_order[(i * 3) + 1] == system1->GetId());
		test_case.Assert(run_order[(i * 3) + 2] == system0->GetId());
	}
	
	system_manager->Kill();
}
