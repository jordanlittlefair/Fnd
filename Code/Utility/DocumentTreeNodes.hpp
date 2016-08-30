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
typedef DocumentTreeNodeTemplate<INode::Type::Integer, long long int> IntegerNode;
typedef DocumentTreeNodeTemplate<INode::Type::Float, double> FloatNode;	
typedef DocumentTreeNodeTemplate<INode::Type::Object, Object> ObjectNode;
typedef DocumentTreeNodeTemplate<INode::Type::Array, Array> ArrayNode;
	
typedef std::shared_ptr<StringNode> StringNodePtr;
typedef std::shared_ptr<IntegerNode> IntegerNodePtr;
typedef std::shared_ptr<FloatNode> FloatNodePtr;
typedef std::shared_ptr<ObjectNode> ObjectNodePtr;
typedef std::shared_ptr<ArrayNode> ArrayNodePtr;

}

}

}
