#include "EntitySystemIntegrationTests.hpp"

#include "../../Code/EntitySystem/BasicEntityIdGenerator.hpp"
#include "../../Code/EntitySystem/EntitySystem.hpp"
#include "../../Code/EntitySystem/StaticIdNameMappers.hpp"

using namespace Fnd::Test::EntitySystem;
using namespace Fnd::EntitySystem;

namespace Components
{

struct ComponentTypeA
{
	static const Fnd::EntitySystem::ComponentId Id;
	
	static const std::string Name;

	struct Data
	{
		int update_count;
	};
};

struct ComponentTypeB
{
	static const Fnd::EntitySystem::ComponentId Id;
	
	static const std::string Name;

	struct Data
	{
		int update_count;
	};
};

struct ComponentTypeC
{
	static const Fnd::EntitySystem::ComponentId Id;
	
	static const std::string Name;

	struct Data
	{
		int update_count;
	};
};

const std::string ComponentTypeA::Name = "A";
const std::string ComponentTypeB::Name = "B";
const std::string ComponentTypeC::Name = "C";

const ComponentId ComponentTypeA::Id = StaticIdNameMappers::Instance().GetComponentIdNameMapper().GenerateId(ComponentTypeA::Name);
const ComponentId ComponentTypeB::Id = StaticIdNameMappers::Instance().GetComponentIdNameMapper().GenerateId(ComponentTypeB::Name);
const ComponentId ComponentTypeC::Id = StaticIdNameMappers::Instance().GetComponentIdNameMapper().GenerateId(ComponentTypeC::Name);

}

namespace Nodes
{

struct NodeType_AB
{
	static const Fnd::EntitySystem::NodeId Id;
	
	static const std::string Name;

	struct Components
	{
		Fnd::EntitySystem::ComponentTemplate<::Components::ComponentTypeA>& a;
		Fnd::EntitySystem::ComponentTemplate<::Components::ComponentTypeB>& b;
	};
	
	struct ComponentsConst
	{
		const Fnd::EntitySystem::ComponentTemplate<::Components::ComponentTypeA>& a;
		const Fnd::EntitySystem::ComponentTemplate<::Components::ComponentTypeB>& b;
	};
	
	static Components GetComponents(const Fnd::EntitySystem::EntityId& entity_id, Fnd::EntitySystem::ComponentManager& component_manager)
	{
		Components components =
		{
			component_manager.GetComponent<::Components::ComponentTypeA>(entity_id),			
			component_manager.GetComponent<::Components::ComponentTypeB>(entity_id)
		};
	
		return components;
	}
	
	static ComponentsConst GetComponents(const Fnd::EntitySystem::EntityId& entity_id, const Fnd::EntitySystem::ComponentManager& component_manager)
	{
		ComponentsConst components =
		{
			component_manager.GetComponent<::Components::ComponentTypeA>(entity_id),			
			component_manager.GetComponent<::Components::ComponentTypeB>(entity_id)
		};
	
		return components;
	}
};

struct NodeType_BC
{
	static const Fnd::EntitySystem::NodeId Id;
	
	static const std::string Name;

	struct Components
	{
		Fnd::EntitySystem::ComponentTemplate<::Components::ComponentTypeB>& b;
		Fnd::EntitySystem::ComponentTemplate<::Components::ComponentTypeC>& c;
	};
	
	struct ComponentsConst
	{
		const Fnd::EntitySystem::ComponentTemplate<::Components::ComponentTypeB>& b;
		const Fnd::EntitySystem::ComponentTemplate<::Components::ComponentTypeC>& c;
	};
	
	static Components GetComponents(const Fnd::EntitySystem::EntityId& entity_id, Fnd::EntitySystem::ComponentManager& component_manager)
	{
		Components components =
		{
			component_manager.GetComponent<::Components::ComponentTypeB>(entity_id),			
			component_manager.GetComponent<::Components::ComponentTypeC>(entity_id)
		};
	
		return components;
	}
	
	static ComponentsConst GetComponents(const Fnd::EntitySystem::EntityId& entity_id, const Fnd::EntitySystem::ComponentManager& component_manager)
	{
		ComponentsConst components =
		{
			component_manager.GetComponent<::Components::ComponentTypeB>(entity_id),			
			component_manager.GetComponent<::Components::ComponentTypeC>(entity_id)
		};
	
		return components;
	}
};

struct NodeType_ABC
{
	static const Fnd::EntitySystem::NodeId Id;
	
	static const std::string Name;

	struct Components
	{
		Fnd::EntitySystem::ComponentTemplate<::Components::ComponentTypeA>& a;
		Fnd::EntitySystem::ComponentTemplate<::Components::ComponentTypeB>& b;
		Fnd::EntitySystem::ComponentTemplate<::Components::ComponentTypeC>& c;
	};
	
