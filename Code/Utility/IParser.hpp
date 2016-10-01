#pragma once

#include "Buffer.hpp"
#include "DocumentTreeNodes.hpp"

namespace Fnd
{

namespace Utility
{

class IParser
{
public:
	
	virtual DocumentTree::ObjectNodePtr Parse(const Buffer& buffer) const = 0;
	
	virtual Buffer Serialise(const DocumentTree::ObjectNodePtr& document_tree) const = 0;
	
	virtual std::string GetDefaultFileExtension() const = 0;

	virtual ~IParser() {}
};
	
typedef std::shared_ptr<IParser> ParserPtr;

}
	
}
