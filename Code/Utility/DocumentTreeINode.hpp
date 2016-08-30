#pragma once

#include <memory>
#include <string>

namespace Fnd
{

namespace Utility
{

namespace DocumentTree
{

/*
	Interface inherited by nodes - exposes the name and type of the node
*/
class INode
{
public:
	
	enum class Type
	{
		String,
		Integer,
		Float,
		Object,
		Array
	};
	
	virtual std::string GetName() const = 0;
	
	virtual Type GetType() const = 0;
	
	virtual ~INode() {}
};
	
typedef std::shared_ptr<INode> NodePtr;
	
}
	
}
	
}
