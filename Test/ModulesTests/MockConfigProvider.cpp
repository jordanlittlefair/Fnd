#include "MockConfigProvider.hpp"

using namespace Fnd::Test::Modules;
using namespace Fnd::Modules;
using namespace Fnd::Utility;
using namespace Fnd::Utility::DocumentTree;

std::string MockConfigProvider::GetValue() const
{
	return _value;
}

void MockConfigProvider::SetValue(const std::string& value)
{
	_value = value;
}

ObjectNodePtr MockConfigProvider::LoadConfigDocumentTree()
{
	ObjectNodePtr ret = std::make_shared<ObjectNode>("");
	
	ret->GetValue().AddChild(std::make_shared<StringNode>("node", _value));
	
	return ret;
}

void MockConfigProvider::SaveConfigDocumentTree(const ObjectNodePtr& document_tree)
{
	_value = document_tree->GetValue().GetChildValue<StringNode>("node");
}
