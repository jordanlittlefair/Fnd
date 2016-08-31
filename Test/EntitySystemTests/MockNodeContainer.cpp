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
