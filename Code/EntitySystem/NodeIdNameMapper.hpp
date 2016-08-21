#pragma once

#include "ComponentId.hpp"

#include "../Utility/HashIdFromNameGenerator.hpp"
#include "../Utility/IdNameMapper.hpp"

#include <memory>

namespace Fnd
{

namespace EntitySystem
{

typedef Fnd::Utility::HashIdFromNameGenerator<ComponentId> ComponentIdFromNameGenerator;
typedef Fnd::Utility::IdNameMapper<ComponentId> ComponentIdNameMapper;

typedef std::shared_ptr<ComponentIdFromNameGenerator> ComponentIdFromNameGeneratorPtr;
typedef std::shared_ptr<ComponentIdNameMapper> ComponentIdNameMapperPtr;

}

}
