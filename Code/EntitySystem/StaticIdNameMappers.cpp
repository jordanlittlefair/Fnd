#include "StaticIdNameMappers.hpp"

using namespace Fnd::EntitySystem;

StaticIdNameMappers& StaticIdNameMappers::Instance()
{
	static StaticIdNameMappers static_id_name_mappers;
	
	return static_id_name_mappers;
}

StaticIdNameMappers::StaticIdNameMappers():
	_component_id_name_mapper(std::make_shared<ComponentIdFromNameGenerator>()),
	_node_id_name_mapper(std::make_shared<NodeIdFromNameGenerator>())
{
	
}

ComponentIdNameMapper& StaticIdNameMappers::GetComponentIdNameMapper()
{
	return _component_id_name_mapper;
}

NodeIdNameMapper& StaticIdNameMappers::GetNodeIdNameMapper()
{
	return _node_id_name_mapper;
}
