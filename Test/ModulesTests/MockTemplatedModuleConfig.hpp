#pragma once

#include "../../Code/Modules/TemplatedModuleConfig.hpp"

namespace Fnd
{

namespace Test
{

namespace Modules
{
	
struct MockConfigData
{
	std::string a_string;
};

class MockTemplatedModuleConfig:
	public Fnd::Modules::TemplatedModuleConfig<MockConfigData>
{
public:
	
	void SetDefault(const std::string& str);
	
protected:
	
	ConfigData OnLoadDefaultConfigData();
	
	ConfigData OnLoadConfigData(const Utility::DocumentTree::ObjectNodePtr& document_tree);
	
	Utility::DocumentTree::ObjectNodePtr OnSaveConfigData(const ConfigData& config_data);
	
private:
	
	std::string _default;
};

}

}

}
