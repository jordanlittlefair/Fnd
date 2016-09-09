#include "MockModuleConfig.hpp"

using namespace Fnd::Test::Modules;
using namespace Fnd::Modules;
using namespace Fnd::Utility;
using namespace Fnd::Utility::DocumentTree;

void MockModuleConfig::SetDefault(const std::string& str)
{
	_default = str;
}

MockModuleConfig::Config& MockModuleConfig::GetConfig()
{
	return _config;
}

void MockModuleConfig::OnLoadDefault()
{
	_config.str = _default;
}

void MockModuleConfig::OnLoad(const Utility::DocumentTree::ObjectNodePtr& document_tree)
{
	_config.str = document_tree->GetValue().GetChildValue<StringNode>("node");
}

ObjectNodePtr MockModuleConfig::OnSave()
{
	ObjectNodePtr ret = std::make_shared<ObjectNode>("");
	
	ret->GetValue().AddChild(std::make_shared<StringNode>("node",std::string(_config.str.begin(),_config.str.end())));
	
	return ret;
}
