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
#include "NodeContainerTests.hpp"
#include "NodeContainerTemplateTests.hpp"
#include "NodeManagerTests.hpp"

using namespace Fnd::Test::EntitySystem;

EntitySystemTestSuite::EntitySystemTestSuite():
	TestSuite("EntitySystemTestSuite")
{
	AddTestClass<ComponentTests>();
	AddTestClass<ComponentTemplateTests>();
	AddTestClass<ComponentContainerTests>();
	AddTestClass<ExceptionTests>();
	AddTestClass<ComponentContainerTemplateTests>();
	AddTestClass<ComponentManagerTests>();
	AddTestClass<EntityManagerTests>();
	AddTestClass<NodeTests>();
	AddTestClass<NodeTemplateTests>();
	AddTestClass<NodeContainerTests>();
	AddTestClass<NodeContainerTemplateTests>();
	AddTestClass<NodeManagerTests>();
}
