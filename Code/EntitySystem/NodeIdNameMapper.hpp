#pragma once

#include "NodeId.hpp"

#include "../Utility/HashIdFromNameGenerator.hpp"
#include "../Utility/IdNameMapper.hpp"

#include <memory>

namespace Fnd
{

namespace EntitySystem
{

typedef Fnd::Utility::HashIdFromNameGenerator<NodeId> NodeIdFromNameGenerator;
typedef Fnd::Utility::IdNameMapper<NodeId> NodeIdNameMapper;

typedef std::shared_ptr<NodeIdFromNameGenerator> NodeIdFromNameGeneratorPtr;
typedef std::shared_ptr<NodeIdNameMapper> NodeIdNameMapperPtr;

}

}
