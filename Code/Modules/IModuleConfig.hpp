#pragma once

#include "IConfigProvider.hpp"

namespace Fnd
{

namespace Modules
{

class IModuleConfig
{
public:
	
	virtual void LoadDefault() = 0;
	
	virtual void Load(const ConfigProviderPtr& config_provider) = 0;
	
	virtual void Save(const ConfigProviderPtr& config_provider) = 0;
	
	virtual ~IModuleConfig() {}
};

typedef std::shared_ptr<IModuleConfig> ModuleConfigPtr;

}

}
