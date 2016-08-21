#pragma once

#include "ComponentIdNameMapper.hpp"
#include "NodeIdNameMapper.hpp"

#include <memory>

namespace Fnd
{

namespace EntitySystem
{

class StaticIdNameMappers
{
public:

	static ComponentIdNameMapper& GetComponentIdNameMapper();
	
	static NodeIdNameMapper& GetNodeIdNameMapper();
	
private:
	
	StaticIdNameMappers();
	StaticIdNameMappers(const StaticIdNameMappers&);
	StaticIdNameMappers& operator=(const StaticIdNameMappers&);
	
private:
	
	static ComponentIdNameMapper _component_id_name_mapper;
	static NodeIdNameMapper _node_id_name_mapper;
};

}

}
