#pragma once

#include "IParser.hpp"

namespace Fnd
{

namespace Utility
{

class JsonParser:
	public IParser
{
public:
	
	DocumentTree::ObjectNodePtr Parse(const Buffer& buffer) const;
	
	Buffer Serialise(const DocumentTree::ObjectNodePtr& document_tree) const;
	
	std::string GetDefaultFileExtension() const;
};
	
}
	
}
