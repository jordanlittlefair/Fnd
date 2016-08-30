#include "DocumentTreeArray.hpp"

using namespace Fnd::Utility::DocumentTree;

Array::Array(const std::vector<NodePtr>& elements):
	_elements(elements)
{
	
}

const std::vector<NodePtr>& Array::GetElements() const
{
	return _elements;
}

void Array::AddElement(const NodePtr& element)
{
	_elements.push_back(element);
}

INode::Type Array::GetElementType(const unsigned int index) const
{
	return _elements[index]->GetType();
}

NodePtr Array::GetElement(const unsigned int index) const
{
	return _elements[index];
}
