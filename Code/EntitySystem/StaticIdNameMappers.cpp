#include "StaticIdNameMappers.hpp"

using namespace Fnd::EntitySystem;

/* static */
ComponentIdNameMapper& StaticIdNameMappers::GetComponentIdNameMapper()
{
	return _component_id_name_mapper;
}

/* static */
NodeIdNameMapper& StaticIdNameMappers::GetNodeIdNameMapper()
{
	return _node_id_name_mapper;
}
