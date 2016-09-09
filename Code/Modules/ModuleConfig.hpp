#pragma once

#include "IConfigProvider.hpp"

namespace Fnd
{

namespace Modules
{

class ModuleConfig
{
public:

	void LoadDefault();

	void Load(const ConfigProviderPtr& config_provider);

	void Save(const ConfigProviderPtr& config_provider);

	virtual ~ModuleConfig();

protected:

	ModuleConfig();
	
protected:

	virtual void OnLoadDefault() = 0;

	virtual void OnLoad(const Utility::DocumentTree::ObjectNodePtr& document_tree) = 0;

	virtual Utility::DocumentTree::ObjectNodePtr OnSave() = 0;

private:

	bool _is_loaded;
};

typedef std::shared_ptr<ModuleConfig> ModuleConfigPtr;

}

}
