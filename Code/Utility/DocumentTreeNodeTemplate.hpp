#pragma once

#include "DocumentTreeINode.hpp"

namespace Fnd
{

namespace Utility
{

namespace DocumentTree
{

/*
	A template which takes a Type to store, and a NodeType to describe the node.
*/
template <INode::Type Type_T, typename DataType_T>
class DocumentTreeNodeTemplate:
	public INode
{
public:
	
	typedef DataType_T DataType;
	
	static const INode::Type NodeType = Type_T;
	
	DocumentTreeNodeTemplate(const std::string& name, const DataType& value = DataType()):
		_name(name),
		_value(value)
	{
	}
	
	std::string GetName() const
	{
		return _name;
	}
	
	Type GetType() const
	{
		return Type_T;
	}
	
	DataType GetValue() const
	{
		return _value;
	}
	
	DataType& GetValue()
	{
		return _value;
	}
	
	void SetValue(const DataType& value)
	{
		_value = value;
	}
	
private:
	
	const std::string _name;
	
	DataType _value;
};

}

}

}
