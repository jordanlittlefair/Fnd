#include "SystemManagerTestSuite.hpp"

#include "SystemManagerExceptionTests.hpp"
#include "SystemGraphNodeTests.hpp"
#include "SystemTests.hpp"
#include "SystemGraphTests.hpp"
#include "CyclicGraphCheckerTests.hpp"
#include "OptimalPathFinderTests.hpp"
#include "TaskTests.hpp"
#include "LambdaTaskTests.hpp"
#include "TaskQueueTests.hpp"

using namespace Fnd::Test::SystemManager;

SystemManagerTestSuite::SystemManagerTestSuite():
	TestSuite("SystemManagerTestSuite")
{
	AddTestClass<SystemManagerExceptionTests>();
	AddTestClass<SystemGraphNodeTests>();
	AddTestClass<SystemTests>();
	AddTestClass<SystemGraphTests>();
	AddTestClass<CyclicGraphCheckerTests>();
	AddTestClass<OptimalPathFinderTests>();
	AddTestClass<TaskTests>();
	AddTestClass<LambdaTaskTests>();
	AddTestClass<TaskQueueTests>();
}
