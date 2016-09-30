#include "MockParser.hpp"

using namespace Fnd::Test::Modules;
using namespace Fnd::Utility;
using namespace Fnd::Utility::DocumentTree;

ObjectNodePtr MockParser::Parse(const Buffer& buffer) const
{
	ObjectNodePtr ret = std::make_shared<ObjectNode>("");
	
	ret->GetValue().AddChild(std::make_shared<StringNode>("node",std::string(buffer.begin(),buffer.end())));
	
	return ret;
}

Buffer MockParser::Serialise(const ObjectNodePtr& document_tree) const
{
	std::string str = document_tree->GetValue().GetChildValue<StringNode>("node");
	
	return Buffer(str.begin(), str.end());
}

std::string MockParser::GetDefaultFileExtension() const
{
	return ".mock";
}
