#pragma once

#include "MockNode.hpp"

#include "../../Code/EntitySystem/NodeContainer.hpp"

#include <map>
#include <memory>

namespace Fnd
{

namespace Test
{

namespace EntitySystem
{

class MockNodeContainer:
	public Fnd::EntitySystem::NodeContainer
{
public:
	
	MockNodeContainer(const Fnd::EntitySystem::NodeId node_id);
	
	void AddNode(const MockNode& node);
	
protected:
	
	Fnd::EntitySystem::Node& OnCreateNode(const Fnd::EntitySystem::EntityId entity_id);
	
	bool OnHasNode(const Fnd::EntitySystem::EntityId entity_id) const;
	
	const Fnd::EntitySystem::Node& OnGetNode(const Fnd::EntitySystem::EntityId entity_id) const;
	
	Fnd::EntitySystem::Node& OnGetNode(const Fnd::EntitySystem::EntityId entity_id);
	
	void OnDestroyNode(const Fnd::EntitySystem::EntityId entity_id);
	
private:
	
	std::map<Fnd::EntitySystem::EntityId,std::shared_ptr<MockNode>> _map;
};

}

}

}
