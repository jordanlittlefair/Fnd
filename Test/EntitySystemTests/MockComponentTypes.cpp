#include "MockComponentTypes.hpp"

#include "../../Code/EntitySystem/StaticIdNameMappers.hpp"

using namespace Fnd::Test::EntitySystem;
using namespace Fnd::EntitySystem;

const std::string MockComponentType1::Name = "One";
const std::string MockComponentType2::Name = "Two";

const ComponentId MockComponentType1::Id = StaticIdNameMappers::Instance().GetComponentIdNameMapper().GenerateId(MockComponentType1::Name);
const ComponentId MockComponentType2::Id = StaticIdNameMappers::Instance().GetComponentIdNameMapper().GenerateId(MockComponentType2::Name);
