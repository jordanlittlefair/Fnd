#pragma once

#include "DocumentTreeINode.hpp"

#include <vector>

namespace Fnd
{

namespace Utility
{

namespace DocumentTree
{

/*
	An object to be stored in an object node. Stores a list of child nodes.
*/
class Object;
typedef std::shared_ptr<Object> ObjectPtr;

class Object
{
public:
	
	Object(const std::vector<NodePtr>& children = std::vector<NodePtr>());
	
	const std::vector<NodePtr>& GetChildren() const;
	
	void AddChild(const NodePtr& child);
	
	bool HasChild(const std::string& name) const;
	
	INode::Type GetChildType(const std::string& name) const;
	
	NodePtr GetChild(const std::string& name) const;
	
	template <typename NodeType_T>
	std::shared_ptr<NodeType_T> GetChildNode(const std::string& name) const
	{
		NodePtr node = GetChild(name);
		
		if (node->GetType() != NodeType_T::NodeType)
		{
			throw std::runtime_error("Wrong type!");
		}
		
		return std::static_pointer_cast<NodeType_T>(node);
	}
	
	template <typename NodeType_T>
	const typename NodeType_T::DataType& GetChildValue(const std::string& name) const
	{
		std::shared_ptr<NodeType_T> node = GetChildNode<NodeType_T>(name);
		
		if (node->GetType() != NodeType_T::NodeType)
		{
			throw std::runtime_error("Wrong type!");
		}
		
		return node->GetValue();
	}
	
private:
	
	std::vector<NodePtr> _children;
};
	
}

}

}
