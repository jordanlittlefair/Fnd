#pragma once

#include "ISystem.hpp"
#include "ISystemContainer.hpp"
#include "ISystemGraph.hpp"

#include <vector>

namespace Fnd
{

namespace SystemManager
{

class SystemContainer:
	public ISystemContainer
{
public:
	
	SystemContainer();
	
	void SetSystemGraph(SystemGraphPtr system_graph);
	
	void SetTaskProvider(TaskProviderPtr task_provider);
	
	void AddSystem(SystemPtr system);
	
	// Get the systems in their optimal path order
	const std::vector<SystemPtr>& GetOrderedSystems() const;
	
private:
	
	void CalculateOptimalPath();
	
private:
	
	SystemGraphPtr _system_graph;
	
	TaskProviderPtr _task_provider;
	
	std::vector<SystemPtr> _systems;
	
	std::vector<SystemPtr> _optimal_path;
};

}

}