	struct ComponentsConst
	{
		const Fnd::EntitySystem::ComponentTemplate<::Components::ComponentTypeA>& a;
		const Fnd::EntitySystem::ComponentTemplate<::Components::ComponentTypeB>& b;
		const Fnd::EntitySystem::ComponentTemplate<::Components::ComponentTypeC>& c;
	};
	
	static Components GetComponents(const Fnd::EntitySystem::EntityId& entity_id, Fnd::EntitySystem::ComponentManager& component_manager)
	{
		Components components =
		{
			component_manager.GetComponent<::Components::ComponentTypeA>(entity_id),
			component_manager.GetComponent<::Components::ComponentTypeB>(entity_id),
			component_manager.GetComponent<::Components::ComponentTypeC>(entity_id)
		};
	
		return components;
	}
	
	static ComponentsConst GetComponents(const Fnd::EntitySystem::EntityId& entity_id, const Fnd::EntitySystem::ComponentManager& component_manager)
	{
		ComponentsConst components =
		{
			component_manager.GetComponent<::Components::ComponentTypeA>(entity_id),
			component_manager.GetComponent<::Components::ComponentTypeB>(entity_id),
			component_manager.GetComponent<::Components::ComponentTypeC>(entity_id)
		};
	
		return components;
	}
};

const std::string NodeType_AB::Name = "AB";
const std::string NodeType_BC::Name = "BC";
const std::string NodeType_ABC::Name = "ABC";

const NodeId NodeType_AB::Id = StaticIdNameMappers::Instance().GetNodeIdNameMapper().GenerateId(NodeType_AB::Name);
const NodeId NodeType_BC::Id = StaticIdNameMappers::Instance().GetNodeIdNameMapper().GenerateId(NodeType_BC::Name);
const NodeId NodeType_ABC::Id = StaticIdNameMappers::Instance().GetNodeIdNameMapper().GenerateId(NodeType_ABC::Name);

}

EntitySystemIntegrationTests::EntitySystemIntegrationTests():
	IntegrationTestClass("EntitySystemIntegrationTests")
{
	AddTestCase( "Create_Components_Nodes_And_Loop_Nodes", &EntitySystemIntegrationTests::Create_Components_Nodes_And_Loop_Nodes, this );
}


