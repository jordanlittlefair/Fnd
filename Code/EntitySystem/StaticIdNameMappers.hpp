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
	
	static StaticIdNameMappers& Instance();

	ComponentIdNameMapper& GetComponentIdNameMapper();
	
	NodeIdNameMapper& GetNodeIdNameMapper();
	
private:
	
	StaticIdNameMappers();
	StaticIdNameMappers(const StaticIdNameMappers&);
	StaticIdNameMappers& operator=(const StaticIdNameMappers&);
	
private:
	
	ComponentIdNameMapper _component_id_name_mapper;
	NodeIdNameMapper _node_id_name_mapper;
};

}

}
