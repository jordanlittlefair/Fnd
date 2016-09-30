#include "MockNodeContainer.hpp"

using namespace Fnd::EntitySystem;
using namespace Fnd::Test::EntitySystem;

MockNodeContainer::MockNodeContainer(const Fnd::EntitySystem::NodeId node_id):
	NodeContainer(node_id)
{
}

void MockNodeContainer::AddNode(const MockNode& node)
{
	_map[node.GetEntityId()] = std::make_shared<MockNode>(node);
}

Fnd::EntitySystem::Node& MockNodeContainer::OnCreateNode(const Fnd::EntitySystem::EntityId entity_id)
{
	return *(_map[entity_id] = std::make_shared<MockNode>(GetNodeId(), entity_id));
}

bool MockNodeContainer::OnHasNode(const Fnd::EntitySystem::EntityId entity_id) const
{
	return _map.find(entity_id) != _map.end();
}

const Fnd::EntitySystem::Node& MockNodeContainer::OnGetNode(const Fnd::EntitySystem::EntityId entity_id) const
{
	auto iter = _map.find(entity_id);
	
	if ( iter != _map.end() )
	{
		return *(iter->second);
	}
	else
	{
		throw std::runtime_error("Node doesn't exist!");
	}
}

Fnd::EntitySystem::Node& MockNodeContainer::OnGetNode(const Fnd::EntitySystem::EntityId entity_id)
{
	auto iter = _map.find(entity_id);
	
	if ( iter != _map.end() )
	{
		return *(iter->second);
	}
	else
	{
		throw std::runtime_error("Node doesn't exist!");
	}
}

void MockNodeContainer::OnDestroyNode(const Fnd::EntitySystem::EntityId entity_id)
{
	_map.erase(entity_id);
}