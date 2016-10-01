#include "ModuleConfig.hpp"

using namespace Fnd::Modules;
using namespace Fnd::Utility;
using namespace Fnd::Utility::DocumentTree;

ModuleConfig::ModuleConfig():
	_is_loaded(false)
{
}

void ModuleConfig::LoadDefault()
{	
	if (_is_loaded)
	{
		throw std::runtime_error("ModuleConfig has already been loaded");
	}

	OnLoadDefault();

	_is_loaded = true;
}

void ModuleConfig::Load(const ConfigProviderPtr& config_provider)
{
	if (_is_loaded)
	{
		throw std::runtime_error("ModuleConfig has already been loaded");
	}

	ObjectNodePtr document_tree = config_provider->LoadConfigDocumentTree();

	OnLoad(document_tree);

	_is_loaded = true;
}

void ModuleConfig::Save(const ConfigProviderPtr& config_provider)
{
	ObjectNodePtr document_tree = OnSave();

	config_provider->SaveConfigDocumentTree(document_tree);
}

ModuleConfig::~ModuleConfig()
{
}
