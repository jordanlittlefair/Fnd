#pragma once

#include "DocumentTreeArray.hpp"
#include "DocumentTreeNodeTemplate.hpp"
#include "DocumentTreeObject.hpp"

namespace Fnd
{

namespace Utility
{

namespace DocumentTree
{
	
typedef DocumentTreeNodeTemplate<INode::Type::String, std::string> StringNode;
typedef DocumentTreeNodeTemplate<INode::Type::Number, double> NumberNode;
typedef DocumentTreeNodeTemplate<INode::Type::Object, Object> ObjectNode;
typedef DocumentTreeNodeTemplate<INode::Type::Array, Array> ArrayNode;
	
typedef std::shared_ptr<StringNode> StringNodePtr;
typedef std::shared_ptr<NumberNode> NumberNodePtr;
typedef std::shared_ptr<ObjectNode> ObjectNodePtr;
typedef std::shared_ptr<ArrayNode> ArrayNodePtr;

}

}

}
