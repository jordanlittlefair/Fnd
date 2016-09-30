#pragma once

#include "ModuleConfig.hpp"

namespace Fnd
{

namespace Modules
{

template <typename ConfigDataT>
class TemplatedModuleConfig:
	public ModuleConfig
{
public:
	
	typedef ConfigDataT ConfigData;
	
	const ConfigData& GetConfigData() const
	{
		return _config_data;
	}
	
	ConfigData& GetConfigData()
	{
		return _config_data;
	}
	
protected:
	
	virtual ConfigData OnLoadDefaultConfigData() = 0;
	
	virtual ConfigData OnLoadConfigData(const Utility::DocumentTree::ObjectNodePtr& document_tree) = 0;
	
	virtual Utility::DocumentTree::ObjectNodePtr OnSaveConfigData(const ConfigData& config_data) = 0;
	
protected:
	
	void OnLoadDefault()
	{
		_config_data = OnLoadDefaultConfigData();
	}
	
	void OnLoad(const Utility::DocumentTree::ObjectNodePtr& document_tree)
	{
		_config_data = OnLoadConfigData(document_tree);
	}
	
	Utility::DocumentTree::ObjectNodePtr OnSave()
	{
		return OnSaveConfigData(_config_data);
	}
	
private:
	
	ConfigData _config_data;
};

}

}
