#include "JsonParser.hpp"

#include "../../External/RapidJSON/document.h"
#include "../../External/RapidJSON/rapidjson.h"

using namespace Fnd::Utility;
using namespace Fnd::Utility::DocumentTree;

ObjectNodePtr JsonParser::Parse(const Buffer& buffer) const
{
	rapidjson::Document document;
	document.Parse(std::string(buffer.begin(), buffer.end()).c_str());

	for (auto& member : document.GetObject())
	{
		// Parse Children
	}
	
	return nullptr;
}

Buffer JsonParser::Serialise(const DocumentTree::ObjectNodePtr& document_tree) const
{
	return Buffer();
}

std::string JsonParser::GetDefaultFileExtension() const
{
	return ".json";
}
