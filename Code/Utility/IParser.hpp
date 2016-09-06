#pragma once

#include "Buffer.hpp"
#include "DocumentTreeINode.hpp"

namespace Fnd
{

namespace Utility
{

class IParser
{
public:
	
	virtual DocumentTree::NodePtr Parse(const Buffer& buffer) const = 0;
	
	virtual Buffer Serialise(const DocumentTree::NodePtr& document_tree) const = 0;
	
	virtual std::string GetDefaultFileExtension() const = 0;

	virtual ~IParser() {}
};
	
typedef std::shared_ptr<IParser> ParserPtr;

}
	
}
