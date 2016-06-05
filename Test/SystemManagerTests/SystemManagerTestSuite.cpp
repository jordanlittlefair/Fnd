#include "SystemManagerTestSuite.hpp"

#include "SystemManagerExceptionTests.hpp"
#include "SystemGraphNodeTests.hpp"
#include "SystemTests.hpp"
#include "SystemGraphTests.hpp"
#include "CyclicGraphCheckerTests.hpp"
#include "OptimalPathFinderTests.hpp"
#include "TaskTests.hpp"
#include "LambdaTaskTests.hpp"

using namespace Fnd::Test::SystemManager;

SystemManagerTestSuite::SystemManagerTestSuite():
	TestSuite("SystemManagerTestSuite")
{
	AddTestClass<SystemManager::SystemManagerExceptionTests>();
	AddTestClass<SystemManager::SystemGraphNodeTests>();
	AddTestClass<SystemManager::SystemTests>();
	AddTestClass<SystemManager::SystemGraphTests>();
	AddTestClass<SystemManager::CyclicGraphCheckerTests>();
	AddTestClass<SystemManager::OptimalPathFinderTests>();
	AddTestClass<SystemManager::TaskTests>();
	AddTestClass<SystemManager::LambdaTaskTests>();
}
