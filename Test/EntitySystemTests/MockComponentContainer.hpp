#pragma once

#include "MockComponent.hpp"

#include "../../Code/EntitySystem/ComponentContainer.hpp"

#include <map>
#include <memory>

namespace Fnd
{

namespace Test
{

namespace EntitySystem
{

class MockComponentContainer:
	public Fnd::EntitySystem::ComponentContainer
{
public:

	MockComponentContainer( const Fnd::EntitySystem::ComponentId component_id );

	void AddComponent( const MockComponent& component );

protected:
	
	Fnd::EntitySystem::Component& OnCreateComponent(const Fnd::EntitySystem::EntityId entity_id);
	
	bool OnHasComponent(const Fnd::EntitySystem::EntityId entity_id) const;

	const Fnd::EntitySystem::Component& OnGetComponent( const Fnd::EntitySystem::EntityId entity_id ) const;

	Fnd::EntitySystem::Component& OnGetComponent( const Fnd::EntitySystem::EntityId entity_id );
	
	void OnDestroyComponent(const Fnd::EntitySystem::EntityId entity_id);

private:

	std::map<Fnd::EntitySystem::EntityId,std::shared_ptr<MockComponent>> _map;
};

}

}

}
