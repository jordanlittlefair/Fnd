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
	
	bool IsInitialised() const;
	
	void AddSystem(SystemPtr system);
	
	void Initialise();
	
	// Get the systems in their optimal path order
	const std::vector<SystemPtr>& GetOrderedSystems() const;
	
private:
	
	void CalculateOptimalPath();
	
private:
	
	bool _is_initialised;
	
	SystemGraphPtr _system_graph;
	
	TaskProviderPtr _task_provider;
	
	std::vector<SystemPtr> _systems;
	
	std::vector<SystemPtr> _optimal_path;
};

}

}
