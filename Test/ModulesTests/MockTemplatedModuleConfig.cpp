#include "MockTemplatedModuleConfig.hpp"

using namespace Fnd::Test::Modules;
using namespace Fnd::Modules;
using namespace Fnd::Utility;
using namespace Fnd::Utility::DocumentTree;

void MockTemplatedModuleConfig::SetDefault(const std::string& str)
{
	_default = str;
}

MockTemplatedModuleConfig::ConfigData MockTemplatedModuleConfig::OnLoadDefaultConfigData()
{
	MockConfigData ret;
	
	ret.a_string = _default;
	
	return ret;
}

MockTemplatedModuleConfig::ConfigData MockTemplatedModuleConfig::OnLoadConfigData(const Utility::DocumentTree::ObjectNodePtr& document_tree)
{
	MockConfigData ret;
	
	ret.a_string = document_tree->GetValue().GetChildValue<StringNode>("node");
	
	return ret;
}

ObjectNodePtr MockTemplatedModuleConfig::OnSaveConfigData(const MockTemplatedModuleConfig::ConfigData& config_data)
{
	ObjectNodePtr ret = std::make_shared<ObjectNode>("");
	
	ret->GetValue().AddChild(std::make_shared<StringNode>("node",GetConfigData().a_string));
	
	return ret;
}
