#pragma once

#include "DocumentTreeINode.hpp"

#include <vector>

namespace Fnd
{

namespace Utility
{

namespace DocumentTree
{

class Array
{
public:
	
	Array(const std::vector<NodePtr>& elements = std::vector<NodePtr>());
	
	const std::vector<NodePtr>& GetElements() const;
	
	void AddElement(const NodePtr& element);
	
	INode::Type GetElementType(const unsigned int index) const;
	
	NodePtr GetElement(const unsigned int index) const;
	
	template <typename NodeType_T>
	std::shared_ptr<NodeType_T> GetElementNode(const unsigned int index) const
	{
		NodePtr node = GetElement(index);
		
		if (node->GetType() != NodeType_T::NodeType)
		{
			throw std::runtime_error("Wrong type!");
		}
		
		return std::static_pointer_cast<NodeType_T>(node);
	}
	
	template <typename NodeType_T>
	const typename NodeType_T::DataType& GetElementValue(const unsigned int index) const
	{
		std::shared_ptr<NodeType_T> node = GetElementNode<NodeType_T>(index);
		
		if (node->GetType() != NodeType_T::NodeType)
		{
			throw std::runtime_error("Wrong type!");
		}
		
		return node->GetValue();
	}

private:
	
	std::vector<NodePtr> _elements;
};
	
}

}

}