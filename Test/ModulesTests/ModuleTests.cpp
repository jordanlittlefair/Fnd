#include "ModuleTests.hpp"

#include "MockModule.hpp"

#include "../../Code/Modules/Exceptions.hpp"

using namespace Fnd::Modules;
using namespace Fnd::Test::Modules;

namespace
{
	
class MockComponentManager:
	public Fnd::EntitySystem::IComponentManager
{
		
};
	
class MockNodeManager:
	public Fnd::EntitySystem::INodeManager
{
	
};
	
class MockSystemManager:
	public Fnd::SystemManager::ISystemManager
{
	
};
	
}

ModuleTests::ModuleTests():
UnitTestClass("ModuleTests")
{
	AddTestCase("GetName_Success", &ModuleTests::GetName_Success, this);
	AddTestCase("RegisterComponents_Success", &ModuleTests::RegisterComponents_Success, this);
	AddTestCase("RegisterNodes_Success", &ModuleTests::RegisterNodes_Success, this);
	AddTestCase("RegisterSystems_Success", &ModuleTests::RegisterSystems_Success, this);
	AddTestCase("Initialise_Success", &ModuleTests::Initialise_Success, this);
	AddTestCase("Initialise_Throw_Fail", &ModuleTests::Initialise_Throw_Fail, this);
	AddTestCase("Initialise_AlreadyInitialised_Fail", &ModuleTests::Initialise_AlreadyInitialised_Fail, this);
}

void ModuleTests::GetName_Success(Fnd::Test::TestCase& test_case)
{
	MockModule module("name");
	
	test_case.AssertEqual("name", module.GetName());
}

void ModuleTests::RegisterComponents_Success(Fnd::Test::TestCase& test_case)
{
	MockModule module("name");
}

void ModuleTests::RegisterNodes_Success(Fnd::Test::TestCase& test_case)
{
	MockModule module("name");
	
}

void ModuleTests::RegisterSystems_Success(Fnd::Test::TestCase& test_case)
{
	MockModule module("name");
	
}

void ModuleTests::Initialise_Success(Fnd::Test::TestCase& test_case)
{
	MockModule module("name");
	
	module.Initialise();
	
	test_case.Assert(module.IsInitialised());
}

void ModuleTests::Initialise_Throw_Fail(Fnd::Test::TestCase& test_case)
{
	MockModule module("name");
	
	module.SetThrowException();
	
	test_case.AssertException<std::runtime_error>([&]()
	{
		module.Initialise();
	});
}

void ModuleTests::Initialise_AlreadyInitialised_Fail(Fnd::Test::TestCase& test_case)
{
	MockModule module("name");
	
	module.Initialise();
	
	test_case.AssertException<InvalidOperationException>([&]()
	{
		module.Initialise();
	});
}