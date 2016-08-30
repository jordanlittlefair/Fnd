#include "DocumentTreeObject.hpp"

using namespace Fnd::Utility::DocumentTree;

Object::Object(const std::vector<NodePtr>& children):
	_children(children)
{
}

const std::vector<NodePtr>& Object::GetChildren() const
{
	return _children;
}

void Object::AddChild(const NodePtr& child)
{
	_children.push_back(child);
}

bool Object::HasChild(const std::string& name) const
{
	for (const auto& child : _children)
	{
		if (child->GetName() == name)
		{
			return true;
		}
	}
	
	return false;;
}

INode::Type Object::GetChildType(const std::string& name) const
{
	for (const auto& child : _children)
	{
		if (child->GetName() == name)
		{
			return child->GetType();
		}
	}
	
	throw std::runtime_error("Can't find child");
}

NodePtr Object::GetChild(const std::string& name) const
{
	for (const auto& child : _children)
	{
		if (child->GetName() == name)
		{
			return child;
		}
	}
	
	throw std::runtime_error("Can't find child");
}
