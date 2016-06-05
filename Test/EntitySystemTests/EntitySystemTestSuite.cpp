#include "EntitySystemTestSuite.hpp"

#include "../EntitySystemTests/ComponentTests.hpp"
#include "../EntitySystemTests/ComponentTemplateTests.hpp"
#include "../EntitySystemTests/ComponentContainerTests.hpp"
#include "../EntitySystemTests/ComponentContainerTemplateTests.hpp"
#include "../EntitySystemTests/ExceptionTests.hpp"
#include "../EntitySystemTests/ComponentManagerTests.hpp"

using namespace Fnd::Test::EntitySystemTests;

EntitySystemTestSuite::EntitySystemTestSuite():
	TestSuite("EntitySystemTestSuite")
{
	AddTestClass<EntitySystem::ComponentTests>();
	AddTestClass<EntitySystem::ComponentTemplateTests>();
	AddTestClass<EntitySystem::ComponentContainerTests>();
	AddTestClass<EntitySystem::ExceptionTests>();
	AddTestClass<EntitySystem::ComponentContainerTemplateTests>();
	AddTestClass<EntitySystem::ComponentManagerTests>();
}
