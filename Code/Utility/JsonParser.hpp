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
	
	DocumentTree::NodePtr Parse(const Buffer& buffer) const;
	
	Buffer Serialise(const DocumentTree::NodePtr& document_tree) const;
	
	std::string GetDefaultFileExtension() const;
};
	
}
	
}
