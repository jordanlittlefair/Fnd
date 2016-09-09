#pragma once

#include "../../Code/Modules/IConfigProvider.hpp"

namespace Fnd
{

namespace Test
{

namespace Modules
{

class MockConfigProvider:
	public Fnd::Modules::IConfigProvider
{
public:
	
	std::string GetValue() const;
	
	void SetValue(const std::string& value);
	
	Utility::DocumentTree::ObjectNodePtr LoadConfigDocumentTree();
	
	void SaveConfigDocumentTree(const Utility::DocumentTree::ObjectNodePtr& document_tree);
	
private:
	
	std::string _value;
};

}

}

}
