#pragma once

#include "SystemId.hpp"

#include "../Utility/HashIdFromNameGenerator.hpp"
#include "../Utility/IdNameMapper.hpp"

#include <memory>

namespace Fnd
{
	
namespace SystemManager
{

typedef Fnd::Utility::HashIdFromNameGenerator<SystemId> SystemIdFromNameGenerator;
typedef Fnd::Utility::IdNameMapper<SystemId> SystemIdNameMapper;

typedef std::shared_ptr<SystemIdFromNameGenerator> SystemIdFromNameGeneratorPtr;
typedef std::shared_ptr<SystemIdNameMapper> SystemIdNameMapperPtr;

}

}
