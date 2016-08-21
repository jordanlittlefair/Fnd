#pragma once

#include "../Framework/IntegrationTestClass.hpp"

#include "../../Code/SystemManager/ConcurrentTaskProcessor.hpp"
#include "../../Code/SystemManager/CyclicGraphChecker.hpp"
#include "../../Code/SystemManager/NameMappedSystem.hpp"
#include "../../Code/SystemManager/OptimalPathFinder.hpp"
#include "../../Code/SystemManager/SystemContainer.hpp"
#include "../../Code/SystemManager/SystemGraph.hpp"
#include "../../Code/SystemManager/SystemManager.hpp"
#include "../../Code/SystemManager/TaskManager.hpp"
#include "../../Code/SystemManager/TaskQueue.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{

class SystemManagerIntegrationTests:
	public IntegrationTestClass
{
public:
	
	SystemManagerIntegrationTests();
	
private:
	
	struct IntegratedSystemManagerClasses
	{
		Fnd::SystemManager::SystemManagerPtr system_manager;
		Fnd::SystemManager::SystemContainerPtr system_container;
		Fnd::SystemManager::SystemIdFromNameGeneratorPtr system_id_from_name_generator;
		Fnd::SystemManager::SystemIdNameMapperPtr system_id_name_mapper;
		Fnd::SystemManager::OptimalPathFinderPtr optimal_path_finder;
		Fnd::SystemManager::CyclicGraphCheckerPtr cyclic_graph_checker;
		Fnd::SystemManager::SystemGraphPtr system_graph;
		Fnd::SystemManager::TaskProviderPtr task_provider;
		Fnd::SystemManager::TaskConsumerPtr task_consumer;
		Fnd::SystemManager::TaskManagerPtr task_manager;
	};
	
	std::shared_ptr<IntegratedSystemManagerClasses> GetClasses() const;
	
private:
	
	void Initialise_Start_Kill_Success(TestCase& test_case);
	void Add_Initialise_Run_Systems_InOrder(TestCase& test_case);
	void RunSystemsWithTasks(TestCase& test_case);
};

}

}

}
