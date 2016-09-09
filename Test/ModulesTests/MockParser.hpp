#pragma once

#include "../../Code/Utility/IParser.hpp"

namespace Fnd
{

namespace Test
{

namespace Modules
{

class MockParser:
	public Fnd::Utility::IParser
{
public:
	
	// Takes a string and returns an object with a single string node containing the buffer.
	Utility::DocumentTree::ObjectNodePtr Parse(const Utility::Buffer& buffer) const;
	
	// Takes an object with a single string node and returns the node's value as a buffer.
	Utility::Buffer Serialise(const Utility::DocumentTree::ObjectNodePtr& document_tree) const;
	
	std::string GetDefaultFileExtension() const;
};

}

}

}
