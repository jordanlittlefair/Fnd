#pragma once

#include "../../Code/SystemManager/System.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{

class MockSystem:
	public Fnd::SystemManager::System
{
public:

	MockSystem( const Fnd::SystemManager::SystemId& id );
};

}

}

}