void EntitySystemIntegrationTests::Create_Components_Nodes_And_Loop_Nodes(Fnd::Test::TestCase& test_case)
{
	using namespace Components;
	using namespace Nodes;
	class EntitySystem es(std::make_shared<BasicEntityIdGenerator>());

	EntityManager& em = es.EntityManager();
	ComponentManager& cm = es.ComponentManager();
	NodeManager& nm = es.NodeManager();

	/*
		Register types
	*/

	cm.RegisterComponent<ComponentTypeA>();
	cm.RegisterComponent<ComponentTypeB>();
	cm.RegisterComponent<ComponentTypeC>();

	nm.RegisterNode<NodeType_AB>();
	nm.RegisterNode<NodeType_BC>();
	nm.RegisterNode<NodeType_ABC>();

	/*
		Create some entities with components
	*/

	ComponentTypeA::Data a_data = { 0 };
	ComponentTypeB::Data b_data = { 0 };
	ComponentTypeC::Data c_data = { 0 };

	EntityId e_ab = em.CreateEntity();
	cm.CreateComponent<ComponentTypeA>(e_ab,a_data);
	cm.CreateComponent<ComponentTypeB>(e_ab,b_data);

	EntityId e_bc = em.CreateEntity();
	cm.CreateComponent<ComponentTypeB>(e_bc,b_data);
	cm.CreateComponent<ComponentTypeC>(e_bc,c_data);

	EntityId e_abc = em.CreateEntity();
	cm.CreateComponent<ComponentTypeA>(e_abc,a_data);
	cm.CreateComponent<ComponentTypeB>(e_abc,b_data);
	cm.CreateComponent<ComponentTypeC>(e_abc,c_data);

	/*
		Create Nodes
	*/

	nm.CreateNode<NodeType_AB>(e_ab);
	nm.CreateNode<NodeType_AB>(e_abc);

	nm.CreateNode<NodeType_BC>(e_bc);
	nm.CreateNode<NodeType_BC>(e_abc);
	
	nm.CreateNode<NodeType_ABC>(e_abc);

	/*
		Update all AB nodes
	*/

	nm.ForEachNode<NodeType_AB>([&](NodeTemplate<NodeType_AB>& node)
	{
		NodeType_AB::Components components = node.GetComponents(cm);

		components.a->update_count += 1;
		components.b->update_count += 1;
	});

	test_case.AssertEqual(1, cm.GetComponent<ComponentTypeA>(e_ab)->update_count);
	test_case.AssertEqual(1, cm.GetComponent<ComponentTypeB>(e_ab)->update_count);

	test_case.AssertEqual(0, cm.GetComponent<ComponentTypeB>(e_bc)->update_count);
	test_case.AssertEqual(0, cm.GetComponent<ComponentTypeC>(e_bc)->update_count);
	
	test_case.AssertEqual(1, cm.GetComponent<ComponentTypeA>(e_abc)->update_count);
	test_case.AssertEqual(1, cm.GetComponent<ComponentTypeB>(e_abc)->update_count);
	test_case.AssertEqual(0, cm.GetComponent<ComponentTypeC>(e_abc)->update_count);


	/*
		Update all BC nodes
	*/

	nm.ForEachNode<NodeType_BC>([&](NodeTemplate<NodeType_BC>& node)
	{
		NodeType_BC::Components components = node.GetComponents(cm);

		components.b->update_count += 1;
		components.c->update_count += 1;
	});

	test_case.AssertEqual(1, cm.GetComponent<ComponentTypeA>(e_ab)->update_count);
	test_case.AssertEqual(1, cm.GetComponent<ComponentTypeB>(e_ab)->update_count);

	test_case.AssertEqual(1, cm.GetComponent<ComponentTypeB>(e_bc)->update_count);
	test_case.AssertEqual(1, cm.GetComponent<ComponentTypeC>(e_bc)->update_count);
	
	test_case.AssertEqual(1, cm.GetComponent<ComponentTypeA>(e_abc)->update_count);
	test_case.AssertEqual(2, cm.GetComponent<ComponentTypeB>(e_abc)->update_count);
	test_case.AssertEqual(1, cm.GetComponent<ComponentTypeC>(e_abc)->update_count);
	
	/*
		Update all ABC nodes
	*/

	nm.ForEachNode<NodeType_ABC>([&](NodeTemplate<NodeType_ABC>& node)
	{
		NodeType_ABC::Components components = node.GetComponents(cm);

		components.a->update_count += 1;
		components.b->update_count += 1;
		components.c->update_count += 1;
	});

	test_case.AssertEqual(1, cm.GetComponent<ComponentTypeA>(e_ab)->update_count);
	test_case.AssertEqual(1, cm.GetComponent<ComponentTypeB>(e_ab)->update_count);

	test_case.AssertEqual(1, cm.GetComponent<ComponentTypeB>(e_bc)->update_count);
	test_case.AssertEqual(1, cm.GetComponent<ComponentTypeC>(e_bc)->update_count);
	
	test_case.AssertEqual(2, cm.GetComponent<ComponentTypeA>(e_abc)->update_count);
	test_case.AssertEqual(3, cm.GetComponent<ComponentTypeB>(e_abc)->update_count);
	test_case.AssertEqual(2, cm.GetComponent<ComponentTypeC>(e_abc)->update_count);

	/*
		Destroy all nodes except ABC
	*/
	nm.DestroyNode<NodeType_AB>(e_ab);
	nm.DestroyNode<NodeType_BC>(e_bc);

	/*
		Update all AB nodes again (only with ABC components)
	*/

	nm.ForEachNode<NodeType_AB>([&](NodeTemplate<NodeType_AB>& node)
	{
		NodeType_AB::Components components = node.GetComponents(cm);

		components.a->update_count += 1;
		components.b->update_count += 1;
	});

	test_case.AssertEqual(1, cm.GetComponent<ComponentTypeA>(e_ab)->update_count);
	test_case.AssertEqual(1, cm.GetComponent<ComponentTypeB>(e_ab)->update_count);

	test_case.AssertEqual(1, cm.GetComponent<ComponentTypeB>(e_bc)->update_count);
	test_case.AssertEqual(1, cm.GetComponent<ComponentTypeC>(e_bc)->update_count);
	
	test_case.AssertEqual(3, cm.GetComponent<ComponentTypeA>(e_abc)->update_count);
	test_case.AssertEqual(4, cm.GetComponent<ComponentTypeB>(e_abc)->update_count);
	test_case.AssertEqual(2, cm.GetComponent<ComponentTypeC>(e_abc)->update_count);

	/*
		Update all BC nodes again (only with ABC components)
	*/

	nm.ForEachNode<NodeType_BC>([&](NodeTemplate<NodeType_BC>& node)
	{
		NodeType_BC::Components components = node.GetComponents(cm);

		components.b->update_count += 1;
		components.c->update_count += 1;
	});

	test_case.AssertEqual(1, cm.GetComponent<ComponentTypeA>(e_ab)->update_count);
	test_case.AssertEqual(1, cm.GetComponent<ComponentTypeB>(e_ab)->update_count);

	test_case.AssertEqual(1, cm.GetComponent<ComponentTypeB>(e_bc)->update_count);
	test_case.AssertEqual(1, cm.GetComponent<ComponentTypeC>(e_bc)->update_count);
	
	test_case.AssertEqual(3, cm.GetComponent<ComponentTypeA>(e_abc)->update_count);
	test_case.AssertEqual(5, cm.GetComponent<ComponentTypeB>(e_abc)->update_count);
	test_case.AssertEqual(3, cm.GetComponent<ComponentTypeC>(e_abc)->update_count);
}