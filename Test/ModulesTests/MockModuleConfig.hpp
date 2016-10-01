#pragma once

#include "../../Code/Modules/ModuleConfig.hpp"

namespace Fnd
{

namespace Test
{

namespace Modules
{

class MockModuleConfig:
	public Fnd::Modules::ModuleConfig
{
public:
	
	void SetDefault(const std::string& str);
	
	struct Config
	{
		std::string str;
	};
	
	Config& GetConfig();
	
protected:
	
	void OnLoadDefault();
	
	void OnLoad(const Utility::DocumentTree::ObjectNodePtr& document_tree);
	
	Utility::DocumentTree::ObjectNodePtr OnSave();
	
private:
	
	std::string _default;
	
	Config _config;
};

}

}

}
