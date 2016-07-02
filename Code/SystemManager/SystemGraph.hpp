#pragma once

#include "ISystem.hpp"
#include "SystemGraphNode.hpp"

#include <map>

namespace Fnd
{

namespace SystemManager
{

class SystemGraph
{
public:

	SystemGraph();
	
	void UpdateSystemNodes( const std::vector<std::shared_ptr<ISystem>>& systems );
	
protected:

	const std::vector<std::shared_ptr<SystemGraphNode>>& GetSystemNodes() const;
	
private:

	std::shared_ptr<SystemGraphNode> GetNode( const SystemId& id ) const;
	
	bool ContainsDuplicateSystemIds( const std::vector<std::shared_ptr<ISystem>>& systems );

	bool IsGraphCyclic() const;

	std::vector<std::shared_ptr<SystemGraphNode>> _system_nodes;
};

}

}
