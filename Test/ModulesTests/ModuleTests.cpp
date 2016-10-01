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
public:
	bool IsRegistered(const Fnd::EntitySystem::ComponentId componentId) const
	{
		throw std::runtime_error("Not implemented");
	}
	
	void RegisterComponent(std::shared_ptr<Fnd::EntitySystem::ComponentContainer> component_container)
	{
		throw std::runtime_error("Not implemented");
	}
	
	Fnd::EntitySystem::Component& CreateComponent(const Fnd::EntitySystem::ComponentId component_id, const Fnd::EntitySystem::EntityId entity_id)
	{
		throw std::runtime_error("Not implemented");
	}
	
	bool HasComponent(const Fnd::EntitySystem::ComponentId component_id, const Fnd::EntitySystem::EntityId entity_id) const
	{
		throw std::runtime_error("Not implemented");
	}
	
	Fnd::EntitySystem::Component& GetComponent(const Fnd::EntitySystem::ComponentId component_id, const Fnd::EntitySystem::EntityId entity_id)
	{
		throw std::runtime_error("Not implemented");
	}
	
	const Fnd::EntitySystem::Component& GetComponent(const Fnd::EntitySystem::ComponentId component_id, const Fnd::EntitySystem::EntityId entity_id) const
	{
		throw std::runtime_error("Not implemented");
	}
	
	void DestroyComponent(const Fnd::EntitySystem::ComponentId component_id, const Fnd::EntitySystem::EntityId entity_id)
	{
		throw std::runtime_error("Not implemented");
	}
};
	
class MockNodeManager:
	public Fnd::EntitySystem::INodeManager
{
public:
	bool IsRegistered(const Fnd::EntitySystem::NodeId node_id) const
	{
		throw std::runtime_error("Not implemented");
	}

	
	void RegisterNode(std::shared_ptr<Fnd::EntitySystem::NodeContainer> node_container)
	{
		throw std::runtime_error("Not implemented");
	}

	
	Fnd::EntitySystem::Node& CreateNode(const Fnd::EntitySystem::NodeId node_id, const Fnd::EntitySystem::EntityId entity_id)
	{
		throw std::runtime_error("Not implemented");
	}

	
	bool HasNode(const Fnd::EntitySystem::NodeId node_id, const Fnd::EntitySystem::EntityId entity_id) const
	{
		throw std::runtime_error("Not implemented");
	}

	
	const Fnd::EntitySystem::Node& GetNode(const Fnd::EntitySystem::NodeId node_id, const Fnd::EntitySystem::EntityId entity_id) const
	{
		throw std::runtime_error("Not implemented");
	}

	
	Fnd::EntitySystem::Node& GetNode(const Fnd::EntitySystem::NodeId node_id, const Fnd::EntitySystem::EntityId entity_id)
	{
		throw std::runtime_error("Not implemented");
	}

	
	void DestroyNode(const Fnd::EntitySystem::NodeId node_id, const Fnd::EntitySystem::EntityId entity_id)
	{
		throw std::runtime_error("Not implemented");
	}

};
	
class MockSystemManager:
	public Fnd::SystemManager::ISystemManager
{
public:
	bool IsInitialised() const
	{
		throw std::runtime_error("Not implemented");
	}
	
	bool IsAlive() const
	{
		throw std::runtime_error("Not implemented");
	}
	
	void RegisterSystem(Fnd::SystemManager::SystemPtr system)
	{
		throw std::runtime_error("Not implemented");
	}
	
	void Initialise()
	{
		throw std::runtime_error("Not implemented");
	}
	
	void Start()
	{
		throw std::runtime_error("Not implemented");
	}
	
	void Run()
	{
		throw std::runtime_error("Not implemented");
	}
	
	void Kill()
	{
		throw std::runtime_error("Not implemented");
	}
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
	
	MockComponentManager component_manager;
	
	test_case.Assert(!module.HasRegisteredComponents());
	
	module.RegisterComponents(component_manager);
	
	test_case.Assert(module.HasRegisteredComponents());
}

void ModuleTests::RegisterNodes_Success(Fnd::Test::TestCase& test_case)
{
	MockModule module("name");
	
	MockNodeManager node_manager;
	
	test_case.Assert(!module.HasRegisteredNodes());
	
	module.RegisterNodes(node_manager);
	
	test_case.Assert(module.HasRegisteredNodes());
}

void ModuleTests::RegisterSystems_Success(Fnd::Test::TestCase& test_case)
{
	MockModule module("name");
	
	MockSystemManager system_manager;
	
	test_case.Assert(!module.HasRegisteredSystems());
	
	module.RegisterSystems(system_manager);
	
	test_case.Assert(module.HasRegisteredSystems());
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