#pragma once

#include "../../Code/SystemManager/NameMappedSystem.hpp"

namespace Fnd
{

namespace Test
{

namespace SystemManager
{

class MockNameMappedSystem:
	public Fnd::SystemManager::NameMappedSystem
{
public:

	MockNameMappedSystem(Fnd::SystemManager::SystemIdNameMapperPtr system_id_name_mapper, const std::string& name);
	
protected:
	
	void OnInitialise();
	
	void OnRun();
};

}

}

}
