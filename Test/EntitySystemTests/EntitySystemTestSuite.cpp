#include "EntitySystemTestSuite.hpp"

#include "ComponentTests.hpp"
#include "ComponentTemplateTests.hpp"
#include "ComponentContainerTests.hpp"
#include "ComponentContainerTemplateTests.hpp"
#include "ExceptionTests.hpp"
#include "ComponentManagerTests.hpp"
#include "EntityManagerTests.hpp"
#include "NodeTests.hpp"
#include "NodeTemplateTests.hpp"

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
	AddTestClass<EntitySystem::EntityManagerTests>();
	AddTestClass<EntitySystem::NodeTests>();
	AddTestClass<EntitySystem::NodeTemplateTests>();
}
